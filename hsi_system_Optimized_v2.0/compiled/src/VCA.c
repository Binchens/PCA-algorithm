// Source file is "L/hsi_system_Optimized_v1.0/src/VCA.cal"

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
extern actor_t VCA;

////////////////////////////////////////////////////////////////////////////////
// Input FIFOs
extern fifo_float_t *VCA_VCA_in;

////////////////////////////////////////////////////////////////////////////////
// Input Fifo control variables
static unsigned int index_VCA_in;
static unsigned int numTokens_VCA_in;
#define SIZE_VCA_in SIZE
#define tokens_VCA_in VCA_VCA_in->contents

extern connection_t connection_VCA_VCA_in;
#define rate_VCA_in connection_VCA_VCA_in.rate

////////////////////////////////////////////////////////////////////////////////
// Predecessors
extern actor_t PCA;

////////////////////////////////////////////////////////////////////////////////
// Output FIFOs
extern fifo_float_t *VCA_VCA_out;

////////////////////////////////////////////////////////////////////////////////
// Output Fifo control variables
static unsigned int index_VCA_out;
static unsigned int numFree_VCA_out;
#define NUM_READERS_VCA_out 1
#define SIZE_VCA_out SIZE
#define tokens_VCA_out VCA_VCA_out->contents

////////////////////////////////////////////////////////////////////////////////
// Successors
extern actor_t LSU;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define VCA_rc 10000
#define VCA_num_PC 25
#define VCA_num_Endmembers 20
#define VCA_int_Endmembers 20
static double image_INI[10000][25];
static double image_INI_Transp[25][10000];
static double averageVector[10000];
static double averageVectorResult[25];
static double minusVectorResult[10000];
static double image_Prima[10000][25];
static double image_Prima_Transp[25][10000];
static double image_SVD_Aux[25][25];
static double image_SVD_IN[25][25];
static double SVD_U[25][25];
static double matrix_Ud[25][19];
static double matrix_Ud_Transp[19][25];
static double matrix_xp[19][10000];
static double matrix_x_Transp[10000][19];
static double matrix_Rp_aux[25][10000];
static double matrix_Rp[25][10000];
static double projection[10000][20];
static i32 d;
static double c;
static double endmemberCollection[20][25];
static double A[20][20];
static double w[20];
static double matrix_p_inverse[20][20];
static double A_mult[20][20];
static double F_aux[20];
static double F[20];
static double F_divided[20];
static double sum_aux;
static double sqrt_value;
static double vTransp[10000];
static i32 index_replaced[20];
static i32 received = 0;
static i32 vca_done = 0;
static float output[25];
static float array_env[25];
static i32 token_sent = 0;
static float array_rec[25];
static double tINI_VCA;
static double tEND_VCA;
static double tDIFF_VCA;



////////////////////////////////////////////////////////////////////////////////
// Token functions
static void read_VCA_in() {
	index_VCA_in = VCA_VCA_in->read_inds[0];
	numTokens_VCA_in = index_VCA_in + fifo_float_get_num_tokens(VCA_VCA_in, 0);
}

static void read_end_VCA_in() {
	VCA_VCA_in->read_inds[0] = index_VCA_in;
}

static void write_VCA_out() {
	index_VCA_out = VCA_VCA_out->write_ind;
	numFree_VCA_out = index_VCA_out + fifo_float_get_room(VCA_VCA_out, NUM_READERS_VCA_out, SIZE_VCA_out);
}

static void write_end_VCA_out() {
	VCA_VCA_out->write_ind = index_VCA_out;
}

////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern double float_to_double(float value);
extern double get_time();
extern void transpose(double matrixIn[10000][10000], double matrixTranspose[10000][10000], double rows, double columns);
extern void matrix_get_row(double matrix1[10000][10000], double vector[10000], i32 rows1, i32 columns1, i32 row);
extern double mean_vector(double vector[10000], i32 positions);
extern void vector_minus_value(double vectorIn[10000], double value, double vectorMinus[10000], i32 positions);
extern void matrix_set_row(double matrix1[10000][10000], double vector[10000], double rows1, double columns1, double row);
extern void matrix_mult(double matrix1[10000][10000], double matrix2[10000][10000], double matrixResult[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern void matrix_scale(double matrixIn[10000][10000], double matrixOut[10000][10000], double value, i32 rows, i32 columns);
extern void get_eigenvectMatrix(double matrixIn[10000][10000], double matrixEigenvectors[10000][10000], i32 rows, i32 columns);
extern void matrix_reduce(double matrix1[10000][10000], double matrix2[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern double maxSqrtSum(double matrix[10000][10000], double rows, double columns);
extern void matrix_extend(double matrixIn[10000][10000], double matrixOut[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern void matrix_fill_column(double matrixIn[10000][10000], double rows1, double columns1, double column, double value);
extern void random_vector(double vector[10000], double positions);
extern void get_pinverse(double matrixIn[10000][10000], double matrix_p_inverse[10000][10000], i32 rows, i32 columns);
extern void matrix_mult_vector(double matrix1[10000][10000], double vector[10000], double vectorResult[10000], double rows1, double columns1, double positions_vector);
extern void vector_minus_vector(double vector1[10000], double vector2[10000], double vectorResult[10000], i32 positions);
extern double elev(double base, double power);
extern double sq_root(double value);
extern void vector_scale(double vectorIn[10000], double vectorOut[10000], double value, i32 positions);
extern i32 getIndexMax(double vector[10000], i32 positions);
extern float double_to_float(double value);


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_receive_data() {
	i32 result;
	i32 local_received;
	i32 local_rc;

	local_received = received;
	local_rc = VCA_rc;
	result = local_received < local_rc;
	return result;
}

static void receive_data() {

	i32 idx_VCA_in;
	float local_VCA_in;
	i32 m;
	i32 local_num_PC;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;

	idx_VCA_in = 0;
	while (idx_VCA_in < 25) {
		local_VCA_in = tokens_VCA_in[(index_VCA_in + (idx_VCA_in)) % SIZE_VCA_in];
		array_rec[idx_VCA_in] = local_VCA_in;
		idx_VCA_in = idx_VCA_in + 1;
	}
	m = 0;
	local_num_PC = VCA_num_PC;
	while (m <= local_num_PC - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_INI[local_received][m] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;

	// Update ports indexes
	index_VCA_in += 25;
	read_end_VCA_in();

	rate_VCA_in += 25;
}
static void receive_data_aligned() {

	i32 idx_VCA_in;
	float local_VCA_in;
	i32 m;
	i32 local_num_PC;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;

	idx_VCA_in = 0;
	while (idx_VCA_in < 25) {
		local_VCA_in = tokens_VCA_in[(index_VCA_in % SIZE_VCA_in) + (idx_VCA_in)];
		array_rec[idx_VCA_in] = local_VCA_in;
		idx_VCA_in = idx_VCA_in + 1;
	}
	m = 0;
	local_num_PC = VCA_num_PC;
	while (m <= local_num_PC - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_INI[local_received][m] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;

	// Update ports indexes
	index_VCA_in += 25;
	read_end_VCA_in();

	rate_VCA_in += 25;
}
static i32 isSchedulable_VCA_algorithm() {
	i32 result;
	i32 local_received;
	i32 local_rc;
	i32 local_vca_done;

	local_received = received;
	local_rc = VCA_rc;
	local_vca_done = vca_done;
	result = (local_received >= local_rc && local_vca_done == 0);
	return result;
}

static void VCA_algorithm() {

	double tmp_get_time;
	i32 local_rc;
	i32 local_num_PC;
	i32 i;
	double tmp_mean_vector;
	double tmp_averageVectorResult;
	double local_num_Endmembers;
	i32 i0;
	i32 j;
	double tmp_matrix_Rp_aux;
	double tmp_averageVectorResult0;
	double tmp_maxSqrtSum;
	double local_c;
	i32 local_int_Endmembers;
	i32 local_d;
	i32 i1;
	i32 j0;
	double local_sum_aux;
	double tmp_F;
	double tmp_elev;
	double tmp_sq_root;
	double local_sqrt_value;
	i32 tmp_getIndexMax;
	i32 k;
	i32 tmp_index;
	double tmp_projection;
	i32 z;
	i32 tmp_index0;
	double tmp_matrix_Rp;
	double tmp_get_time0;
	double local_tEND_VCA;
	double local_tINI_VCA;
	double local_tDIFF_VCA;

	printf("****Inicio VCA****\n");
	tmp_get_time = get_time();
	tINI_VCA = tmp_get_time;
	local_rc = VCA_rc;
	local_num_PC = VCA_num_PC;
	transpose(image_INI, image_INI_Transp, local_rc, local_num_PC);
	i = 0;
	local_num_PC = VCA_num_PC;
	while (i <= local_num_PC - 1) {
		local_num_PC = VCA_num_PC;
		local_rc = VCA_rc;
		matrix_get_row(image_INI_Transp, averageVector, local_num_PC, local_rc, i);
		local_rc = VCA_rc;
		tmp_mean_vector = mean_vector(averageVector, local_rc);
		averageVectorResult[i] = tmp_mean_vector;
		tmp_averageVectorResult = averageVectorResult[i];
		local_rc = VCA_rc;
		vector_minus_value(averageVector, tmp_averageVectorResult, minusVectorResult, local_rc);
		local_num_PC = VCA_num_PC;
		local_rc = VCA_rc;
		matrix_set_row(image_Prima_Transp, minusVectorResult, local_num_PC, local_rc, i);
		i = i + 1;
	}
	local_num_PC = VCA_num_PC;
	local_rc = VCA_rc;
	transpose(image_Prima_Transp, image_Prima, local_num_PC, local_rc);
	local_num_PC = VCA_num_PC;
	local_rc = VCA_rc;
	local_rc = VCA_rc;
	local_num_PC = VCA_num_PC;
	matrix_mult(image_Prima_Transp, image_Prima, image_SVD_Aux, local_num_PC, local_rc, local_rc, local_num_PC);
	local_num_PC = VCA_num_PC;
	local_num_PC = VCA_num_PC;
	local_num_PC = VCA_num_PC;
	matrix_scale(image_SVD_Aux, image_SVD_IN, local_num_PC, local_num_PC, local_num_PC);
	local_num_PC = VCA_num_PC;
	local_num_PC = VCA_num_PC;
	get_eigenvectMatrix(image_SVD_IN, SVD_U, local_num_PC, local_num_PC);
	local_num_PC = VCA_num_PC;
	local_num_PC = VCA_num_PC;
	local_num_PC = VCA_num_PC;
	local_num_Endmembers = VCA_num_Endmembers;
	matrix_reduce(SVD_U, matrix_Ud, local_num_PC, local_num_PC, local_num_PC, local_num_Endmembers - 1);
	local_num_PC = VCA_num_PC;
	local_num_Endmembers = VCA_num_Endmembers;
	transpose(matrix_Ud, matrix_Ud_Transp, local_num_PC, local_num_Endmembers - 1);
	local_num_Endmembers = VCA_num_Endmembers;
	local_num_PC = VCA_num_PC;
	local_num_PC = VCA_num_PC;
	local_rc = VCA_rc;
	matrix_mult(matrix_Ud_Transp, image_Prima_Transp, matrix_xp, local_num_Endmembers - 1, local_num_PC, local_num_PC, local_rc);
	local_num_PC = VCA_num_PC;
	local_num_Endmembers = VCA_num_Endmembers;
	local_num_Endmembers = VCA_num_Endmembers;
	local_rc = VCA_rc;
	matrix_mult(matrix_Ud, matrix_xp, matrix_Rp_aux, local_num_PC, local_num_Endmembers - 1, local_num_Endmembers - 1, local_rc);
	i0 = 0;
	local_num_PC = VCA_num_PC;
	while (i0 <= local_num_PC - 1) {
		j = 0;
		local_rc = VCA_rc;
		while (j <= local_rc - 1) {
			tmp_matrix_Rp_aux = matrix_Rp_aux[i0][j];
			tmp_averageVectorResult0 = averageVectorResult[i0];
			matrix_Rp[i0][j] = tmp_matrix_Rp_aux + tmp_averageVectorResult0;
			j = j + 1;
		}
		i0 = i0 + 1;
	}
	local_num_Endmembers = VCA_num_Endmembers;
	local_rc = VCA_rc;
	tmp_maxSqrtSum = maxSqrtSum(matrix_xp, local_num_Endmembers - 1, local_rc);
	c = tmp_maxSqrtSum;
	local_num_Endmembers = VCA_num_Endmembers;
	local_rc = VCA_rc;
	transpose(matrix_xp, matrix_x_Transp, local_num_Endmembers - 1, local_rc);
	local_rc = VCA_rc;
	local_num_Endmembers = VCA_num_Endmembers;
	local_rc = VCA_rc;
	local_num_Endmembers = VCA_num_Endmembers;
	matrix_extend(matrix_x_Transp, projection, local_rc, local_num_Endmembers - 1, local_rc, local_num_Endmembers);
	local_rc = VCA_rc;
	local_num_Endmembers = VCA_num_Endmembers;
	local_num_Endmembers = VCA_num_Endmembers;
	local_c = c;
	matrix_fill_column(projection, local_rc, local_num_Endmembers, local_num_Endmembers - 1, local_c);
	local_int_Endmembers = VCA_int_Endmembers;
	d = local_int_Endmembers - 1;
	local_d = d;
	A[local_d][0] = 1;
	i1 = 0;
	local_num_Endmembers = VCA_num_Endmembers;
	while (i1 <= local_num_Endmembers - 1) {
		local_num_Endmembers = VCA_num_Endmembers;
		random_vector(w, local_num_Endmembers);
		local_int_Endmembers = VCA_int_Endmembers;
		local_int_Endmembers = VCA_int_Endmembers;
		get_pinverse(A, matrix_p_inverse, local_int_Endmembers, local_int_Endmembers);
		local_num_Endmembers = VCA_num_Endmembers;
		local_num_Endmembers = VCA_num_Endmembers;
		local_num_Endmembers = VCA_num_Endmembers;
		local_num_Endmembers = VCA_num_Endmembers;
		matrix_mult(A, matrix_p_inverse, A_mult, local_num_Endmembers, local_num_Endmembers, local_num_Endmembers, local_num_Endmembers);
		local_num_Endmembers = VCA_num_Endmembers;
		local_num_Endmembers = VCA_num_Endmembers;
		local_num_Endmembers = VCA_num_Endmembers;
		matrix_mult_vector(A_mult, w, F_aux, local_num_Endmembers, local_num_Endmembers, local_num_Endmembers);
		local_int_Endmembers = VCA_int_Endmembers;
		vector_minus_vector(w, F_aux, F, local_int_Endmembers);
		sum_aux = 0;
		j0 = 0;
		local_num_Endmembers = VCA_num_Endmembers;
		while (j0 <= local_num_Endmembers - 1) {
			local_sum_aux = sum_aux;
			tmp_F = F[j0];
			tmp_elev = elev(tmp_F, 2);
			sum_aux = local_sum_aux + tmp_elev;
			j0 = j0 + 1;
		}
		local_sum_aux = sum_aux;
		tmp_sq_root = sq_root(local_sum_aux);
		sqrt_value = tmp_sq_root;
		local_sqrt_value = sqrt_value;
		local_int_Endmembers = VCA_int_Endmembers;
		vector_scale(F, F_divided, local_sqrt_value, local_int_Endmembers);
		local_rc = VCA_rc;
		local_num_Endmembers = VCA_num_Endmembers;
		local_num_Endmembers = VCA_num_Endmembers;
		matrix_mult_vector(projection, F_divided, vTransp, local_rc, local_num_Endmembers, local_num_Endmembers);
		local_rc = VCA_rc;
		tmp_getIndexMax = getIndexMax(vTransp, local_rc);
		index_replaced[i1] = tmp_getIndexMax;
		k = 0;
		local_num_Endmembers = VCA_num_Endmembers;
		while (k <= local_num_Endmembers) {
			tmp_index = index_replaced[i1];
			tmp_projection = projection[tmp_index][k];
			A[k][i1] = tmp_projection;
			k = k + 1;
		}
		z = 0;
		local_num_PC = VCA_num_PC;
		while (z <= local_num_PC - 1) {
			tmp_index0 = index_replaced[i1];
			tmp_matrix_Rp = matrix_Rp[z][tmp_index0];
			endmemberCollection[i1][z] = tmp_matrix_Rp;
			z = z + 1;
		}
		i1 = i1 + 1;
	}
	tmp_get_time0 = get_time();
	tEND_VCA = tmp_get_time0;
	local_tEND_VCA = tEND_VCA;
	local_tINI_VCA = tINI_VCA;
	tDIFF_VCA = local_tEND_VCA - local_tINI_VCA;
	local_tDIFF_VCA = tDIFF_VCA;
	printf("El tiempo total de VCA es: %f\n", local_tDIFF_VCA);
	printf("****Fin VCA****\n");
	vca_done = 1;

	// Update ports indexes

}
static i32 isSchedulable_send() {
	i32 result;
	i32 local_vca_done;
	i32 local_token_sent;
	i32 local_int_Endmembers;

	local_vca_done = vca_done;
	local_token_sent = token_sent;
	local_int_Endmembers = VCA_int_Endmembers;
	result = (local_vca_done == 1 && local_token_sent < local_int_Endmembers);
	return result;
}

static void send() {

	i32 m;
	i32 local_num_PC;
	i32 local_token_sent;
	double tmp_endmemberCollection;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 idx_output;
	float local_output;

	m = 0;
	local_num_PC = VCA_num_PC;
	while (m <= local_num_PC - 1) {
		local_token_sent = token_sent;
		tmp_endmemberCollection = endmemberCollection[local_token_sent][m];
		tmp_double_to_float = double_to_float(tmp_endmemberCollection);
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
		tokens_VCA_out[(index_VCA_out + (idx_output)) % SIZE_VCA_out] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_VCA_out += 25;
	write_end_VCA_out();

}
static void send_aligned() {

	i32 m;
	i32 local_num_PC;
	i32 local_token_sent;
	double tmp_endmemberCollection;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 idx_output;
	float local_output;

	m = 0;
	local_num_PC = VCA_num_PC;
	while (m <= local_num_PC - 1) {
		local_token_sent = token_sent;
		tmp_endmemberCollection = endmemberCollection[local_token_sent][m];
		tmp_double_to_float = double_to_float(tmp_endmemberCollection);
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
		tokens_VCA_out[(index_VCA_out % SIZE_VCA_out) + (idx_output)] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_VCA_out += 25;
	write_end_VCA_out();

}

////////////////////////////////////////////////////////////////////////////////
// Initializes

void VCA_initialize(schedinfo_t *si) {
	int i = 0;
	write_VCA_out();
finished:
	write_end_VCA_out();
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler
void VCA_scheduler(schedinfo_t *si) {
	int i = 0;
	si->ports = 0;

	read_VCA_in();
	write_VCA_out();

	while (1) {
		if (numTokens_VCA_in - index_VCA_in >= 25 && isSchedulable_receive_data()) {
			{
				int isAligned = 1;
				isAligned &= ((index_VCA_in % SIZE_VCA_in) < ((index_VCA_in + 25) % SIZE_VCA_in));
				if (isAligned) {
					receive_data_aligned();
				} else {
					receive_data();
				}
			}
			i++;
		} else if (isSchedulable_VCA_algorithm()) {
			VCA_algorithm();
			i++;
		} else if (isSchedulable_send()) {
			int stop = 0;
			if (25 > SIZE_VCA_out - index_VCA_out + VCA_VCA_out->read_inds[0]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_VCA_out % SIZE_VCA_out) < ((index_VCA_out + 25) % SIZE_VCA_out));
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

	read_end_VCA_in();
	write_end_VCA_out();
}
