
#ifdef __cplusplus

#include "itkImageRegionIterator.h"
#include <vnl/algo/vnl_qr.h>
#include <math.h>
#include <vnl/vnl_random.h>

#ifndef __HsiCppFunctions_H
#define __HsiCppFunctions_H

using namespace std;

typedef vnl_matrix<double> Matrix;
typedef vnl_vector<double> Vector;
typedef vnl_svd<double> SVDType;

class HsiCppFunctions {


                int m_i;

        public:
                void int_set(int i);

                int int_get();

		void get_eigen(double* matrixIn, double* matrixU, int rows, int columns);

		void read_Image(double* matrixIn, int rows, int columns, char* fileName);
		void write_Image(double* matrixOut, int rows, int columns, char* fileName);

		void generate_random_vector(double* vector, double positions);
			
		void get_pinverse(double* matrixIn, double* matrixPinverse, int rows, int columns);

		void get_inverse(double* matrixIn, double* matrixInverse, int rows, int columns);

		void gen_data(int rows, int columns, int bands, int nbits, int nformat, int numPC, int numEnd);

		void gen_hdr(int lines, int samples, int bands, int numEnd, char* path, char* fileName, int typeFile);
		
};

#endif
#endif
