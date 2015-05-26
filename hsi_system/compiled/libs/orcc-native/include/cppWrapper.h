#ifndef __CPPWRAPPER_H
#define __CPPWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HsiCppFunctions HsiCppFunctions;

HsiCppFunctions* newHsiCppFunctions();

void HsiCppFunctions_get_eigen(HsiCppFunctions* v,double* matrixIn, double* matrixU, int rows, int columns);

void HsiCppFunctions_leer_Imagen(HsiCppFunctions* v,double* matrixIn, int rows, int columns, char* fileName);
void HsiCppFunctions_escribir_Imagen(HsiCppFunctions* v,double* matrixOut, int rows, int columns, char* fileName);

void HsiCppFunctions_random_vector(HsiCppFunctions* v,double* vector, double positions);

void HsiCppFunctions_get_pinverse(HsiCppFunctions* v,double* matrixIn, double* matrixPinverse, int rows, int columns);
void HsiCppFunctions_get_inverse(HsiCppFunctions* v,double* matrixIn, double* matrixInverse, int rows, int columns);
void HsiCppFunctions_gen_data(HsiCppFunctions* v, int rows, int columns, int bands, int nbits, int nformat, int numPC, int numEnd);
void HsiCppFunctions_gen_hdr(HsiCppFunctions* v, int lines, int samples, int bands, int numEnd, char* path, char* fileName, int typeFile);

void deleteHsiCppFunctions(HsiCppFunctions* v);

#ifdef __cplusplus
}
#endif
#endif
