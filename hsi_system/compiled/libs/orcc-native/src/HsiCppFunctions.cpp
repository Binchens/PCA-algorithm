#include <HsiCppFunctions.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>


void HsiCppFunctions::get_eigen(double* matrixIn, double* matrixU, int rows, int columns) {

	int i;
	int j;
	Matrix SubsetMatrix(rows,columns);
	Matrix U(rows,columns);

	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++){
			SubsetMatrix.put(i,j,matrixIn[i*columns+j]);	
		}
	}
	
	SVDType s(SubsetMatrix); 
	U = s.U();

	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++){
			matrixU[i*columns+j] = U.get(i,j);
		}
	}
}

void HsiCppFunctions::read_Image(double* matrixIn, int rows, int columns, char* fileName){


	int i;
	int j;

   	ifstream fs; 

	fs.open(fileName);
	for(i = 0; i<rows; i++){
		for(j = 0; j<columns; j++){
			 fs >> matrixIn[(i*columns) + j];
		}
	}
   	fs.close(); 
}

void HsiCppFunctions::write_Image(double* matrixOut, int rows, int columns, char* fileName){

	int i;
	int j;
	ofstream fs2;

	fs2.open(fileName);
	for(i = 0; i<rows; i++){
		for(j = 0; j<columns; j++){
			 fs2 << matrixOut[(i*columns) + j] << endl;
		}
	}
	fs2.close();	
}

void HsiCppFunctions::generate_random_vector(double* vector, double positions){


	vnl_random randomGenerator;
	randomGenerator = vnl_random();
	int i;
	for(i = 0; i<positions; i++){
		vector[i] = (randomGenerator.drand64());
	}
}

void HsiCppFunctions::get_pinverse(double* matrixIn, double* matrixPinverse, int rows, int columns) {

	int i;
	int j;
	Matrix SubsetMatrix(rows,columns);
	Matrix Pinverse(rows,columns);

	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++)
			SubsetMatrix.put(i,j,matrixIn[i*columns+j]);	
	}
	
	SVDType s(SubsetMatrix); 
	Pinverse = s.pinverse();

	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++){
			matrixPinverse[i*columns+j] = Pinverse.get(i,j);
		}
	}
}

void HsiCppFunctions::get_inverse(double* matrixIn, double* matrixInverse, int rows, int columns){
	
	int i;
	int j;
	Matrix SubsetMatrix(rows,columns);
	Matrix Inverse(rows,columns);

	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++)
			SubsetMatrix.put(i,j,matrixIn[i*columns+j]);	
	}
	
	SVDType s(SubsetMatrix); 
	Inverse = s.inverse();

	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++)
			matrixInverse[i*columns+j] = Inverse.get(i,j);
	}
}

void HsiCppFunctions::gen_data(int rows, int columns, int bands, int nbits, int nformat, int numPC, int numEnd){

	ofstream fs3;
	fs3.open("Data.cal");
	fs3 << "package hsi_analysis;" << endl;
	fs3 << " " << endl;
	fs3 << " " << endl;
	fs3 << "unit Data:" << endl;
	fs3 << " " << endl;
	fs3 << " " << endl;
	fs3 << "int(size=32) rows = " << rows << ";" << endl;
	fs3 << "int(size=32) columns = " << columns << ";" << endl;
	fs3 << "int(size=32) bands = " << bands << ";" << endl;
	fs3 << "int(size=32) nbits = " << nbits << ";" << endl;
	fs3 << "int(size=32) nformat = " << nformat << ";  //0 BSQ, 1 BIP, 2 BIL" << endl;
	fs3 << " " << endl;
	fs3 << "int(size=32) num_PC = " << numPC << ";" << endl;
	fs3 << "double num_Endmembers = " << numEnd << ";" << endl;
	fs3 << " " << endl;
	fs3 << "int(size=32) rc = rows*columns;" << endl;
	fs3 << "int(size=32) int_Endmembers = " << numEnd << ";" << endl;
	fs3 << " " << endl;	
	fs3 << " " << endl;
	fs3 << "end" << endl;

	fs3.close();	
}

void HsiCppFunctions::gen_hdr(int lines, int samples, int bands, int numEnd, char* path, char* fileName, int typeFile){
	
	int i;
  	char format[] = ".hdr";
	char *aux2 = fileName;
	char aux[strlen(aux2)+4];
	int length = strlen(fileName);

	for(i=0;i<strlen(aux2);i++)
		aux[i] = aux2[i];

	aux[length] = format[0];
	aux[length+1] = format[1];
	aux[length+2] = format[2];
	aux[length+3] = format[3];
	aux[length+4] = format[4];

	ofstream fs4;
	fs4.open(aux);
	if(typeFile == 1){		//DIMENSIONALITY REDUCTION
		fs4 << "ENVI" << endl;
		fs4 << "description = {" << endl;
		fs4 << path << "}" << endl;
		fs4 << "samples = " << samples << endl;
		fs4 << "lines   = " << lines << endl;
		fs4 << "bands   = " << bands << endl;
		fs4 << "header offset = 0" << endl;
		fs4 << "file type = ENVI Standard" << endl;
		fs4 << "data type = 5" << endl;
		fs4 << "interleave = bsq" << endl;
		fs4 << "byte order = 0" << endl;
		fs4 << "band names = {" << endl;
	
		for (i = 1; i < bands; i++){
			fs4 << "Band " << i << "," << endl;
		}
		fs4 << "Band " << bands << "}" << endl;
	}
	else if(typeFile == 2){	//ENDMEMBERS
		fs4 << "ENVI" << endl;
		fs4 << "description = {" << endl;
		fs4 << path << "}" << endl;
		fs4 << "samples = " << numEnd << endl;
		fs4 << "lines   = " << 1 << endl;
		fs4 << "bands   = " << bands << endl;
		fs4 << "header offset = 0" << endl;
		fs4 << "file type = ENVI Standard" << endl;
		fs4 << "data type = 5" << endl;
		fs4 << "interleave = bsq" << endl;
		fs4 << "byte order = 0" << endl;
		fs4 << "band names = {" << endl;
	
		for (i = 1; i < bands; i++){
			fs4 << "Band " << i << "," << endl;
		}
		fs4 << "Band " << bands << "}" << endl;
	}
	else if(typeFile == 3){	//ABUNDANCES
		fs4 << "ENVI" << endl;
		fs4 << "description = {" << endl;
		fs4 << path << "}" << endl;
		fs4 << "samples = " << samples << endl;
		fs4 << "lines   = " << lines << endl;
		fs4 << "bands   = " << numEnd << endl;
		fs4 << "header offset = 0" << endl;
		fs4 << "file type = ENVI Standard" << endl;
		fs4 << "data type = 5" << endl;
		fs4 << "interleave = bsq" << endl;
		fs4 << "byte order = 0" << endl;
		fs4 << "band names = {" << endl;
	
		for (i = 1; i < numEnd; i++){
			fs4 << "Band " << i << "," << endl;
		}
		fs4 << "Band " << numEnd << "}" << endl;
	}
	fs4.close();	
}

