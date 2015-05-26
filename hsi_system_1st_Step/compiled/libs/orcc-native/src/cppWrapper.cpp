#include "HsiCppFunctions.h"
#include "cppWrapper.h"

extern "C" {
        HsiCppFunctions* newHsiCppFunctions() {
                return new HsiCppFunctions();
        }

	void HsiCppFunctions_get_eigen(HsiCppFunctions* v, double* matrixIn, double* matrixU, int rows, int columns){

		v->get_eigen(matrixIn, matrixU, rows, columns);

	}

	void HsiCppFunctions_leer_Imagen(HsiCppFunctions* v, double* matrixIn, int rows, int columns, char* fileName){

		v->read_Image(matrixIn,rows, columns, fileName);

	}

	void HsiCppFunctions_escribir_Imagen(HsiCppFunctions* v, double* matrixOut, int rows, int columns, char* fileName){

		v->write_Image(matrixOut,rows, columns, fileName);

	}

	void HsiCppFunctions_gen_data(HsiCppFunctions* v,int rows, int columns, int bands, int nbits, int nformat, int numPC, int numEnd){

		v->gen_data(rows,columns, bands, nbits, nformat, numPC, numEnd);

	}

	void HsiCppFunctions_gen_hdr(HsiCppFunctions* v,int lines, int samples, int bands, int numEnd, char* path, char* fileName, int typeFile){

		v->gen_hdr(lines, samples, bands, numEnd, path, fileName, typeFile);

	}

	void HsiCppFunctions_random_vector(HsiCppFunctions* v, double* vector, double positions){

		v->generate_random_vector(vector, positions);

	}

	void HsiCppFunctions_get_pinverse(HsiCppFunctions* v, double* matrixIn, double* matrixPinverse, int rows, int columns){

		v->get_pinverse(matrixIn, matrixPinverse, rows, columns);

	}

	void HsiCppFunctions_get_inverse(HsiCppFunctions* v, double* matrixIn, double* matrixInverse, int rows, int columns){

		v->get_inverse(matrixIn, matrixInverse, rows, columns);

	}


        void deleteHsiCppFunctions(HsiCppFunctions* v) {
                delete v;
        }
}
