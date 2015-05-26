// Source file is "L/hsi_system_Optimized_v1.0/src/PCA_Code_Optimized.cal"

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#include "types.h"
#include "fifo.h"
#include "util.h"
#include "scheduler.h"
#include "dataflow.h"
#include "cycle.h"

#define SIZE 512

////////////////////////////////////////////////////////////////////////////////
// Instance
extern actor_t PCA;

////////////////////////////////////////////////////////////////////////////////
// Input FIFOs
extern fifo_float_t *PCA_PCA_in;
extern fifo_i32_t *PCA_EOF;

////////////////////////////////////////////////////////////////////////////////
// Input Fifo control variables
static unsigned int index_PCA_in;
static unsigned int numTokens_PCA_in;
#define SIZE_PCA_in SIZE
#define tokens_PCA_in PCA_PCA_in->contents

extern connection_t connection_PCA_PCA_in;
#define rate_PCA_in connection_PCA_PCA_in.rate

static unsigned int index_EOF;
static unsigned int numTokens_EOF;
#define SIZE_EOF SIZE
#define tokens_EOF PCA_EOF->contents

extern connection_t connection_PCA_EOF;
#define rate_EOF connection_PCA_EOF.rate

////////////////////////////////////////////////////////////////////////////////
// Predecessors
extern actor_t Source;
extern actor_t Source;

////////////////////////////////////////////////////////////////////////////////
// Output FIFOs
extern fifo_float_t *PCA_PCA_out;

////////////////////////////////////////////////////////////////////////////////
// Output Fifo control variables
static unsigned int index_PCA_out;
static unsigned int numFree_PCA_out;
#define NUM_READERS_PCA_out 2
#define SIZE_PCA_out SIZE
#define tokens_PCA_out PCA_PCA_out->contents

////////////////////////////////////////////////////////////////////////////////
// Successors
extern actor_t VCA;
extern actor_t LSU;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define PCA_rc 10000
#define PCA_bands 221
#define PCA_num_PC 25
static double image_IN[10000][221];
static double image_Prima[10000][221];
static double image_Prima_Transp[221][10000];
static double image_Mult[221][221];
static i32 pca_done = 0;
static double averageVector[10000];
static double averageVectorResult;
static double minusVectorResult[10000];
static double matrix_eigen[221][221];
static double PCA_eigen[221][25];
static double PCA_out[10000][25];
static i32 received = 0;
static i32 token_sent = 0;
static float array_rec[221];
static float output[25];
static float array_env[25];
static double tINI;
static double tEND;
static double tDIFF;



////////////////////////////////////////////////////////////////////////////////
// Token functions
static void read_PCA_in() {
	index_PCA_in = PCA_PCA_in->read_inds[0];
	numTokens_PCA_in = index_PCA_in + fifo_float_get_num_tokens(PCA_PCA_in, 0);
}

static void read_end_PCA_in() {
	PCA_PCA_in->read_inds[0] = index_PCA_in;
}
static void read_EOF() {
	index_EOF = PCA_EOF->read_inds[0];
	numTokens_EOF = index_EOF + fifo_i32_get_num_tokens(PCA_EOF, 0);
}

static void read_end_EOF() {
	PCA_EOF->read_inds[0] = index_EOF;
}

static void write_PCA_out() {
	index_PCA_out = PCA_PCA_out->write_ind;
	numFree_PCA_out = index_PCA_out + fifo_float_get_room(PCA_PCA_out, NUM_READERS_PCA_out, SIZE_PCA_out);
}

static void write_end_PCA_out() {
	PCA_PCA_out->write_ind = index_PCA_out;
}

////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern double float_to_double(float value);
extern double get_time();
extern void matrix_get_column(double matrix1[10000][10000], double vector[10000], double rows1, double columns1, double column);
extern double mean_vector(double vector[10000], i32 positions);
extern void vector_minus_value(double vectorIn[10000], double value, double vectorMinus[10000], i32 positions);
extern void matrix_set_column(double matrix1[10000][10000], double vector[10000], double rows1, double columns1, double column);
extern void matrix_set_row(double matrix1[10000][10000], double vector[10000], double rows1, double columns1, double row);
extern void matrix_mult(double matrix1[10000][10000], double matrix2[10000][10000], double matrixResult[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern void get_eigenvectMatrix(double matrixIn[10000][10000], double matrixEigenvectors[10000][10000], i32 rows, i32 columns);
extern void matrix_reduce(double matrix1[10000][10000], double matrix2[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern void write_txt(double matrixOut[10000][10000], i32 rows, i32 columns, char * fileName);
extern float double_to_float(double value);


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_receive_data() {
	i32 result;
	i32 endOfFile;
	i32 local_received;
	i32 local_rc;

	endOfFile = tokens_EOF[(index_EOF + (0)) % SIZE_EOF];
	local_received = received;
	local_rc = PCA_rc;
	result = (local_received < local_rc && endOfFile == 0);
	return result;
}

static void receive_data() {

	i32 endOfFile;
	i32 idx_PCA_in;
	float local_PCA_in;
	i32 m;
	i32 local_bands;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;

	endOfFile = tokens_EOF[(index_EOF + (0)) % SIZE_EOF];
	idx_PCA_in = 0;
	while (idx_PCA_in < 221) {
		local_PCA_in = tokens_PCA_in[(index_PCA_in + (idx_PCA_in)) % SIZE_PCA_in];
		array_rec[idx_PCA_in] = local_PCA_in;
		idx_PCA_in = idx_PCA_in + 1;
	}
	m = 0;
	local_bands = PCA_bands;
	while (m <= local_bands - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_IN[local_received][m] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;

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
	i32 m;
	i32 local_bands;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;

	endOfFile = tokens_EOF[(index_EOF + (0)) % SIZE_EOF];
	idx_PCA_in = 0;
	while (idx_PCA_in < 221) {
		local_PCA_in = tokens_PCA_in[(index_PCA_in % SIZE_PCA_in) + (idx_PCA_in)];
		array_rec[idx_PCA_in] = local_PCA_in;
		idx_PCA_in = idx_PCA_in + 1;
	}
	m = 0;
	local_bands = PCA_bands;
	while (m <= local_bands - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_IN[local_received][m] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;

	// Update ports indexes
	index_PCA_in += 221;
	read_end_PCA_in();
	index_EOF += 1;

	rate_PCA_in += 221;
	rate_EOF += 1;
}
static i32 isSchedulable_PCA_alogrithm() {
	i32 result;
	i32 local_pca_done;
	i32 local_received;
	i32 local_rc;

	local_pca_done = pca_done;
	local_received = received;
	local_rc = PCA_rc;
	result = (local_pca_done == 0 && local_received >= local_rc);
	return result;
}

static void PCA_alogrithm() {

	double tmp_get_time;
	i32 i;
	i32 local_bands;
	i32 local_rc;
	double tmp_mean_vector;
	double local_averageVectorResult;
	i32 local_num_PC;
	double tmp_get_time0;
	double local_tEND;
	double local_tINI;
	double local_tDIFF;

	printf("****Inicio PCA****\n");
	tmp_get_time = get_time();
	tINI = tmp_get_time;
	i = 0;
	local_bands = PCA_bands;
	while (i <= local_bands - 1) {
		local_rc = PCA_rc;
		local_bands = PCA_bands;
		matrix_get_column(image_IN, averageVector, local_rc, local_bands, i);
		local_rc = PCA_rc;
		tmp_mean_vector = mean_vector(averageVector, local_rc);
		averageVectorResult = tmp_mean_vector;
		local_averageVectorResult = averageVectorResult;
		local_rc = PCA_rc;
		vector_minus_value(averageVector, local_averageVectorResult, minusVectorResult, local_rc);
		local_rc = PCA_rc;
		local_bands = PCA_bands;
		matrix_set_column(image_Prima, minusVectorResult, local_rc, local_bands, i);
		local_bands = PCA_bands;
		local_rc = PCA_rc;
		matrix_set_row(image_Prima_Transp, minusVectorResult, local_bands, local_rc, i);
		i = i + 1;
	}
	local_bands = PCA_bands;
	local_rc = PCA_rc;
	local_rc = PCA_rc;
	local_bands = PCA_bands;
	matrix_mult(image_Prima_Transp, image_Prima, image_Mult, local_bands, local_rc, local_rc, local_bands);
	local_bands = PCA_bands;
	local_bands = PCA_bands;
	get_eigenvectMatrix(image_Mult, matrix_eigen, local_bands, local_bands);
	local_bands = PCA_bands;
	local_bands = PCA_bands;
	local_bands = PCA_bands;
	local_num_PC = PCA_num_PC;
	matrix_reduce(matrix_eigen, PCA_eigen, local_bands, local_bands, local_bands, local_num_PC);
	local_rc = PCA_rc;
	local_bands = PCA_bands;
	local_bands = PCA_bands;
	local_num_PC = PCA_num_PC;
	matrix_mult(image_IN, PCA_eigen, PCA_out, local_rc, local_bands, local_bands, local_num_PC);
	tmp_get_time0 = get_time();
	tEND = tmp_get_time0;
	local_tEND = tEND;
	local_tINI = tINI;
	tDIFF = local_tEND - local_tINI;
	local_tDIFF = tDIFF;
	printf("El tiempo total de PCA es: %f\n", local_tDIFF);
	local_rc = PCA_rc;
	local_num_PC = PCA_num_PC;
	write_txt(PCA_out, local_rc, local_num_PC, "PCA_25_OPT.TXT");
	printf("****Fin PCA****\n");
	pca_done = 1;

	// Update ports indexes

}
static i32 isSchedulable_send() {
	i32 result;
	i32 local_pca_done;
	i32 local_token_sent;
	i32 local_rc;

	local_pca_done = pca_done;
	local_token_sent = token_sent;
	local_rc = PCA_rc;
	result = (local_pca_done == 1 && local_token_sent < local_rc);
	return result;
}

static void send() {

	i32 m;
	i32 local_num_PC;
	i32 local_token_sent;
	double tmp_PCA_out;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 idx_output;
	float local_output;

	m = 0;
	local_num_PC = PCA_num_PC;
	while (m <= local_num_PC - 1) {
		local_token_sent = token_sent;
		tmp_PCA_out = PCA_out[local_token_sent][m];
		tmp_double_to_float = double_to_float(tmp_PCA_out);
		array_env[m] = tmp_double_to_float;
		m = m + 1;
	}
	idx_array_env = 0;
	while (idx_array_env < 25) {
		local_array_env = array_env[idx_array_env];
		output[idx_array_env] = local_array_env;
		idx_array_env = idx_array_env + 1;
	}
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_output = 0;
	while (idx_output < 25) {
		local_output = output[idx_output];
		tokens_PCA_out[(index_PCA_out + (idx_output)) % SIZE_PCA_out] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_PCA_out += 25;
	write_end_PCA_out();

}
static void send_aligned() {

	i32 m;
	i32 local_num_PC;
	i32 local_token_sent;
	double tmp_PCA_out;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 idx_output;
	float local_output;

	m = 0;
	local_num_PC = PCA_num_PC;
	while (m <= local_num_PC - 1) {
		local_token_sent = token_sent;
		tmp_PCA_out = PCA_out[local_token_sent][m];
		tmp_double_to_float = double_to_float(tmp_PCA_out);
		array_env[m] = tmp_double_to_float;
		m = m + 1;
	}
	idx_array_env = 0;
	while (idx_array_env < 25) {
		local_array_env = array_env[idx_array_env];
		output[idx_array_env] = local_array_env;
		idx_array_env = idx_array_env + 1;
	}
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_output = 0;
	while (idx_output < 25) {
		local_output = output[idx_output];
		tokens_PCA_out[(index_PCA_out % SIZE_PCA_out) + (idx_output)] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_PCA_out += 25;
	write_end_PCA_out();

}

////////////////////////////////////////////////////////////////////////////////
// Initializes

void PCA_initialize(schedinfo_t *si) {
	int i = 0;
	write_PCA_out();
finished:
	write_end_PCA_out();
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler
void PCA_scheduler(schedinfo_t *si) {
	int i = 0;
	si->ports = 0;

	read_PCA_in();
	read_EOF();
	write_PCA_out();

	while (1) {
		if (numTokens_PCA_in - index_PCA_in >= 221 && numTokens_EOF - index_EOF >= 1 && isSchedulable_receive_data()) {
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
		} else if (isSchedulable_PCA_alogrithm()) {
			PCA_alogrithm();
			i++;
		} else if (isSchedulable_send()) {
			int stop = 0;
			if (25 > SIZE_PCA_out - index_PCA_out + PCA_PCA_out->read_inds[0]) {
				stop = 1;
			}
			if (25 > SIZE_PCA_out - index_PCA_out + PCA_PCA_out->read_inds[1]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_PCA_out % SIZE_PCA_out) < ((index_PCA_out + 25) % SIZE_PCA_out));
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

	read_end_PCA_in();
	read_end_EOF();
	write_end_PCA_out();
}
