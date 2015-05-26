// Source file is "L/hsi_system_Optimized_v1.0/src/LSU.cal"

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
extern actor_t LSU;

////////////////////////////////////////////////////////////////////////////////
// Input FIFOs
extern fifo_float_t *LSU_LSU_in;
extern fifo_float_t *LSU_pixels;

////////////////////////////////////////////////////////////////////////////////
// Input Fifo control variables
static unsigned int index_LSU_in;
static unsigned int numTokens_LSU_in;
#define SIZE_LSU_in SIZE
#define tokens_LSU_in LSU_LSU_in->contents

extern connection_t connection_LSU_LSU_in;
#define rate_LSU_in connection_LSU_LSU_in.rate

static unsigned int index_pixels;
static unsigned int numTokens_pixels;
#define SIZE_pixels SIZE
#define tokens_pixels LSU_pixels->contents

extern connection_t connection_LSU_pixels;
#define rate_pixels connection_LSU_pixels.rate

////////////////////////////////////////////////////////////////////////////////
// Predecessors
extern actor_t VCA;
extern actor_t PCA;

////////////////////////////////////////////////////////////////////////////////
// Output FIFOs
extern fifo_float_t *LSU_LSU_out;

////////////////////////////////////////////////////////////////////////////////
// Output Fifo control variables
static unsigned int index_LSU_out;
static unsigned int numFree_LSU_out;
#define NUM_READERS_LSU_out 1
#define SIZE_LSU_out SIZE
#define tokens_LSU_out LSU_LSU_out->contents

////////////////////////////////////////////////////////////////////////////////
// Successors
extern actor_t Display;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define LSU_rc 10000
#define LSU_num_PC 25
#define LSU_int_Endmembers 20
#define LSU_num_Endmembers 20
static double image_PIXELS[25][10000];
static double image_END[25][20];
static double image_END_Transp[20][25];
static double PRODUCT[20][20];
static double INVERSE[20][20];
static double COMPUT_MATRIX[20][25];
static double ABUNDANCES[20][10000];
static i32 lsu_done = 0;
static i32 received = 0;
static i32 pix_received = 0;
static float output[20];
static float array_env[20];
static i32 token_sent = 0;
static float array_rec[25];
static float array_rec_pixels[25];
static double tINI_LSU;
static double tEND_LSU;
static double tDIFF_LSU;



////////////////////////////////////////////////////////////////////////////////
// Token functions
static void read_LSU_in() {
	index_LSU_in = LSU_LSU_in->read_inds[0];
	numTokens_LSU_in = index_LSU_in + fifo_float_get_num_tokens(LSU_LSU_in, 0);
}

static void read_end_LSU_in() {
	LSU_LSU_in->read_inds[0] = index_LSU_in;
}
static void read_pixels() {
	index_pixels = LSU_pixels->read_inds[1];
	numTokens_pixels = index_pixels + fifo_float_get_num_tokens(LSU_pixels, 1);
}

static void read_end_pixels() {
	LSU_pixels->read_inds[1] = index_pixels;
}

static void write_LSU_out() {
	index_LSU_out = LSU_LSU_out->write_ind;
	numFree_LSU_out = index_LSU_out + fifo_float_get_room(LSU_LSU_out, NUM_READERS_LSU_out, SIZE_LSU_out);
}

static void write_end_LSU_out() {
	LSU_LSU_out->write_ind = index_LSU_out;
}

////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern double float_to_double(float value);
extern double get_time();
extern void transpose(double matrixIn[10000][10000], double matrixTranspose[10000][10000], double rows, double columns);
extern void matrix_mult(double matrix1[10000][10000], double matrix2[10000][10000], double matrixResult[10000][10000], double rows1, double columns1, double rows2, double columns2);
extern void get_inverse(double matrixIn[10000][10000], double matrix_inverse[10000][10000], i32 rows, i32 columns);
extern float double_to_float(double value);


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_receive_data() {
	i32 result;
	i32 local_pix_received;
	i32 local_rc;

	local_pix_received = pix_received;
	local_rc = LSU_rc;
	result = local_pix_received < local_rc;
	return result;
}

static void receive_data() {

	i32 idx_pixels;
	float local_pixels;
	i32 m;
	i32 local_num_PC;
	i32 local_pix_received;
	float tmp_array_rec_pixels;
	double tmp_float_to_double;

	idx_pixels = 0;
	while (idx_pixels < 25) {
		local_pixels = tokens_pixels[(index_pixels + (idx_pixels)) % SIZE_pixels];
		array_rec_pixels[idx_pixels] = local_pixels;
		idx_pixels = idx_pixels + 1;
	}
	m = 0;
	local_num_PC = LSU_num_PC;
	while (m <= local_num_PC - 1) {
		local_pix_received = pix_received;
		tmp_array_rec_pixels = array_rec_pixels[m];
		tmp_float_to_double = float_to_double(tmp_array_rec_pixels);
		image_PIXELS[m][local_pix_received] = tmp_float_to_double;
		m = m + 1;
	}
	local_pix_received = pix_received;
	pix_received = local_pix_received + 1;

	// Update ports indexes
	index_pixels += 25;
	read_end_pixels();

	rate_pixels += 25;
}
static void receive_data_aligned() {

	i32 idx_pixels;
	float local_pixels;
	i32 m;
	i32 local_num_PC;
	i32 local_pix_received;
	float tmp_array_rec_pixels;
	double tmp_float_to_double;

	idx_pixels = 0;
	while (idx_pixels < 25) {
		local_pixels = tokens_pixels[(index_pixels % SIZE_pixels) + (idx_pixels)];
		array_rec_pixels[idx_pixels] = local_pixels;
		idx_pixels = idx_pixels + 1;
	}
	m = 0;
	local_num_PC = LSU_num_PC;
	while (m <= local_num_PC - 1) {
		local_pix_received = pix_received;
		tmp_array_rec_pixels = array_rec_pixels[m];
		tmp_float_to_double = float_to_double(tmp_array_rec_pixels);
		image_PIXELS[m][local_pix_received] = tmp_float_to_double;
		m = m + 1;
	}
	local_pix_received = pix_received;
	pix_received = local_pix_received + 1;

	// Update ports indexes
	index_pixels += 25;
	read_end_pixels();

	rate_pixels += 25;
}
static i32 isSchedulable_receive_endmembers() {
	i32 result;
	i32 local_received;
	i32 local_int_Endmembers;

	local_received = received;
	local_int_Endmembers = LSU_int_Endmembers;
	result = local_received < local_int_Endmembers;
	return result;
}

static void receive_endmembers() {

	i32 idx_LSU_in;
	float local_LSU_in;
	i32 m;
	i32 local_num_PC;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;

	idx_LSU_in = 0;
	while (idx_LSU_in < 25) {
		local_LSU_in = tokens_LSU_in[(index_LSU_in + (idx_LSU_in)) % SIZE_LSU_in];
		array_rec[idx_LSU_in] = local_LSU_in;
		idx_LSU_in = idx_LSU_in + 1;
	}
	m = 0;
	local_num_PC = LSU_num_PC;
	while (m <= local_num_PC - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_END[m][local_received] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;

	// Update ports indexes
	index_LSU_in += 25;
	read_end_LSU_in();

	rate_LSU_in += 25;
}
static void receive_endmembers_aligned() {

	i32 idx_LSU_in;
	float local_LSU_in;
	i32 m;
	i32 local_num_PC;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;

	idx_LSU_in = 0;
	while (idx_LSU_in < 25) {
		local_LSU_in = tokens_LSU_in[(index_LSU_in % SIZE_LSU_in) + (idx_LSU_in)];
		array_rec[idx_LSU_in] = local_LSU_in;
		idx_LSU_in = idx_LSU_in + 1;
	}
	m = 0;
	local_num_PC = LSU_num_PC;
	while (m <= local_num_PC - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_END[m][local_received] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;

	// Update ports indexes
	index_LSU_in += 25;
	read_end_LSU_in();

	rate_LSU_in += 25;
}
static i32 isSchedulable_LSU_algorithm() {
	i32 result;
	i32 local_received;
	i32 local_int_Endmembers;
	i32 local_pix_received;
	i32 local_rc;
	i32 local_lsu_done;

	local_received = received;
	local_int_Endmembers = LSU_int_Endmembers;
	local_pix_received = pix_received;
	local_rc = LSU_rc;
	local_lsu_done = lsu_done;
	result = ((local_received >= local_int_Endmembers && local_pix_received >= local_rc) && local_lsu_done == 0);
	return result;
}

static void LSU_algorithm() {

	double tmp_get_time;
	i32 local_num_PC;
	double local_num_Endmembers;
	i32 local_int_Endmembers;
	i32 local_rc;
	double tmp_get_time0;
	double local_tEND_LSU;
	double local_tINI_LSU;
	double local_tDIFF_LSU;

	printf("****Inicio LSU****\n");
	tmp_get_time = get_time();
	tINI_LSU = tmp_get_time;
	local_num_PC = LSU_num_PC;
	local_num_Endmembers = LSU_num_Endmembers;
	transpose(image_END, image_END_Transp, local_num_PC, local_num_Endmembers);
	local_num_Endmembers = LSU_num_Endmembers;
	local_num_PC = LSU_num_PC;
	local_num_PC = LSU_num_PC;
	local_num_Endmembers = LSU_num_Endmembers;
	matrix_mult(image_END_Transp, image_END, PRODUCT, local_num_Endmembers, local_num_PC, local_num_PC, local_num_Endmembers);
	local_int_Endmembers = LSU_int_Endmembers;
	local_int_Endmembers = LSU_int_Endmembers;
	get_inverse(PRODUCT, INVERSE, local_int_Endmembers, local_int_Endmembers);
	local_num_Endmembers = LSU_num_Endmembers;
	local_num_Endmembers = LSU_num_Endmembers;
	local_num_Endmembers = LSU_num_Endmembers;
	local_num_PC = LSU_num_PC;
	matrix_mult(INVERSE, image_END_Transp, COMPUT_MATRIX, local_num_Endmembers, local_num_Endmembers, local_num_Endmembers, local_num_PC);
	local_num_Endmembers = LSU_num_Endmembers;
	local_num_PC = LSU_num_PC;
	local_num_PC = LSU_num_PC;
	local_rc = LSU_rc;
	matrix_mult(COMPUT_MATRIX, image_PIXELS, ABUNDANCES, local_num_Endmembers, local_num_PC, local_num_PC, local_rc);
	tmp_get_time0 = get_time();
	tEND_LSU = tmp_get_time0;
	local_tEND_LSU = tEND_LSU;
	local_tINI_LSU = tINI_LSU;
	tDIFF_LSU = local_tEND_LSU - local_tINI_LSU;
	local_tDIFF_LSU = tDIFF_LSU;
	printf("El tiempo total de LSU es: %f\n", local_tDIFF_LSU);
	printf("****Fin LSU****\n");
	printf("****Imagen procesada****\n");
	lsu_done = 1;

	// Update ports indexes

}
static i32 isSchedulable_send_abundances() {
	i32 result;
	i32 local_lsu_done;
	i32 local_token_sent;
	i32 local_rc;

	local_lsu_done = lsu_done;
	local_token_sent = token_sent;
	local_rc = LSU_rc;
	result = (local_lsu_done == 1 && local_token_sent < local_rc);
	return result;
}

static void send_abundances() {

	i32 m;
	double local_num_Endmembers;
	i32 local_token_sent;
	double tmp_ABUNDANCES;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 idx_output;
	float local_output;

	m = 0;
	local_num_Endmembers = LSU_num_Endmembers;
	while (m <= local_num_Endmembers - 1) {
		local_token_sent = token_sent;
		tmp_ABUNDANCES = ABUNDANCES[m][local_token_sent];
		tmp_double_to_float = double_to_float(tmp_ABUNDANCES);
		array_env[m] = tmp_double_to_float;
		m = m + 1;
	}
	idx_array_env = 0;
	while (idx_array_env < 20) {
		local_array_env = array_env[idx_array_env];
		output[idx_array_env] = local_array_env;
		idx_array_env = idx_array_env + 1;
	}
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_output = 0;
	while (idx_output < 20) {
		local_output = output[idx_output];
		tokens_LSU_out[(index_LSU_out + (idx_output)) % SIZE_LSU_out] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_LSU_out += 20;
	write_end_LSU_out();

}
static void send_abundances_aligned() {

	i32 m;
	double local_num_Endmembers;
	i32 local_token_sent;
	double tmp_ABUNDANCES;
	float tmp_double_to_float;
	i32 idx_array_env;
	float local_array_env;
	i32 idx_output;
	float local_output;

	m = 0;
	local_num_Endmembers = LSU_num_Endmembers;
	while (m <= local_num_Endmembers - 1) {
		local_token_sent = token_sent;
		tmp_ABUNDANCES = ABUNDANCES[m][local_token_sent];
		tmp_double_to_float = double_to_float(tmp_ABUNDANCES);
		array_env[m] = tmp_double_to_float;
		m = m + 1;
	}
	idx_array_env = 0;
	while (idx_array_env < 20) {
		local_array_env = array_env[idx_array_env];
		output[idx_array_env] = local_array_env;
		idx_array_env = idx_array_env + 1;
	}
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_output = 0;
	while (idx_output < 20) {
		local_output = output[idx_output];
		tokens_LSU_out[(index_LSU_out % SIZE_LSU_out) + (idx_output)] = local_output;
		idx_output = idx_output + 1;
	}

	// Update ports indexes
	index_LSU_out += 20;
	write_end_LSU_out();

}

////////////////////////////////////////////////////////////////////////////////
// Initializes

void LSU_initialize(schedinfo_t *si) {
	int i = 0;
	write_LSU_out();
finished:
	write_end_LSU_out();
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler
void LSU_scheduler(schedinfo_t *si) {
	int i = 0;
	si->ports = 0;

	read_LSU_in();
	read_pixels();
	write_LSU_out();

	while (1) {
		if (numTokens_pixels - index_pixels >= 25 && isSchedulable_receive_data()) {
			{
				int isAligned = 1;
				isAligned &= ((index_pixels % SIZE_pixels) < ((index_pixels + 25) % SIZE_pixels));
				if (isAligned) {
					receive_data_aligned();
				} else {
					receive_data();
				}
			}
			i++;
		} else if (numTokens_LSU_in - index_LSU_in >= 25 && isSchedulable_receive_endmembers()) {
			{
				int isAligned = 1;
				isAligned &= ((index_LSU_in % SIZE_LSU_in) < ((index_LSU_in + 25) % SIZE_LSU_in));
				if (isAligned) {
					receive_endmembers_aligned();
				} else {
					receive_endmembers();
				}
			}
			i++;
		} else if (isSchedulable_LSU_algorithm()) {
			LSU_algorithm();
			i++;
		} else if (isSchedulable_send_abundances()) {
			int stop = 0;
			if (20 > SIZE_LSU_out - index_LSU_out + LSU_LSU_out->read_inds[0]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_LSU_out % SIZE_LSU_out) < ((index_LSU_out + 20) % SIZE_LSU_out));
				if (isAligned) {
					send_abundances_aligned();
				} else {
					send_abundances();
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

	read_end_LSU_in();
	read_end_pixels();
	write_end_LSU_out();
}
