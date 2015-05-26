// Source file is "L/hsi_system_1st_Step/src/Matrix_Constructor.cal"

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#include "types.h"
#include "fifo.h"
#include "util.h"
#include "scheduler.h"
#include "dataflow.h"
#include "cycle.h"

#define SIZE 2048

////////////////////////////////////////////////////////////////////////////////
// Instance
extern actor_t Constructor_PCA;

////////////////////////////////////////////////////////////////////////////////
// Input FIFOs
extern fifo_float_t *Constructor_PCA_Constructor_in0;
extern fifo_i32_t *Constructor_PCA_Sec_Pointer0;
extern fifo_float_t *Constructor_PCA_Constructor_in1;
extern fifo_i32_t *Constructor_PCA_Sec_Pointer1;
extern fifo_float_t *Constructor_PCA_Constructor_in2;
extern fifo_i32_t *Constructor_PCA_Sec_Pointer2;
extern fifo_float_t *Constructor_PCA_Constructor_in3;
extern fifo_i32_t *Constructor_PCA_Sec_Pointer3;
extern fifo_float_t *Constructor_PCA_PCA_in;
extern fifo_i32_t *Constructor_PCA_EOF;

////////////////////////////////////////////////////////////////////////////////
// Input Fifo control variables
static unsigned int index_Constructor_in0;
static unsigned int numTokens_Constructor_in0;
#define SIZE_Constructor_in0 SIZE
#define tokens_Constructor_in0 Constructor_PCA_Constructor_in0->contents

extern connection_t connection_Constructor_PCA_Constructor_in0;
#define rate_Constructor_in0 connection_Constructor_PCA_Constructor_in0.rate

static unsigned int index_Sec_Pointer0;
static unsigned int numTokens_Sec_Pointer0;
#define SIZE_Sec_Pointer0 SIZE
#define tokens_Sec_Pointer0 Constructor_PCA_Sec_Pointer0->contents

extern connection_t connection_Constructor_PCA_Sec_Pointer0;
#define rate_Sec_Pointer0 connection_Constructor_PCA_Sec_Pointer0.rate

static unsigned int index_Constructor_in1;
static unsigned int numTokens_Constructor_in1;
#define SIZE_Constructor_in1 SIZE
#define tokens_Constructor_in1 Constructor_PCA_Constructor_in1->contents

extern connection_t connection_Constructor_PCA_Constructor_in1;
#define rate_Constructor_in1 connection_Constructor_PCA_Constructor_in1.rate

static unsigned int index_Sec_Pointer1;
static unsigned int numTokens_Sec_Pointer1;
#define SIZE_Sec_Pointer1 SIZE
#define tokens_Sec_Pointer1 Constructor_PCA_Sec_Pointer1->contents

extern connection_t connection_Constructor_PCA_Sec_Pointer1;
#define rate_Sec_Pointer1 connection_Constructor_PCA_Sec_Pointer1.rate

static unsigned int index_Constructor_in2;
static unsigned int numTokens_Constructor_in2;
#define SIZE_Constructor_in2 SIZE
#define tokens_Constructor_in2 Constructor_PCA_Constructor_in2->contents

extern connection_t connection_Constructor_PCA_Constructor_in2;
#define rate_Constructor_in2 connection_Constructor_PCA_Constructor_in2.rate

static unsigned int index_Sec_Pointer2;
static unsigned int numTokens_Sec_Pointer2;
#define SIZE_Sec_Pointer2 SIZE
#define tokens_Sec_Pointer2 Constructor_PCA_Sec_Pointer2->contents

extern connection_t connection_Constructor_PCA_Sec_Pointer2;
#define rate_Sec_Pointer2 connection_Constructor_PCA_Sec_Pointer2.rate

static unsigned int index_Constructor_in3;
static unsigned int numTokens_Constructor_in3;
#define SIZE_Constructor_in3 SIZE
#define tokens_Constructor_in3 Constructor_PCA_Constructor_in3->contents

extern connection_t connection_Constructor_PCA_Constructor_in3;
#define rate_Constructor_in3 connection_Constructor_PCA_Constructor_in3.rate

static unsigned int index_Sec_Pointer3;
static unsigned int numTokens_Sec_Pointer3;
#define SIZE_Sec_Pointer3 SIZE
#define tokens_Sec_Pointer3 Constructor_PCA_Sec_Pointer3->contents

extern connection_t connection_Constructor_PCA_Sec_Pointer3;
#define rate_Sec_Pointer3 connection_Constructor_PCA_Sec_Pointer3.rate

static unsigned int index_PCA_in;
static unsigned int numTokens_PCA_in;
#define SIZE_PCA_in SIZE
#define tokens_PCA_in Constructor_PCA_PCA_in->contents

extern connection_t connection_Constructor_PCA_PCA_in;
#define rate_PCA_in connection_Constructor_PCA_PCA_in.rate

static unsigned int index_EOF;
static unsigned int numTokens_EOF;
#define SIZE_EOF SIZE
#define tokens_EOF Constructor_PCA_EOF->contents

extern connection_t connection_Constructor_PCA_EOF;
#define rate_EOF connection_Constructor_PCA_EOF.rate

////////////////////////////////////////////////////////////////////////////////
// Predecessors
extern actor_t Secondary_PCA_0;
extern actor_t Secondary_PCA_0;
extern actor_t Secondary_PCA_1;
extern actor_t Secondary_PCA_1;
extern actor_t Secondary_PCA_2;
extern actor_t Secondary_PCA_2;
extern actor_t Secondary_PCA_3;
extern actor_t Secondary_PCA_3;
extern actor_t Source;
extern actor_t Source;

////////////////////////////////////////////////////////////////////////////////
// Output FIFOs
extern fifo_float_t *Constructor_PCA_PCA_Constructor_out;

////////////////////////////////////////////////////////////////////////////////
// Output Fifo control variables
static unsigned int index_PCA_Constructor_out;
static unsigned int numFree_PCA_Constructor_out;
#define NUM_READERS_PCA_Constructor_out 2
#define SIZE_PCA_Constructor_out SIZE
#define tokens_PCA_Constructor_out Constructor_PCA_PCA_Constructor_out->contents

////////////////////////////////////////////////////////////////////////////////
// Successors
extern actor_t VCA;
extern actor_t LSU;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define Constructor_PCA_bands4core 55
#define Constructor_PCA_rc 10000
#define Constructor_PCA_bands 221
#define Constructor_PCA_num_PC 100
static i32 received = 0;
static i32 received0 = 0;
static i32 received1 = 0;
static i32 received2 = 0;
static i32 received3 = 0;
static i32 sent = 0;
static i32 point = 0;
static double image_IN[10000][221];
static double image_Mult[221][221];
static double matrix_eigen[221][221];
static double image_Prima[10000][221];
static double image_Prima_Transp[221][10000];
static double PCA_eigen[221][100];
static double PCA_out[10000][100];
static i32 pca_done = 0;
static float array_rec[10000];
static float array[221];
static float output[100];
static float array_env[100];
static double element_received;
static double tINI;
static double tEND;
static double tDIFF;



////////////////////////////////////////////////////////////////////////////////
// Token functions
static void read_Constructor_in0() {
	index_Constructor_in0 = Constructor_PCA_Constructor_in0->read_inds[0];
	numTokens_Constructor_in0 = index_Constructor_in0 + fifo_float_get_num_tokens(Constructor_PCA_Constructor_in0, 0);
}

static void read_end_Constructor_in0() {
	Constructor_PCA_Constructor_in0->read_inds[0] = index_Constructor_in0;
}
static void read_Sec_Pointer0() {
	index_Sec_Pointer0 = Constructor_PCA_Sec_Pointer0->read_inds[0];
	numTokens_Sec_Pointer0 = index_Sec_Pointer0 + fifo_i32_get_num_tokens(Constructor_PCA_Sec_Pointer0, 0);
}

static void read_end_Sec_Pointer0() {
	Constructor_PCA_Sec_Pointer0->read_inds[0] = index_Sec_Pointer0;
}
static void read_Constructor_in1() {
	index_Constructor_in1 = Constructor_PCA_Constructor_in1->read_inds[0];
	numTokens_Constructor_in1 = index_Constructor_in1 + fifo_float_get_num_tokens(Constructor_PCA_Constructor_in1, 0);
}

static void read_end_Constructor_in1() {
	Constructor_PCA_Constructor_in1->read_inds[0] = index_Constructor_in1;
}
static void read_Sec_Pointer1() {
	index_Sec_Pointer1 = Constructor_PCA_Sec_Pointer1->read_inds[0];
	numTokens_Sec_Pointer1 = index_Sec_Pointer1 + fifo_i32_get_num_tokens(Constructor_PCA_Sec_Pointer1, 0);
}

static void read_end_Sec_Pointer1() {
	Constructor_PCA_Sec_Pointer1->read_inds[0] = index_Sec_Pointer1;
}
static void read_Constructor_in2() {
	index_Constructor_in2 = Constructor_PCA_Constructor_in2->read_inds[0];
	numTokens_Constructor_in2 = index_Constructor_in2 + fifo_float_get_num_tokens(Constructor_PCA_Constructor_in2, 0);
}

static void read_end_Constructor_in2() {
	Constructor_PCA_Constructor_in2->read_inds[0] = index_Constructor_in2;
}
static void read_Sec_Pointer2() {
	index_Sec_Pointer2 = Constructor_PCA_Sec_Pointer2->read_inds[0];
	numTokens_Sec_Pointer2 = index_Sec_Pointer2 + fifo_i32_get_num_tokens(Constructor_PCA_Sec_Pointer2, 0);
}

static void read_end_Sec_Pointer2() {
	Constructor_PCA_Sec_Pointer2->read_inds[0] = index_Sec_Pointer2;
}
static void read_Constructor_in3() {
	index_Constructor_in3 = Constructor_PCA_Constructor_in3->read_inds[0];
	numTokens_Constructor_in3 = index_Constructor_in3 + fifo_float_get_num_tokens(Constructor_PCA_Constructor_in3, 0);
}

static void read_end_Constructor_in3() {
	Constructor_PCA_Constructor_in3->read_inds[0] = index_Constructor_in3;
}
static void read_Sec_Pointer3() {
	index_Sec_Pointer3 = Constructor_PCA_Sec_Pointer3->read_inds[0];
	numTokens_Sec_Pointer3 = index_Sec_Pointer3 + fifo_i32_get_num_tokens(Constructor_PCA_Sec_Pointer3, 0);
}

static void read_end_Sec_Pointer3() {
	Constructor_PCA_Sec_Pointer3->read_inds[0] = index_Sec_Pointer3;
}
static void read_PCA_in() {
	index_PCA_in = Constructor_PCA_PCA_in->read_inds[0];
	numTokens_PCA_in = index_PCA_in + fifo_float_get_num_tokens(Constructor_PCA_PCA_in, 0);
}

static void read_end_PCA_in() {
	Constructor_PCA_PCA_in->read_inds[0] = index_PCA_in;
}
static void read_EOF() {
	index_EOF = Constructor_PCA_EOF->read_inds[1];
	numTokens_EOF = index_EOF + fifo_i32_get_num_tokens(Constructor_PCA_EOF, 1);
}

static void read_end_EOF() {
	Constructor_PCA_EOF->read_inds[1] = index_EOF;
}

static void write_PCA_Constructor_out() {
	index_PCA_Constructor_out = Constructor_PCA_PCA_Constructor_out->write_ind;
	numFree_PCA_Constructor_out = index_PCA_Constructor_out + fifo_float_get_room(Constructor_PCA_PCA_Constructor_out, NUM_READERS_PCA_Constructor_out, SIZE_PCA_Constructor_out);
}

static void write_end_PCA_Constructor_out() {
	Constructor_PCA_PCA_Constructor_out->write_ind = index_PCA_Constructor_out;
}

////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern double get_time();
extern double float_to_double(float value);
extern void matrix_mult(double matrix1[10000][10000], double matrix2[10000][10000], double matrixResult[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern void get_eigenvectMatrix(double matrixIn[10000][10000], double matrixEigenvectors[10000][10000], i32 rows, i32 columns);
extern void matrix_reduce(double matrix1[10000][10000], double matrix2[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern float double_to_float(double value);


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_receive_vector0() {
	i32 result;
	i32 local_received0;
	i32 local_bands4core;

	local_received0 = received0;
	local_bands4core = Constructor_PCA_bands4core;
	result = local_received0 < local_bands4core;
	return result;
}

static void receive_vector0() {

	i32 pointer_in0;
	i32 local_received0;
	double tmp_get_time;
	i32 idx_Constructor_in0;
	float local_Constructor_in0;
	i32 m;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;

	pointer_in0 = tokens_Sec_Pointer0[(index_Sec_Pointer0 + (0)) % SIZE_Sec_Pointer0];
	local_received0 = received0;
	if (local_received0 == 0) {
		printf("****Inicio Constructor PCA****\n");
		tmp_get_time = get_time();
		tINI = tmp_get_time;
	}
	point = pointer_in0;
	idx_Constructor_in0 = 0;
	while (idx_Constructor_in0 < 10000) {
		local_Constructor_in0 = tokens_Constructor_in0[(index_Constructor_in0 + (idx_Constructor_in0)) % SIZE_Constructor_in0];
		array_rec[idx_Constructor_in0] = local_Constructor_in0;
		idx_Constructor_in0 = idx_Constructor_in0 + 1;
	}
	m = 0;
	local_rc = Constructor_PCA_rc;
	while (m <= local_rc - 1) {
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[m][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][m] = local_element_received;
		m = m + 1;
	}
	local_received0 = received0;
	received0 = local_received0 + 1;

	// Update ports indexes
	index_Constructor_in0 += 10000;
	read_end_Constructor_in0();
	index_Sec_Pointer0 += 1;

	rate_Constructor_in0 += 10000;
	rate_Sec_Pointer0 += 1;
}
static void receive_vector0_aligned() {

	i32 pointer_in0;
	i32 local_received0;
	double tmp_get_time;
	i32 idx_Constructor_in0;
	float local_Constructor_in0;
	i32 m;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;

	pointer_in0 = tokens_Sec_Pointer0[(index_Sec_Pointer0 + (0)) % SIZE_Sec_Pointer0];
	local_received0 = received0;
	if (local_received0 == 0) {
		printf("****Inicio Constructor PCA****\n");
		tmp_get_time = get_time();
		tINI = tmp_get_time;
	}
	point = pointer_in0;
	idx_Constructor_in0 = 0;
	while (idx_Constructor_in0 < 10000) {
		local_Constructor_in0 = tokens_Constructor_in0[(index_Constructor_in0 % SIZE_Constructor_in0) + (idx_Constructor_in0)];
		array_rec[idx_Constructor_in0] = local_Constructor_in0;
		idx_Constructor_in0 = idx_Constructor_in0 + 1;
	}
	m = 0;
	local_rc = Constructor_PCA_rc;
	while (m <= local_rc - 1) {
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[m][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][m] = local_element_received;
		m = m + 1;
	}
	local_received0 = received0;
	received0 = local_received0 + 1;

	// Update ports indexes
	index_Constructor_in0 += 10000;
	read_end_Constructor_in0();
	index_Sec_Pointer0 += 1;

	rate_Constructor_in0 += 10000;
	rate_Sec_Pointer0 += 1;
}
static i32 isSchedulable_receive_vector1() {
	i32 result;
	i32 local_received1;
	i32 local_bands4core;
	i32 local_received0;

	local_received1 = received1;
	local_bands4core = Constructor_PCA_bands4core;
	local_received0 = received0;
	local_bands4core = Constructor_PCA_bands4core;
	result = (local_received1 < local_bands4core && local_received0 >= local_bands4core);
	return result;
}

static void receive_vector1() {

	i32 pointer_in1;
	i32 idx_Constructor_in1;
	float local_Constructor_in1;
	i32 j;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;
	i32 local_received1;

	pointer_in1 = tokens_Sec_Pointer1[(index_Sec_Pointer1 + (0)) % SIZE_Sec_Pointer1];
	point = pointer_in1;
	idx_Constructor_in1 = 0;
	while (idx_Constructor_in1 < 10000) {
		local_Constructor_in1 = tokens_Constructor_in1[(index_Constructor_in1 + (idx_Constructor_in1)) % SIZE_Constructor_in1];
		array_rec[idx_Constructor_in1] = local_Constructor_in1;
		idx_Constructor_in1 = idx_Constructor_in1 + 1;
	}
	j = 0;
	local_rc = Constructor_PCA_rc;
	while (j <= local_rc - 1) {
		tmp_array_rec = array_rec[j];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[j][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][j] = local_element_received;
		j = j + 1;
	}
	local_received1 = received1;
	received1 = local_received1 + 1;

	// Update ports indexes
	index_Constructor_in1 += 10000;
	read_end_Constructor_in1();
	index_Sec_Pointer1 += 1;

	rate_Constructor_in1 += 10000;
	rate_Sec_Pointer1 += 1;
}
static void receive_vector1_aligned() {

	i32 pointer_in1;
	i32 idx_Constructor_in1;
	float local_Constructor_in1;
	i32 j;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;
	i32 local_received1;

	pointer_in1 = tokens_Sec_Pointer1[(index_Sec_Pointer1 + (0)) % SIZE_Sec_Pointer1];
	point = pointer_in1;
	idx_Constructor_in1 = 0;
	while (idx_Constructor_in1 < 10000) {
		local_Constructor_in1 = tokens_Constructor_in1[(index_Constructor_in1 % SIZE_Constructor_in1) + (idx_Constructor_in1)];
		array_rec[idx_Constructor_in1] = local_Constructor_in1;
		idx_Constructor_in1 = idx_Constructor_in1 + 1;
	}
	j = 0;
	local_rc = Constructor_PCA_rc;
	while (j <= local_rc - 1) {
		tmp_array_rec = array_rec[j];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[j][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][j] = local_element_received;
		j = j + 1;
	}
	local_received1 = received1;
	received1 = local_received1 + 1;

	// Update ports indexes
	index_Constructor_in1 += 10000;
	read_end_Constructor_in1();
	index_Sec_Pointer1 += 1;

	rate_Constructor_in1 += 10000;
	rate_Sec_Pointer1 += 1;
}
static i32 isSchedulable_receive_vector2() {
	i32 result;
	i32 local_received2;
	i32 local_bands4core;
	i32 local_received1;

	local_received2 = received2;
	local_bands4core = Constructor_PCA_bands4core;
	local_received1 = received1;
	local_bands4core = Constructor_PCA_bands4core;
	result = (local_received2 < local_bands4core && local_received1 >= local_bands4core);
	return result;
}

static void receive_vector2() {

	i32 pointer_in2;
	i32 idx_Constructor_in2;
	float local_Constructor_in2;
	i32 k;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;
	i32 local_received2;

	pointer_in2 = tokens_Sec_Pointer2[(index_Sec_Pointer2 + (0)) % SIZE_Sec_Pointer2];
	point = pointer_in2;
	idx_Constructor_in2 = 0;
	while (idx_Constructor_in2 < 10000) {
		local_Constructor_in2 = tokens_Constructor_in2[(index_Constructor_in2 + (idx_Constructor_in2)) % SIZE_Constructor_in2];
		array_rec[idx_Constructor_in2] = local_Constructor_in2;
		idx_Constructor_in2 = idx_Constructor_in2 + 1;
	}
	k = 0;
	local_rc = Constructor_PCA_rc;
	while (k <= local_rc - 1) {
		tmp_array_rec = array_rec[k];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[k][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][k] = local_element_received;
		k = k + 1;
	}
	local_received2 = received2;
	received2 = local_received2 + 1;

	// Update ports indexes
	index_Constructor_in2 += 10000;
	read_end_Constructor_in2();
	index_Sec_Pointer2 += 1;

	rate_Constructor_in2 += 10000;
	rate_Sec_Pointer2 += 1;
}
static void receive_vector2_aligned() {

	i32 pointer_in2;
	i32 idx_Constructor_in2;
	float local_Constructor_in2;
	i32 k;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;
	i32 local_received2;

	pointer_in2 = tokens_Sec_Pointer2[(index_Sec_Pointer2 + (0)) % SIZE_Sec_Pointer2];
	point = pointer_in2;
	idx_Constructor_in2 = 0;
	while (idx_Constructor_in2 < 10000) {
		local_Constructor_in2 = tokens_Constructor_in2[(index_Constructor_in2 % SIZE_Constructor_in2) + (idx_Constructor_in2)];
		array_rec[idx_Constructor_in2] = local_Constructor_in2;
		idx_Constructor_in2 = idx_Constructor_in2 + 1;
	}
	k = 0;
	local_rc = Constructor_PCA_rc;
	while (k <= local_rc - 1) {
		tmp_array_rec = array_rec[k];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[k][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][k] = local_element_received;
		k = k + 1;
	}
	local_received2 = received2;
	received2 = local_received2 + 1;

	// Update ports indexes
	index_Constructor_in2 += 10000;
	read_end_Constructor_in2();
	index_Sec_Pointer2 += 1;

	rate_Constructor_in2 += 10000;
	rate_Sec_Pointer2 += 1;
}
static i32 isSchedulable_receive_vector3() {
	i32 result;
	i32 local_received3;
	i32 local_bands4core;
	i32 local_received2;

	local_received3 = received3;
	local_bands4core = Constructor_PCA_bands4core;
	local_received2 = received2;
	local_bands4core = Constructor_PCA_bands4core;
	result = (local_received3 < local_bands4core && local_received2 >= local_bands4core);
	return result;
}

static void receive_vector3() {

	i32 pointer_in3;
	i32 idx_Constructor_in3;
	float local_Constructor_in3;
	i32 n;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;
	i32 local_received3;

	pointer_in3 = tokens_Sec_Pointer3[(index_Sec_Pointer3 + (0)) % SIZE_Sec_Pointer3];
	point = pointer_in3;
	idx_Constructor_in3 = 0;
	while (idx_Constructor_in3 < 10000) {
		local_Constructor_in3 = tokens_Constructor_in3[(index_Constructor_in3 + (idx_Constructor_in3)) % SIZE_Constructor_in3];
		array_rec[idx_Constructor_in3] = local_Constructor_in3;
		idx_Constructor_in3 = idx_Constructor_in3 + 1;
	}
	n = 0;
	local_rc = Constructor_PCA_rc;
	while (n <= local_rc - 1) {
		tmp_array_rec = array_rec[n];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[n][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][n] = local_element_received;
		n = n + 1;
	}
	local_received3 = received3;
	received3 = local_received3 + 1;

	// Update ports indexes
	index_Constructor_in3 += 10000;
	read_end_Constructor_in3();
	index_Sec_Pointer3 += 1;

	rate_Constructor_in3 += 10000;
	rate_Sec_Pointer3 += 1;
}
static void receive_vector3_aligned() {

	i32 pointer_in3;
	i32 idx_Constructor_in3;
	float local_Constructor_in3;
	i32 n;
	i32 local_rc;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_point;
	double local_element_received;
	i32 local_received3;

	pointer_in3 = tokens_Sec_Pointer3[(index_Sec_Pointer3 + (0)) % SIZE_Sec_Pointer3];
	point = pointer_in3;
	idx_Constructor_in3 = 0;
	while (idx_Constructor_in3 < 10000) {
		local_Constructor_in3 = tokens_Constructor_in3[(index_Constructor_in3 % SIZE_Constructor_in3) + (idx_Constructor_in3)];
		array_rec[idx_Constructor_in3] = local_Constructor_in3;
		idx_Constructor_in3 = idx_Constructor_in3 + 1;
	}
	n = 0;
	local_rc = Constructor_PCA_rc;
	while (n <= local_rc - 1) {
		tmp_array_rec = array_rec[n];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		element_received = tmp_float_to_double;
		local_point = point;
		local_element_received = element_received;
		image_Prima[n][local_point] = local_element_received;
		local_point = point;
		local_element_received = element_received;
		image_Prima_Transp[local_point][n] = local_element_received;
		n = n + 1;
	}
	local_received3 = received3;
	received3 = local_received3 + 1;

	// Update ports indexes
	index_Constructor_in3 += 10000;
	read_end_Constructor_in3();
	index_Sec_Pointer3 += 1;

	rate_Constructor_in3 += 10000;
	rate_Sec_Pointer3 += 1;
}
static i32 isSchedulable_receive_data() {
	i32 result;
	i32 local_received;
	i32 local_rc;
	i32 local_received3;
	i32 local_bands4core;

	local_received = received;
	local_rc = Constructor_PCA_rc;
	local_received3 = received3;
	local_bands4core = Constructor_PCA_bands4core;
	result = (local_received < local_rc && local_received3 >= local_bands4core);
	return result;
}

static void receive_data() {

	i32 endOfFile;
	i32 idx_PCA_in;
	float local_PCA_in;
	i32 t;
	i32 local_bands;
	i32 local_received;
	float tmp_array;
	double tmp_float_to_double;

	endOfFile = tokens_EOF[(index_EOF + (0)) % SIZE_EOF];
	if (endOfFile == 1) {
		printf("****No hay puto fichero de mis cojones****\n");
	} else {
		idx_PCA_in = 0;
		while (idx_PCA_in < 221) {
			local_PCA_in = tokens_PCA_in[(index_PCA_in + (idx_PCA_in)) % SIZE_PCA_in];
			array[idx_PCA_in] = local_PCA_in;
			idx_PCA_in = idx_PCA_in + 1;
		}
		t = 0;
		local_bands = Constructor_PCA_bands;
		while (t <= local_bands - 1) {
			local_received = received;
			tmp_array = array[t];
			tmp_float_to_double = float_to_double(tmp_array);
			image_IN[local_received][t] = tmp_float_to_double;
			t = t + 1;
		}
		local_received = received;
		received = local_received + 1;
	}

	// Update ports indexes
	index_PCA_in += 221;
	read_end_PCA_in();
	index_EOF += 1;

	rate_PCA_in += 221;
	rate_EOF += 1;
}
static void receive_data_aligned() {

	i32 endOfFile;
	i32 idx_PCA_in;
	float local_PCA_in;
	i32 t;
	i32 local_bands;
	i32 local_received;
	float tmp_array;
	double tmp_float_to_double;

	endOfFile = tokens_EOF[(index_EOF + (0)) % SIZE_EOF];
	if (endOfFile == 1) {
		printf("****No hay puto fichero de mis cojones****\n");
	} else {
		idx_PCA_in = 0;
		while (idx_PCA_in < 221) {
			local_PCA_in = tokens_PCA_in[(index_PCA_in % SIZE_PCA_in) + (idx_PCA_in)];
			array[idx_PCA_in] = local_PCA_in;
			idx_PCA_in = idx_PCA_in + 1;
		}
		t = 0;
		local_bands = Constructor_PCA_bands;
		while (t <= local_bands - 1) {
			local_received = received;
			tmp_array = array[t];
			tmp_float_to_double = float_to_double(tmp_array);
			image_IN[local_received][t] = tmp_float_to_double;
			t = t + 1;
		}
		local_received = received;
		received = local_received + 1;
	}

	// Update ports indexes
	index_PCA_in += 221;
	read_end_PCA_in();
	index_EOF += 1;

	rate_PCA_in += 221;
	rate_EOF += 1;
}
static i32 isSchedulable_PCA_algorithm() {
	i32 result;
	i32 local_pca_done;
	i32 local_received;
	i32 local_rc;

	local_pca_done = pca_done;
	local_received = received;
	local_rc = Constructor_PCA_rc;
	result = (local_pca_done == 0 && local_received >= local_rc);
	return result;
}

static void PCA_algorithm() {

	i32 local_bands;
	i32 local_rc;
	i32 local_num_PC;

	local_bands = Constructor_PCA_bands;
	local_rc = Constructor_PCA_rc;
	local_rc = Constructor_PCA_rc;
	local_bands = Constructor_PCA_bands;
	matrix_mult(image_Prima_Transp, image_Prima, image_Mult, local_bands, local_rc, local_rc, local_bands);
	local_bands = Constructor_PCA_bands;
	local_bands = Constructor_PCA_bands;
	get_eigenvectMatrix(image_Mult, matrix_eigen, local_bands, local_bands);
	local_bands = Constructor_PCA_bands;
	local_bands = Constructor_PCA_bands;
	local_bands = Constructor_PCA_bands;
	local_num_PC = Constructor_PCA_num_PC;
	matrix_reduce(matrix_eigen, PCA_eigen, local_bands, local_bands, local_bands, local_num_PC);
	local_rc = Constructor_PCA_rc;
	local_bands = Constructor_PCA_bands;
	local_bands = Constructor_PCA_bands;
	local_num_PC = Constructor_PCA_num_PC;
	matrix_mult(image_IN, PCA_eigen, PCA_out, local_rc, local_bands, local_bands, local_num_PC);
	pca_done = 1;

	// Update ports indexes

}
static i32 isSchedulable_send() {
	i32 result;
	i32 local_sent;
	i32 local_rc;
	i32 local_pca_done;

	local_sent = sent;
	local_rc = Constructor_PCA_rc;
	local_pca_done = pca_done;
	result = (local_sent < local_rc && local_pca_done == 1);
	return result;
}

static void send() {

	i32 s;
	i32 local_num_PC;
	i32 local_sent;
	double tmp_PCA_out;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 local_rc;
	double tmp_get_time;
	double local_tEND;
	double local_tINI;
	double local_tDIFF;
	i32 idx_output;
	float local_output;

	s = 0;
	local_num_PC = Constructor_PCA_num_PC;
	while (s <= local_num_PC - 1) {
		local_sent = sent;
		tmp_PCA_out = PCA_out[local_sent][s];
		tmp_double_to_float = double_to_float(tmp_PCA_out);
		array_env[s] = tmp_double_to_float;
		s = s + 1;
	}
	idx_array_env = 0;
	while (idx_array_env < 100) {
		local_array_env = array_env[idx_array_env];
		output[idx_array_env] = local_array_env;
		idx_array_env = idx_array_env + 1;
	}
	local_sent = sent;
	sent = local_sent + 1;
	local_sent = sent;
	local_rc = Constructor_PCA_rc;
	if (local_sent == local_rc) {
		tmp_get_time = get_time();
		tEND = tmp_get_time;
		local_tEND = tEND;
		local_tINI = tINI;
		tDIFF = local_tEND - local_tINI;
		local_tDIFF = tDIFF;
		printf("El tiempo Constructor PCA es: %f\n", local_tDIFF);
	}
	idx_output = 0;
	while (idx_output < 100) {
		local_output = output[idx_output];
		tokens_PCA_Constructor_out[(index_PCA_Constructor_out + (idx_output)) % SIZE_PCA_Constructor_out] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_PCA_Constructor_out += 100;
	write_end_PCA_Constructor_out();

}
static void send_aligned() {

	i32 s;
	i32 local_num_PC;
	i32 local_sent;
	double tmp_PCA_out;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 local_rc;
	double tmp_get_time;
	double local_tEND;
	double local_tINI;
	double local_tDIFF;
	i32 idx_output;
	float local_output;

	s = 0;
	local_num_PC = Constructor_PCA_num_PC;
	while (s <= local_num_PC - 1) {
		local_sent = sent;
		tmp_PCA_out = PCA_out[local_sent][s];
		tmp_double_to_float = double_to_float(tmp_PCA_out);
		array_env[s] = tmp_double_to_float;
		s = s + 1;
	}
	idx_array_env = 0;
	while (idx_array_env < 100) {
		local_array_env = array_env[idx_array_env];
		output[idx_array_env] = local_array_env;
		idx_array_env = idx_array_env + 1;
	}
	local_sent = sent;
	sent = local_sent + 1;
	local_sent = sent;
	local_rc = Constructor_PCA_rc;
	if (local_sent == local_rc) {
		tmp_get_time = get_time();
		tEND = tmp_get_time;
		local_tEND = tEND;
		local_tINI = tINI;
		tDIFF = local_tEND - local_tINI;
		local_tDIFF = tDIFF;
		printf("El tiempo Constructor PCA es: %f\n", local_tDIFF);
	}
	idx_output = 0;
	while (idx_output < 100) {
		local_output = output[idx_output];
		tokens_PCA_Constructor_out[(index_PCA_Constructor_out % SIZE_PCA_Constructor_out) + (idx_output)] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_PCA_Constructor_out += 100;
	write_end_PCA_Constructor_out();

}

////////////////////////////////////////////////////////////////////////////////
// Initializes

void Constructor_PCA_initialize(schedinfo_t *si) {
	int i = 0;
	write_PCA_Constructor_out();
finished:
	write_end_PCA_Constructor_out();
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler
void Constructor_PCA_scheduler(schedinfo_t *si) {
	int i = 0;
	si->ports = 0;

	read_Constructor_in0();
	read_Sec_Pointer0();
	read_Constructor_in1();
	read_Sec_Pointer1();
	read_Constructor_in2();
	read_Sec_Pointer2();
	read_Constructor_in3();
	read_Sec_Pointer3();
	read_PCA_in();
	read_EOF();
	write_PCA_Constructor_out();

	while (1) {
		if (numTokens_Constructor_in0 - index_Constructor_in0 >= 10000 && numTokens_Sec_Pointer0 - index_Sec_Pointer0 >= 1 && isSchedulable_receive_vector0()) {
			{
				int isAligned = 1;
				isAligned &= ((index_Constructor_in0 % SIZE_Constructor_in0) < ((index_Constructor_in0 + 10000) % SIZE_Constructor_in0));
				if (isAligned) {
					receive_vector0_aligned();
				} else {
					receive_vector0();
				}
			}
			i++;
		} else if (numTokens_Constructor_in1 - index_Constructor_in1 >= 10000 && numTokens_Sec_Pointer1 - index_Sec_Pointer1 >= 1 && isSchedulable_receive_vector1()) {
			{
				int isAligned = 1;
				isAligned &= ((index_Constructor_in1 % SIZE_Constructor_in1) < ((index_Constructor_in1 + 10000) % SIZE_Constructor_in1));
				if (isAligned) {
					receive_vector1_aligned();
				} else {
					receive_vector1();
				}
			}
			i++;
		} else if (numTokens_Constructor_in2 - index_Constructor_in2 >= 10000 && numTokens_Sec_Pointer2 - index_Sec_Pointer2 >= 1 && isSchedulable_receive_vector2()) {
			{
				int isAligned = 1;
				isAligned &= ((index_Constructor_in2 % SIZE_Constructor_in2) < ((index_Constructor_in2 + 10000) % SIZE_Constructor_in2));
				if (isAligned) {
					receive_vector2_aligned();
				} else {
					receive_vector2();
				}
			}
			i++;
		} else if (numTokens_Constructor_in3 - index_Constructor_in3 >= 10000 && numTokens_Sec_Pointer3 - index_Sec_Pointer3 >= 1 && isSchedulable_receive_vector3()) {
			{
				int isAligned = 1;
				isAligned &= ((index_Constructor_in3 % SIZE_Constructor_in3) < ((index_Constructor_in3 + 10000) % SIZE_Constructor_in3));
				if (isAligned) {
					receive_vector3_aligned();
				} else {
					receive_vector3();
				}
			}
			i++;
		} else if (numTokens_PCA_in - index_PCA_in >= 221 && numTokens_EOF - index_EOF >= 1 && isSchedulable_receive_data()) {
			{
				int isAligned = 1;
				isAligned &= ((index_PCA_in % SIZE_PCA_in) < ((index_PCA_in + 221) % SIZE_PCA_in));
				if (isAligned) {
					receive_data_aligned();
				} else {
					receive_data();
				}
			}
			i++;
		} else if (isSchedulable_PCA_algorithm()) {
			PCA_algorithm();
			i++;
		} else if (isSchedulable_send()) {
			int stop = 0;
			if (100 > SIZE_PCA_Constructor_out - index_PCA_Constructor_out + Constructor_PCA_PCA_Constructor_out->read_inds[0]) {
				stop = 1;
			}
			if (100 > SIZE_PCA_Constructor_out - index_PCA_Constructor_out + Constructor_PCA_PCA_Constructor_out->read_inds[1]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_PCA_Constructor_out % SIZE_PCA_Constructor_out) < ((index_PCA_Constructor_out + 100) % SIZE_PCA_Constructor_out));
				if (isAligned) {
					send_aligned();
				} else {
					send();
				}
			}
			i++;
		} else {
			si->num_firings = i;
			si->reason = starved;
			goto finished;
		}
	}

finished:

	read_end_Constructor_in0();
	read_end_Sec_Pointer0();
	read_end_Constructor_in1();
	read_end_Sec_Pointer1();
	read_end_Constructor_in2();
	read_end_Sec_Pointer2();
	read_end_Constructor_in3();
	read_end_Sec_Pointer3();
	read_end_PCA_in();
	read_end_EOF();
	write_end_PCA_Constructor_out();
}
