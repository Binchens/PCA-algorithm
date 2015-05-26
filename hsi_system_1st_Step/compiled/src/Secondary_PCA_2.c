// Source file is "L/hsi_system_1st_Step/src/PCA_Secondary_1.cal"

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
extern actor_t Secondary_PCA_2;

////////////////////////////////////////////////////////////////////////////////
// Input FIFOs
extern fifo_float_t *Secondary_PCA_2_PCA_Secondary_in;
extern fifo_i32_t *Secondary_PCA_2_Sche_Pointer;

////////////////////////////////////////////////////////////////////////////////
// Input Fifo control variables
static unsigned int index_PCA_Secondary_in;
static unsigned int numTokens_PCA_Secondary_in;
#define SIZE_PCA_Secondary_in SIZE
#define tokens_PCA_Secondary_in Secondary_PCA_2_PCA_Secondary_in->contents

extern connection_t connection_Secondary_PCA_2_PCA_Secondary_in;
#define rate_PCA_Secondary_in connection_Secondary_PCA_2_PCA_Secondary_in.rate

static unsigned int index_Sche_Pointer;
static unsigned int numTokens_Sche_Pointer;
#define SIZE_Sche_Pointer SIZE
#define tokens_Sche_Pointer Secondary_PCA_2_Sche_Pointer->contents

extern connection_t connection_Secondary_PCA_2_Sche_Pointer;
#define rate_Sche_Pointer connection_Secondary_PCA_2_Sche_Pointer.rate

////////////////////////////////////////////////////////////////////////////////
// Predecessors
extern actor_t Scheduler_PCA;
extern actor_t Scheduler_PCA;

////////////////////////////////////////////////////////////////////////////////
// Output FIFOs
extern fifo_float_t *Secondary_PCA_2_PCA_Secondary_out;
extern fifo_i32_t *Secondary_PCA_2_Sec_Pointer;

////////////////////////////////////////////////////////////////////////////////
// Output Fifo control variables
static unsigned int index_PCA_Secondary_out;
static unsigned int numFree_PCA_Secondary_out;
#define NUM_READERS_PCA_Secondary_out 1
#define SIZE_PCA_Secondary_out SIZE
#define tokens_PCA_Secondary_out Secondary_PCA_2_PCA_Secondary_out->contents

static unsigned int index_Sec_Pointer;
static unsigned int numFree_Sec_Pointer;
#define NUM_READERS_Sec_Pointer 1
#define SIZE_Sec_Pointer SIZE
#define tokens_Sec_Pointer Secondary_PCA_2_Sec_Pointer->contents

////////////////////////////////////////////////////////////////////////////////
// Successors
extern actor_t Constructor_PCA;
extern actor_t Constructor_PCA;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define Secondary_PCA_2_bands4core 55
#define Secondary_PCA_2_rc 10000
static i32 received = 0;
static i32 pointer = 0;
static i32 pointer_out = 0;
static float minusVectorResult[10000];
static float averageVectorResult;
static float Secondary_out[10000];
static float vector_received[10000];
static double tINI;
static double tEND;
static double tDIFF;



////////////////////////////////////////////////////////////////////////////////
// Token functions
static void read_PCA_Secondary_in() {
	index_PCA_Secondary_in = Secondary_PCA_2_PCA_Secondary_in->read_inds[0];
	numTokens_PCA_Secondary_in = index_PCA_Secondary_in + fifo_float_get_num_tokens(Secondary_PCA_2_PCA_Secondary_in, 0);
}

static void read_end_PCA_Secondary_in() {
	Secondary_PCA_2_PCA_Secondary_in->read_inds[0] = index_PCA_Secondary_in;
}
static void read_Sche_Pointer() {
	index_Sche_Pointer = Secondary_PCA_2_Sche_Pointer->read_inds[0];
	numTokens_Sche_Pointer = index_Sche_Pointer + fifo_i32_get_num_tokens(Secondary_PCA_2_Sche_Pointer, 0);
}

static void read_end_Sche_Pointer() {
	Secondary_PCA_2_Sche_Pointer->read_inds[0] = index_Sche_Pointer;
}

static void write_PCA_Secondary_out() {
	index_PCA_Secondary_out = Secondary_PCA_2_PCA_Secondary_out->write_ind;
	numFree_PCA_Secondary_out = index_PCA_Secondary_out + fifo_float_get_room(Secondary_PCA_2_PCA_Secondary_out, NUM_READERS_PCA_Secondary_out, SIZE_PCA_Secondary_out);
}

static void write_end_PCA_Secondary_out() {
	Secondary_PCA_2_PCA_Secondary_out->write_ind = index_PCA_Secondary_out;
}
static void write_Sec_Pointer() {
	index_Sec_Pointer = Secondary_PCA_2_Sec_Pointer->write_ind;
	numFree_Sec_Pointer = index_Sec_Pointer + fifo_i32_get_room(Secondary_PCA_2_Sec_Pointer, NUM_READERS_Sec_Pointer, SIZE_Sec_Pointer);
}

static void write_end_Sec_Pointer() {
	Secondary_PCA_2_Sec_Pointer->write_ind = index_Sec_Pointer;
}

////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern double get_time();
extern float mean_vector_float(float vector[10000], i32 positions);
extern void vector_minus_value_float(float vectorIn[10000], float value, float vectorMinus[10000], i32 positions);


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_receive_scheduler() {
	i32 result;
	i32 local_received;
	i32 local_bands4core;

	local_received = received;
	local_bands4core = Secondary_PCA_2_bands4core;
	result = local_received < local_bands4core;
	return result;
}

static void receive_scheduler() {

	i32 pointer_in;
	i32 local_received;
	double tmp_get_time;
	i32 idx_PCA_Secondary_in;
	float local_PCA_Secondary_in;
	i32 local_rc;
	float tmp_mean_vector_float;
	float local_averageVectorResult;
	i32 idx_minusVectorResult;
	float local_minusVectorResult;
	i32 local_pointer;
	i32 local_bands4core;
	double tmp_get_time0;
	double local_tEND;
	double local_tINI;
	double local_tDIFF;
	i32 idx_Secondary_out;
	float local_Secondary_out;
	i32 local_pointer_out;

	pointer_in = tokens_Sche_Pointer[(index_Sche_Pointer + (0)) % SIZE_Sche_Pointer];
	local_received = received;
	if (local_received == 0) {
		printf("****Inicio Secondary PCA****\n");
		tmp_get_time = get_time();
		tINI = tmp_get_time;
	}
	local_received = received;
	printf("****Se han recivido: %i\n", local_received);
	idx_PCA_Secondary_in = 0;
	while (idx_PCA_Secondary_in < 10000) {
		local_PCA_Secondary_in = tokens_PCA_Secondary_in[(index_PCA_Secondary_in + (idx_PCA_Secondary_in)) % SIZE_PCA_Secondary_in];
		vector_received[idx_PCA_Secondary_in] = local_PCA_Secondary_in;
		idx_PCA_Secondary_in = idx_PCA_Secondary_in + 1;
	}
	local_rc = Secondary_PCA_2_rc;
	tmp_mean_vector_float = mean_vector_float(vector_received, local_rc);
	averageVectorResult = tmp_mean_vector_float;
	local_averageVectorResult = averageVectorResult;
	local_rc = Secondary_PCA_2_rc;
	vector_minus_value_float(vector_received, local_averageVectorResult, minusVectorResult, local_rc);
	idx_minusVectorResult = 0;
	while (idx_minusVectorResult < 10000) {
		local_minusVectorResult = minusVectorResult[idx_minusVectorResult];
		Secondary_out[idx_minusVectorResult] = local_minusVectorResult;
		idx_minusVectorResult = idx_minusVectorResult + 1;
	}
	pointer = pointer_in;
	local_pointer = pointer;
	pointer_out = local_pointer;
	local_received = received;
	received = local_received + 1;
	local_received = received;
	local_bands4core = Secondary_PCA_2_bands4core;
	if (local_received == local_bands4core) {
		tmp_get_time0 = get_time();
		tEND = tmp_get_time0;
		local_tEND = tEND;
		local_tINI = tINI;
		tDIFF = local_tEND - local_tINI;
		local_tDIFF = tDIFF;
		printf("El tiempo del Secondary PCA es: %f\n", local_tDIFF);
		printf("****Fin Secondary PCA****\n");
	}
	idx_Secondary_out = 0;
	while (idx_Secondary_out < 10000) {
		local_Secondary_out = Secondary_out[idx_Secondary_out];
		tokens_PCA_Secondary_out[(index_PCA_Secondary_out + (idx_Secondary_out)) % SIZE_PCA_Secondary_out] = local_Secondary_out;
		idx_Secondary_out = idx_Secondary_out + 1;
	}
	local_pointer_out = pointer_out;
	tokens_Sec_Pointer[(index_Sec_Pointer + (0)) % SIZE_Sec_Pointer] = local_pointer_out;

	// Update ports indexes
	index_PCA_Secondary_in += 10000;
	read_end_PCA_Secondary_in();
	index_Sche_Pointer += 1;
	index_PCA_Secondary_out += 10000;
	write_end_PCA_Secondary_out();
	index_Sec_Pointer += 1;

	rate_PCA_Secondary_in += 10000;
	rate_Sche_Pointer += 1;
}
static void receive_scheduler_aligned() {

	i32 pointer_in;
	i32 local_received;
	double tmp_get_time;
	i32 idx_PCA_Secondary_in;
	float local_PCA_Secondary_in;
	i32 local_rc;
	float tmp_mean_vector_float;
	float local_averageVectorResult;
	i32 idx_minusVectorResult;
	float local_minusVectorResult;
	i32 local_pointer;
	i32 local_bands4core;
	double tmp_get_time0;
	double local_tEND;
	double local_tINI;
	double local_tDIFF;
	i32 idx_Secondary_out;
	float local_Secondary_out;
	i32 local_pointer_out;

	pointer_in = tokens_Sche_Pointer[(index_Sche_Pointer + (0)) % SIZE_Sche_Pointer];
	local_received = received;
	if (local_received == 0) {
		printf("****Inicio Secondary PCA****\n");
		tmp_get_time = get_time();
		tINI = tmp_get_time;
	}
	local_received = received;
	printf("****Se han recivido: %i\n", local_received);
	idx_PCA_Secondary_in = 0;
	while (idx_PCA_Secondary_in < 10000) {
		local_PCA_Secondary_in = tokens_PCA_Secondary_in[(index_PCA_Secondary_in % SIZE_PCA_Secondary_in) + (idx_PCA_Secondary_in)];
		vector_received[idx_PCA_Secondary_in] = local_PCA_Secondary_in;
		idx_PCA_Secondary_in = idx_PCA_Secondary_in + 1;
	}
	local_rc = Secondary_PCA_2_rc;
	tmp_mean_vector_float = mean_vector_float(vector_received, local_rc);
	averageVectorResult = tmp_mean_vector_float;
	local_averageVectorResult = averageVectorResult;
	local_rc = Secondary_PCA_2_rc;
	vector_minus_value_float(vector_received, local_averageVectorResult, minusVectorResult, local_rc);
	idx_minusVectorResult = 0;
	while (idx_minusVectorResult < 10000) {
		local_minusVectorResult = minusVectorResult[idx_minusVectorResult];
		Secondary_out[idx_minusVectorResult] = local_minusVectorResult;
		idx_minusVectorResult = idx_minusVectorResult + 1;
	}
	pointer = pointer_in;
	local_pointer = pointer;
	pointer_out = local_pointer;
	local_received = received;
	received = local_received + 1;
	local_received = received;
	local_bands4core = Secondary_PCA_2_bands4core;
	if (local_received == local_bands4core) {
		tmp_get_time0 = get_time();
		tEND = tmp_get_time0;
		local_tEND = tEND;
		local_tINI = tINI;
		tDIFF = local_tEND - local_tINI;
		local_tDIFF = tDIFF;
		printf("El tiempo del Secondary PCA es: %f\n", local_tDIFF);
		printf("****Fin Secondary PCA****\n");
	}
	idx_Secondary_out = 0;
	while (idx_Secondary_out < 10000) {
		local_Secondary_out = Secondary_out[idx_Secondary_out];
		tokens_PCA_Secondary_out[(index_PCA_Secondary_out % SIZE_PCA_Secondary_out) + (idx_Secondary_out)] = local_Secondary_out;
		idx_Secondary_out = idx_Secondary_out + 1;
	}
	local_pointer_out = pointer_out;
	tokens_Sec_Pointer[(index_Sec_Pointer + (0)) % SIZE_Sec_Pointer] = local_pointer_out;

	// Update ports indexes
	index_PCA_Secondary_in += 10000;
	read_end_PCA_Secondary_in();
	index_Sche_Pointer += 1;
	index_PCA_Secondary_out += 10000;
	write_end_PCA_Secondary_out();
	index_Sec_Pointer += 1;

	rate_PCA_Secondary_in += 10000;
	rate_Sche_Pointer += 1;
}

////////////////////////////////////////////////////////////////////////////////
// Initializes

void Secondary_PCA_2_initialize(schedinfo_t *si) {
	int i = 0;
	write_PCA_Secondary_out();
	write_Sec_Pointer();
finished:
	write_end_PCA_Secondary_out();
	write_end_Sec_Pointer();
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler
void Secondary_PCA_2_scheduler(schedinfo_t *si) {
	int i = 0;
	si->ports = 0;

	read_PCA_Secondary_in();
	read_Sche_Pointer();
	write_PCA_Secondary_out();
	write_Sec_Pointer();

	while (1) {
		if (numTokens_PCA_Secondary_in - index_PCA_Secondary_in >= 10000 && numTokens_Sche_Pointer - index_Sche_Pointer >= 1 && isSchedulable_receive_scheduler()) {
			int stop = 0;
			if (10000 > SIZE_PCA_Secondary_out - index_PCA_Secondary_out + Secondary_PCA_2_PCA_Secondary_out->read_inds[0]) {
				stop = 1;
			}
			if (1 > SIZE_Sec_Pointer - index_Sec_Pointer + Secondary_PCA_2_Sec_Pointer->read_inds[0]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_PCA_Secondary_in % SIZE_PCA_Secondary_in) < ((index_PCA_Secondary_in + 10000) % SIZE_PCA_Secondary_in));
				isAligned &= ((index_PCA_Secondary_out % SIZE_PCA_Secondary_out) < ((index_PCA_Secondary_out + 10000) % SIZE_PCA_Secondary_out));
				if (isAligned) {
					receive_scheduler_aligned();
				} else {
					receive_scheduler();
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

	read_end_PCA_Secondary_in();
	read_end_Sche_Pointer();
	write_end_PCA_Secondary_out();
	write_end_Sec_Pointer();
}
