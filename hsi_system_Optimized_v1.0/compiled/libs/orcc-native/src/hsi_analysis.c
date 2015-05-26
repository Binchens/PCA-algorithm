/**
 * Hyperspectral Imaging Algorithms Library
 *
 * @file
 * @brief Library of common functions to implement algorithms for analyzing hyperspectral images
 * 
 * @author Raquel Lazcano
 * @author Daniel Madroñal
 * @version 1.0
 * @date July 2014
 */

#include <assert.h>
#if (!defined(NO_DLFCN) && !defined(_BGL) && !defined(_BGP))
#include <dlfcn.h>
#endif
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#if !defined(__FreeBSD__) && !defined(__APPLE__)
#include <malloc.h>
#endif
#include <math.h>
#include <memory.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include "cppWrapper.h"


/**
* @brief Cast between float and double types
* @param value double value
* @return The same value, but as a float
*/
float double_to_float(double value) {
	
	return (float) value;
}

/**
* @brief Cast between int and double types
* @param value double value
* @return The same value, but as an int
*/
int double_to_int(double value) {
	
	return (int) value;
}

/**
* @brief Raise a number to a given power
* @param base Number we want to raise to a certain power
* @param power Power 
* @return Result
*/
double elev(double base, double power) {
	
	return pow (base, power);	
}

/**
* @brief Finish program execution
*/
void end_program(){
	exit(0);
}

/**
* @brief Cast between float and double types
* @param value float value
* @return The same value, but as a double
*/
double float_to_double(float value) {
	
	return (double) value;
}

/**
* @brief Generate the Data.cal file. This function is only used to generate the output of algorithms related to endmember estimation
* @param rows Number of rows of the original hyperspectral image
* @param columns Number of columns of the original hyperspectral image
* @param bands Number of bands of the original hyperspectral image
* @param nbits Number of bits of each pixel
* @param nformat Number to select the format: 0 - BSQ, 1 - BIP, 2 - BIL
* @param numPC Number of principal components (PCA algorithm)
* @param numEnd Number of endmembers 
*/
void gen_conf_data(int rows, int columns, int bands, int nbits, int nformat, int numPC, int numEnd){

	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_gen_data(c, rows, columns,  bands,  nbits,  nformat,  numPC,  numEnd);
        deleteHsiCppFunctions(c);
}

/**
* @brief Generate a complete hyperspectral image, which has two files: a binary file and a .hdr file. The last one is the header of the binary file, and it must have the same name, but with the .hdr extension. The file is written (row by row) in the bin directory of the project. The format of the analyzed hyperspectral images is supposed to be BSQ.
* @param matrixOut Image to save in the binary file
* @param rows Number of rows of matrixOut
* @param columns Number of columns of matrixOut
* @param lines Number of lines of the initial image
* @param samples Number of samples of the initial image
* @param bands Number of bands of the output hyperspectral image
* @param numEnd Number of endmembers of the output hyperspectral image
* @param path Path to the hyperspectral image associated with the .hdr generated
* @param fileName Name of the binary file (without the extension) 
* @param typeFile Number to select the file we want to generate: 1 - Dimensionality reduction, 2 - Endmembers, 3 - Abundances
*/
void gen_hdr(double* matrixOut, int rows, int columns, int lines, int samples, int bands, int numEnd, char* path, char* fileName, int typeFile){
	
	FILE *fp;	
	int i = 0;	
	int j = 0;
	int num_written; 

	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_gen_hdr(c, lines, samples, bands, numEnd, path, fileName, typeFile);
        deleteHsiCppFunctions(c);

	fp = fopen( fileName , "w" );
	num_written = fwrite (matrixOut, 8, rows*columns, fp);
	//printf("%d",num_written);
	//printf("\n");
   	fclose(fp);

}

/**
* @brief Get the diagonal vector of a matrix
* @param matrix Matrix whose diagonal we want to obtain (it has to be a square matrix)
* @param vectorDiag Diagonal vector (result)
* @param positions Number of rows or columns of matrix
*/
void get_diagonal(double *matrix, double *vectorDiag, int positions){

	int i;

	for (i = 0; i < positions; i++){
		vectorDiag[i] = matrix[i*positions + i];
	}
}

/**
* @brief Get the eigenvectors matrix 
* @param matrixIn Matrix whose eigenvectors we want to obtain (it has to be a square matrix)
* @param matrixEigenvectors Eigenvectors matrix (result)
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
*/
void get_eigenvectMatrix(double *matrixIn, double *matrixEigenvectors, int rows, int columns){

	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_get_eigen(c, matrixIn, matrixEigenvectors, rows, columns);
        deleteHsiCppFunctions(c);
}

/**
* @brief Get the inverse matrix 
* @param matrixIn Matrix whose inverse we want to obtain (it has to be a square matrix)
* @param matrix_inverse Inverse matrix (result)
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
*/
void get_inverse(double *matrixIn, double *matrix_inverse, int rows, int columns){

	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_get_inverse(c, matrixIn, matrix_inverse, rows, columns);
        deleteHsiCppFunctions(c);
}

/**
* @brief Get a pseudo - inverse matrix 
* @param matrixIn Matrix whose pseudo - inverse we want to obtain (it has to be a square matrix)
* @param matrix_p_inverse Pseudo - inverse matrix (result)
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
*/
void get_pinverse(double *matrixIn, double *matrix_p_inverse, int rows, int columns){

	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_get_pinverse(c, matrixIn, matrix_p_inverse, rows, columns);
        deleteHsiCppFunctions(c);
}

/**
* @brief Get the real time of the system (in seconds, with a resolution of nanoseconds)
* @return System time
*/
double get_time(){
	struct timespec t1;
	clock_gettime(CLOCK_MONOTONIC,  &t1);
	return (t1.tv_sec + (double) t1.tv_nsec*1e-9);
}

/**
* @brief Get the position of the largest element vector (absolute values only)
* @param vector Vector to use in the operation
* @param positions Number of elements of vector
* @return Returns the position (index) of the largest element vector
*/
int getIndexMax(double* vector, int positions) {
	
	double max = 0;
	unsigned int index = 0;
	double absValue;
	int i;
	
	for (i = 0; i < positions; i++)
	{
		absValue = abs(vector[i]);
		if (absValue > max)
		{
			max = absValue;
			index = i;
		}
	}
//	printf("Indice: %d\n",index);
	return index;
}

/**
* @brief Cast between int and double types
* @param value int value
* @return The same value, but as a double
*/
double int_to_double(int value) {
	
	return (double) value;
}

/**
* @brief Get the logarithm of a number (base 10): result = log(value)
* @param value Number whose logarithm we want to calculate
* @return Result
*/
double log(double value){

	return log10(value);
}

/**
* @brief Extend a matrix
* @param matrix1 Matrix whose dimensions we want to extend 
* @param matrix2 Extended matrix (result)
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param rows2 Number of rows of matrix2
* @param columns2 Number of columns of matrix2
*/
void matrix_extend(double *matrix1, double *matrix2, double rows1, double columns1, double rows2, double columns2) {
	
	int i;	
	int j;

	for (i = 0; i<rows1; i++){
		for(j = 0; j<columns1; j++){
			matrix2[(i*(int)columns2) + j] = matrix1[(i*(int)columns1) + j];
		}
	}
}

/**
* @brief Set each element of a column of the input matrix to the same value
* @param matrix1 Matrix whose column we want to fill
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Position of the filled column
* @param value Value of each element of the filled column
*/
void matrix_fill_column(double *matrix1, double rows1, double columns1, double column, double value) {
	
	int i;	
	for (i = 0; i<rows1; i++){
		matrix1[(i*(int)columns1) + (int)column] = value;
	}
}

/**
* @brief Get a certain column from a matrix
* @param matrix1 Matrix whose column we want to obtain
* @param vector Vector where the required column is saved
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Pointer to the required column
*/
void matrix_get_column(double *matrix1, double* vector, double rows1, double columns1, double column) {
	
	int i;	
	for (i = 0; i<rows1; i++){
		vector[i] = matrix1[(i*(int)columns1) + (int)column];
	}
}

				// New function for float
/**
* @brief Get a certain column from a matrix
* @param matrix1 Matrix whose column we want to obtain
* @param vector Vector where the required column is saved
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Pointer to the required column
*/

void matrix_get_column_float(float *matrix1, float* vector, int rows1, int columns1, int column) {
	
	int i;	
	for (i = 0; i<rows1; i++){
		vector[i] = matrix1[(i*columns1) + column];
	}
}

/**
* @brief Get a certain row from a matrix
* @param matrix1 Matrix whose row we want to obtain
* @param vector Vector where the required row is saved
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Pointer to the required row
*/
void matrix_get_row(double *matrix1, double* vector, int rows1, int columns1, int row) {
	
	int i;	
	for (i = 0; i<columns1; i++){
		vector[i] = matrix1[row*columns1 + i];
	}
}

/**
* @brief Deduct two matrices
* @param matrix1 Minuend
* @param matrix2 Subtrahend
* @param matrixOut Matrix where the result is saved
* @param rows Number of rows of matrix1 and matrix2
* @param columns Number of columns of matrix1 and matrix2
*/
void matrix_minus_matrix(double *matrix1, double *matrix2, double *matrixOut, int rows, int columns) {

	int i = 0;	
	for (i = 0; i<rows*columns; i++){
		matrixOut[i] = matrix1[i] - matrix2[i];
	}	
}

/**
* @brief Deduct the same value to all the elements of a matrix
* @param matrixIn Matrix whose elements we want to edit
* @param matrixOut Matrix where the result is saved
* @param value Value to deduct
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
*/
void matrix_minus_value(double *matrixIn, double *matrixOut, double value, int rows, int columns) {

	int i = 0;	
	for (i = 0; i<rows*columns; i++){
		matrixOut[i] = matrixIn[i] - value;
	}	
}

/**
* @brief Multiply two matrices
* @param matrix1 First factor
* @param matrix2 Second factor
* @param matrixResult Product
* @param rows1 Number of rows of first factor
* @param columns1 Number of columns of first factor
* @param rows2 Number of rows of second factor
* @param columns2 Number of columns of second factor
*/
void matrix_mult(double *matrix1, double *matrix2, double *matrixResult, double rows1, double columns1, double rows2, double columns2) {
	
	int i;	
	int j;
	int k;
	double aux;

	for (i = 0; i<rows1; i++){
		for (j = 0; j<columns2; j++){
			aux = 0;
			for(k = 0; k<columns1; k++){
				aux = aux + matrix1[i*(int)columns1 + k] * matrix2[k*(int)columns2 + j];
			}			
			matrixResult[(int)columns2*i + j] = aux;
		}
	}
}

/**
* @brief Multiply a matrix by a vector (the result is a vector)
* @param matrix1 First factor
* @param vector Second factor
* @param vectorResult Product
* @param rows1 Number of rows of first factor
* @param columns1 Number of columns of first factor
* @param positions_vector Number of elements of second factor
*/
void matrix_mult_vector(double *matrix1, double *vector, double *vectorResult, double rows1, double columns1, double positions_vector) {
	
	int i;	
	int j;
	double aux;

	for (i = 0; i<rows1; i++){
		aux = 0;
		for(j = 0; j<columns1; j++){
			aux = aux + (matrix1[i*(int)columns1 + j] * vector[j]);
		}
		vectorResult[i] = aux;		
	}
}

/**
* @brief Add two matrices
* @param matrix1 First operand
* @param matrix2 Second operand
* @param matrixOut Matrix where the result is saved
* @param rows Number of rows of matrix1 and matrix2
* @param columns Number of columns of matrix1 and matrix2
*/
void matrix_plus_matrix(double *matrix1, double *matrix2, double *matrixOut, int rows, int columns) {

	int i = 0;	
	for (i = 0; i<rows*columns; i++){
		matrixOut[i] = matrix1[i] + matrix2[i];
	}	
}

/**
* @brief Add the same value to all the elements of a matrix
* @param matrixIn Matrix whose elements we want to edit
* @param matrixOut Matrix where the result is saved
* @param value Value to add
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
*/
void matrix_plus_value(double *matrixIn, double *matrixOut, double value, int rows, int columns) {

	int i = 0;	
	for (i = 0; i<rows*columns; i++){
		matrixOut[i] = matrixIn[i] + value;
	}	
}

/**
* @brief Reduce matrix dimensions
* @param matrix1 Matrix whose dimensions we want to reduce 
* @param matrix2 Reduced matrix (result)
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param rows2 Number of rows of matrix2
* @param columns2 Number of columns of matrix2
*/	
void matrix_reduce(double *matrix1, double *matrix2, double rows1, double columns1, double rows2, double columns2) {
	
	int i;	
	int j;

	for (i = 0; i<rows2; i++){
		for(j = 0; j<columns2; j++){
			matrix2[(i*(int)columns2) + j] = matrix1[(i*(int)columns1) + j];
		}
	}
}

/**
* @brief Divide each element of a matrix by the same value
* @param matrixIn Each element of this matrix is the dividend of each operation
* @param matrixOut Result of the division
* @param value Divider of each operation
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
*/
void matrix_scale(double *matrixIn, double *matrixOut, double value, int rows, int columns) {

	int i = 0;	
	for (i = 0; i<rows*columns; i++){
		matrixOut[i] = matrixIn[i] / value;
	}	
}

/**
* @brief Set a certain column of a matrix
* @param matrix1 Matrix whose column we want to modify
* @param vector Contains the new values of the column we want to edit
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Pointer to the column we want to edit
*/
void matrix_set_column(double *matrix1, double* vector, double rows1, double columns1, double column) {
	
	int i;	
	for (i = 0; i<rows1; i++){
		matrix1[(i*(int)columns1) + (int)column] = vector[i];
	}
}

					// New function for float

/**
* @brief Set a certain column of a matrix
* @param matrix1 Matrix whose column we want to modify
* @param vector Contains the new values of the column we want to edit
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Pointer to the column we want to edit
*/

void matrix_set_column_float(float *matrix1, float* vector, int rows1, int columns1, int column) {
	
	int i;	
	for (i = 0; i<rows1; i++){
		matrix1[(i*columns1) + column] = vector[i];
	}
}

/**
* @brief Set a certain row of a matrix
* @param matrix1 Matrix whose row we want to modify
* @param vector Contains the new values of the row we want to edit
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Pointer to the row we want to edit
*/
void matrix_set_row(double *matrix1, double* vector, double rows1, double columns1, double row) {
	
	int i;	
	for (i = 0; i<columns1; i++){
		matrix1[(int)row*(int)columns1 + i] = vector[i];
	}
}

					// New function for float

/**
* @brief Set a certain row of a matrix
* @param matrix1 Matrix whose row we want to modify
* @param vector Contains the new values of the row we want to edit
* @param rows1 Number of rows of matrix1
* @param columns1 Number of columns of matrix1
* @param column Pointer to the row we want to edit
*/
void matrix_set_row_float(float *matrix1, float* vector, int rows1, int columns1, int row) {
	
	int i;	
	for (i = 0; i<columns1; i++){
		matrix1[(row*columns1) + i] = vector[i];
	}
}

/**
* @brief Square each element of each row and add them, row by row
* @param matrix Matrix to use in the operation
* @param rows Number of rows of matrix
* @param columns Number of columns of matrix
* @return The function returns the square root of the largest row sum of squares
*/
double maxSqrtSum(double* matrix, double rows, double columns) {
	
	double resultado = 0;
	double aux;
	int i,j;
	for (i=0; i < rows; i++){
		aux = 0;
		for (j=0; j < columns; j++){
			aux = aux + elev(matrix[i*(int)columns + j],2);
		}
		if(aux > resultado)
			resultado = aux;
	}
	return elev(resultado, 0.5);
}

/**
* @brief Get the mean value of a given vector
* @param vector Vector whose mean value we want to obtain
* @param positions Size of vector
* @return Mean Value
*/
double mean_vector(double *vector, int positions){

	double sum = 0;
	int i;

	for (i = 0; i < positions; i++){
		sum = sum + vector[i];	
	}
	return (sum/positions);
}

					// New function for float

/**
* @brief Get the mean value of a given vector
* @param vector Vector whose mean value we want to obtain
* @param positions Size of vector
* @return Mean Value
*/
float mean_vector_float(float *vector, int positions){

	float sum = 0;
	int i;

	for (i = 0; i < positions; i++){
		sum = sum + vector[i];	
	}
	return (sum/positions);
}

/**
* @brief Modify analysis chain configuration parameters
* @param num_PC Number of principal components we want to obtain
* @param num_Endmembers Number of endmembers we want to obtain
* @param pathIn Path to the generated code of the HSI analysis chain
* @param var1 Name of the first variable we want to modify (number of principal components)
* @param var2 Name of the second variable we want to modify (number of endmembers)
*/
void modify_config(int num_PC, int num_Endmembers, char* pathIn, char* var1, char* var2){
	struct dirent *pDirent;
    	DIR *pDir;
	char *path = malloc(strlen(pathIn));
	strcpy(path,pathIn);
    	int success = 0;
    	char* nombreFichero;
	char * aux3 = "temporalFile";
    	char * path_to_file_src;
    	char * path_to_file_exit;
    	char * path_to_src = malloc(strlen(path)+strlen("/src"));
	char *e;
	int isc;

	int done1 = 0;
	int done2 = 0;
	char *line = malloc(sizeof(char)*200);
	char *line2 = malloc(sizeof(char)*200);
	char *e2;
	size_t len;
        ssize_t read;
	char aux1[4];
	int i;
	int contador;
	int copia;
	int fin;
	FILE* fDir;
	FILE* fDir2;
	char *num_PC_line = malloc(strlen("#define ")+strlen(var1)+strlen(aux1));
	strcpy(num_PC_line,"#define ");
	strcat(num_PC_line,var1);
	strcat(num_PC_line," ");
	sprintf(aux1,"%d",num_PC);
	strcat(num_PC_line,aux1);
	strcat(num_PC_line,"\n");

	char *num_Endmembers_line = malloc(strlen("#define ")+strlen(var2)+strlen(aux1));
	strcpy(num_Endmembers_line,"#define ");
	strcat(num_Endmembers_line,var2);
	strcat(num_Endmembers_line," ");
	sprintf(aux1,"%d",num_Endmembers);
	strcat(num_Endmembers_line,aux1);
	strcat(num_Endmembers_line,"\n");

    	strcpy(path_to_src, path);
    	strcat(path_to_src,"/src/");
    	pDir = opendir (path_to_src);
    	if (pDir == NULL) {
        	printf ("Cannot open directory '%s'\n", path_to_src);	
		exit(0);
    	}
    	pDirent = readdir(pDir);
       	do{ 
    		nombreFichero = pDirent->d_name;
		e = strrchr(nombreFichero, '.');
		if(e == NULL)
			isc = 0;
		else{
	    		if (strcmp(e,".c") == 0){
    				isc = 1;
    			}
    			else{
    				isc= 0;
    			}
		}
        	if(isc == 1) {
        		success = 1;
			done1 = 0;
			done2 = 0;
    			path_to_file_src = malloc(strlen(path_to_src)+strlen(nombreFichero)-1);
    			strcpy(path_to_file_src, path_to_src);
    			strcat(path_to_file_src, nombreFichero);
    			path_to_file_exit = malloc(strlen(path_to_file_src)+strlen(aux3)-1);	
    			strcpy(path_to_file_exit, path_to_file_src);
    			strcat(path_to_file_exit, aux3);
			
			fDir = fopen(path_to_file_src,"r+");
			fDir2 = fopen(path_to_file_exit,"w");

			while ((read = getline(&line, &len, fDir)) != -1) {
				contador = 0;
				copia = 0;
				fin = 0;
				for(i=0;i<strlen(line);i++){
					if(copia == 1){
						line2[i+contador] = line[i];
					}
					if(line[i] == '%'){
						if(contador==0)
							strcpy(line2,line);
						contador++;
						copia = 1;
						line2[i+contador] = '%';				
					}
				}
				if(copia == 1){
					for(i=0;i<(strlen(line)+contador);i++){
						if(fin == 0)
							line[i] = line2[i];
						else
							line[i] = NULL;
						if(line[i] == '\n')
							fin = 1;
						}
				}
    				e2 = strstr(line, var1); 
				fprintf(fDir2,line);
    				if((e2 != NULL) && done1 == 0){
					done1 = 1;
					fseek(fDir2, 0-strlen(line), SEEK_CUR);
					fprintf(fDir2,num_PC_line);
    				}
    				e2 = strstr(line, var2); 
    				if((e2 != NULL) && done2 == 0){
					done2 = 1;
					fseek(fDir2, 0-strlen(line), SEEK_CUR);
					fprintf(fDir2,num_Endmembers_line);
    				}
			}	
			fclose(fDir);
			fclose(fDir2);
			remove(path_to_file_src);
			rename(path_to_file_exit,path_to_file_src);

        	}
        	pDirent = readdir(pDir);
    	}while (pDirent != NULL);
    	closedir (pDir);
}

/**
* @brief Fill a vector with random values between 0 and 1 (of double type)
* @param vector Vector filled with random values
* @param positions Number of elements of vector 
*/	
void random_vector(double* vector, double positions){
	
	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_random_vector(c, vector, positions);
        deleteHsiCppFunctions(c);
}

/**
* @brief Read a .txt file (row by row) and save its contents in a matrix. Hence, the .txt file should contain only a matrix, and it should be located in the folder where the executable file is generated
* @param matrixIn Matrix where the result is going to be saved
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
* @param fileName Name of the required .txt file. The extension must also be written in this parameter 
*/
void read_txt(double* matrixIn, int rows, int columns, char* fileName){
	
	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_leer_Imagen(c, matrixIn, rows, columns, fileName);
        deleteHsiCppFunctions(c);
}

/**
* @brief Return the remainder of a division 
* @param dividend Dividend of the division
* @param divisor Divisor of the division
* @return Remainder of the division
*/
int rem(double dividend, int divisor) {

	return ((int) dividend % divisor);
}

/**
* @brief Get the square root of a number
* @param value Radicand
* @return Result
*/
double sq_root(double value) {
	
	return sqrt(value);
}

/**
* @brief Transpose a matrix
* @param matrixIn Matrix whose transpose we want to obtain
* @param matrixTranspose Matrix where the result is saved
* @param rows Number of rows of matrixIn
* @param columns Number of columns of matrixIn
*/
void transpose(double *matrixIn, double *matrixTranspose, double rows, double columns) {
	int i = 0;	
	int j = 0;	
	
	for (i = 0; i<rows; i++){
		for (j = 0; j<columns; j++){
			matrixTranspose[i+j*(int)rows] = matrixIn[i*(int)columns+j];
		}
	}
}

/**
* @brief Subtract the same value from each position of a vector
* @param vectorIn Each position is the minuend of each subtraction
* @param value Common subtrahend of each subtraction
* @param vectorMinus Vector where the result is saved
* @param positions Size of vectorIn
*/
void vector_minus_value(double *vectorIn, double value, double *vectorMinus, int positions) {
	
	int i;

	for (i = 0; i<positions; i++){
		vectorMinus[i] = vectorIn[i] - value;
	}
}

					// New function for float

/**
* @brief Subtract the same value from each position of a vector
* @param vectorIn Each position is the minuend of each subtraction
* @param value Common subtrahend of each subtraction
* @param vectorMinus Vector where the result is saved
* @param positions Size of vectorIn
*/
void vector_minus_value_float(float *vectorIn, float value, float *vectorMinus, int positions) {
	
	int i;

	for (i = 0; i<positions; i++){
		vectorMinus[i] = vectorIn[i] - value;
	}
}

/**
* @brief Subtract one vector from another
* @param vector1 Minuend vector
* @param vector2 Subtrahend vector
* @param vectorResult Vector where the result is saved
* @param positions Size of vector1 and vector2 (they must have the same number of elements)
*/
void vector_minus_vector(double *vector1, double *vector2, double *vectorResult, int positions) {
	
	int i;
	for (i = 0; i<positions; i++){
		vectorResult[i] = vector1[i] - vector2[i];
	}
}

					// New function for float

/**
* @brief Subtract one vector from another
* @param vector1 Minuend vector
* @param vector2 Subtrahend vector
* @param vectorResult Vector where the result is saved
* @param positions Size of vector1 and vector2 (they must have the same number of elements)
*/
void vector_minus_vector_float(float *vector1, float *vector2, float *vectorResult, int positions) {
	
	int i;
	for (i = 0; i<positions; i++){
		vectorResult[i] = vector1[i] - vector2[i];
	}
}

/**
* @brief Multiply two vectors
* @param vector1 First factor
* @param vector2 Second factor
* @param positions Number of elements of each vector
* @return Product
*/
double vector_mult(double *vector1, double *vector2, int positions){

	double mult = 0;
	int i;
	
	for (i = 0; i < positions; i++){
		mult = mult + (vector1[i]*vector2[i]);
		}
	return mult;
}

/**
* @brief Multiply a matrix by a vector
* @param vector First factor
* @param matrix Second factor
* @param vectorResult Vector where the result is saved
* @param positions_vector Number of elements of vector
* @param rows1 Number of rows of matrix
* @param columns1 Number of columns of matrix
*/
void vector_mult_matrix(double *vector, double *matrix, double *vectorResult, double positions_vector, double rows1, double columns1) {
	
	int i;	
	int j;
	double aux;

	for (i = 0; i<columns1; i++){
		aux = 0;
		for(j = 0; j<positions_vector; j++){
			aux = aux + (matrix[j*(int)columns1 + i] * vector[j]);

		}
		vectorResult[i] = aux;		
	}
}

/**
* @brief Divide each element of a vector by the same value
* @param vectorIn Each element of this vector is the dividend of each operation
* @param vectorOut Result of the division
* @param value Divider of each operation
* @param positions Number of elements of vectorIn
*/
void vector_scale(double *vectorIn, double *vectorOut, double value, int positions) {
	int i = 0;	
	for (i = 0; i<positions; i++){
		vectorOut[i] = vectorIn[i] / value;
	}	
}

/**
* @brief Write an image into a binary file (row by row). This function must be used to write images implemented with double type of data
* @param matrixOut Image to save in the binary file
* @param rows Number of rows of matrixOut
* @param columns Number of columns of matrixOut
* @param fileName Name of the generated file
*/
void write_double_binary(double* matrixOut, int rows, int columns, char* fileName){

	FILE *fp;	
	int i = 0;	
	int j = 0;
	int num_written; 
	
	fp = fopen( fileName , "w" );
	num_written = fwrite (matrixOut, 8, rows*columns, fp);
	//printf("%d",num_written);
	//printf("\n");
   	fclose(fp);
  
}

/**
* @brief Write an image into a binary file (row by row). This function must be used to write images implemented with short int type of data. 
* @param matrixOut Image to save in the binary file
* @param rows Number of rows of matrixOut
* @param columns Number of columns of matrixOut
* @param fileName Name of the generated file
*/
void write_short_binary(short int* matrixOut, int rows, int columns, char* fileName){

	FILE *fp;
	int i;

   	//fp = fopen( "binary_file_test_bip" , "w" );
	fp = fopen(fileName, "w" );
	//printf("\n");

	fwrite (matrixOut, 2, rows*columns, fp);
   	fclose(fp);
  
}

/**
* @brief Save a matrix into a .txt file (row by row). This file is generated in the bin folder of the project

* @param matrixOut Matrix to be saved in the .txt file
* @param rows Number of rows of matrixOut
* @param columns Number of columns of matrixOut
* @param fileName Name of the output .txt file. The extension must also be written in this parameter
*/	
void write_txt(double* matrixOut, int rows, int columns,char* fileName){
	
	struct HsiCppFunctions* c = newHsiCppFunctions();
	HsiCppFunctions_escribir_Imagen(c, matrixOut, rows, columns,fileName);
        deleteHsiCppFunctions(c);
}

