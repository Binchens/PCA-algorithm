// Source file is "L/hsi_system_1st_Step/src/PCA_Scheduler.cal"

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
extern actor_t Scheduler_PCA;

////////////////////////////////////////////////////////////////////////////////
// Input FIFOs
extern fifo_float_t *Scheduler_PCA_Scheduler_In;
extern fifo_i32_t *Scheduler_PCA_EOF;

////////////////////////////////////////////////////////////////////////////////
// Input Fifo control variables
static unsigned int index_Scheduler_In;
static unsigned int numTokens_Scheduler_In;
#define SIZE_Scheduler_In SIZE
#define tokens_Scheduler_In Scheduler_PCA_Scheduler_In->contents

extern connection_t connection_Scheduler_PCA_Scheduler_In;
#define rate_Scheduler_In connection_Scheduler_PCA_Scheduler_In.rate

static unsigned int index_EOF;
static unsigned int numTokens_EOF;
#define SIZE_EOF SIZE
#define tokens_EOF Scheduler_PCA_EOF->contents

extern connection_t connection_Scheduler_PCA_EOF;
#define rate_EOF connection_Scheduler_PCA_EOF.rate

////////////////////////////////////////////////////////////////////////////////
// Predecessors
extern actor_t Source;
extern actor_t Source;

////////////////////////////////////////////////////////////////////////////////
// Output FIFOs
extern fifo_float_t *Scheduler_PCA_Secondary_Out0;
extern fifo_i32_t *Scheduler_PCA_Sche_Pointer0;
extern fifo_float_t *Scheduler_PCA_Secondary_Out1;
extern fifo_i32_t *Scheduler_PCA_Sche_Pointer1;
extern fifo_float_t *Scheduler_PCA_Secondary_Out2;
extern fifo_i32_t *Scheduler_PCA_Sche_Pointer2;
extern fifo_float_t *Scheduler_PCA_Secondary_Out3;
extern fifo_i32_t *Scheduler_PCA_Sche_Pointer3;

////////////////////////////////////////////////////////////////////////////////
// Output Fifo control variables
static unsigned int index_Secondary_Out0;
static unsigned int numFree_Secondary_Out0;
#define NUM_READERS_Secondary_Out0 1
#define SIZE_Secondary_Out0 SIZE
#define tokens_Secondary_Out0 Scheduler_PCA_Secondary_Out0->contents

static unsigned int index_Sche_Pointer0;
static unsigned int numFree_Sche_Pointer0;
#define NUM_READERS_Sche_Pointer0 1
#define SIZE_Sche_Pointer0 SIZE
#define tokens_Sche_Pointer0 Scheduler_PCA_Sche_Pointer0->contents

static unsigned int index_Secondary_Out1;
static unsigned int numFree_Secondary_Out1;
#define NUM_READERS_Secondary_Out1 1
#define SIZE_Secondary_Out1 SIZE
#define tokens_Secondary_Out1 Scheduler_PCA_Secondary_Out1->contents

static unsigned int index_Sche_Pointer1;
static unsigned int numFree_Sche_Pointer1;
#define NUM_READERS_Sche_Pointer1 1
#define SIZE_Sche_Pointer1 SIZE
#define tokens_Sche_Pointer1 Scheduler_PCA_Sche_Pointer1->contents

static unsigned int index_Secondary_Out2;
static unsigned int numFree_Secondary_Out2;
#define NUM_READERS_Secondary_Out2 1
#define SIZE_Secondary_Out2 SIZE
#define tokens_Secondary_Out2 Scheduler_PCA_Secondary_Out2->contents

static unsigned int index_Sche_Pointer2;
static unsigned int numFree_Sche_Pointer2;
#define NUM_READERS_Sche_Pointer2 1
#define SIZE_Sche_Pointer2 SIZE
#define tokens_Sche_Pointer2 Scheduler_PCA_Sche_Pointer2->contents

static unsigned int index_Secondary_Out3;
static unsigned int numFree_Secondary_Out3;
#define NUM_READERS_Secondary_Out3 1
#define SIZE_Secondary_Out3 SIZE
#define tokens_Secondary_Out3 Scheduler_PCA_Secondary_Out3->contents

static unsigned int index_Sche_Pointer3;
static unsigned int numFree_Sche_Pointer3;
#define NUM_READERS_Sche_Pointer3 1
#define SIZE_Sche_Pointer3 SIZE
#define tokens_Sche_Pointer3 Scheduler_PCA_Sche_Pointer3->contents

////////////////////////////////////////////////////////////////////////////////
// Successors
extern actor_t Secondary_PCA_0;
extern actor_t Secondary_PCA_0;
extern actor_t Secondary_PCA_1;
extern actor_t Secondary_PCA_1;
extern actor_t Secondary_PCA_2;
extern actor_t Secondary_PCA_2;
extern actor_t Secondary_PCA_3;
extern actor_t Secondary_PCA_3;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define Scheduler_PCA_rc 10000
#define Scheduler_PCA_bands 221
#define Scheduler_PCA_band4core1 55
#define Scheduler_PCA_band4core2 110
#define Scheduler_PCA_band4core3 165
static i32 pointer0 = 0;
static i32 pointer1 = 0;
static i32 pointer2 = 0;
static i32 pointer3 = 0;
static i32 received = 0;
static i32 token_sent = 0;
static float image_IN[10000][221];
static float array_rec[221];
static float averageVector[10000];
static float Sche_out0[10000];
static float Sche_out1[10000];
static float Sche_out2[10000];
static float Sche_out3[10000];
static double tINI;
static double tEND;
static double tDIFF;



////////////////////////////////////////////////////////////////////////////////
// Token functions
static void read_Scheduler_In() {
	index_Scheduler_In = Scheduler_PCA_Scheduler_In->read_inds[1];
	numTokens_Scheduler_In = index_Scheduler_In + fifo_float_get_num_tokens(Scheduler_PCA_Scheduler_In, 1);
}

static void read_end_Scheduler_In() {
	Scheduler_PCA_Scheduler_In->read_inds[1] = index_Scheduler_In;
}
static void read_EOF() {
	index_EOF = Scheduler_PCA_EOF->read_inds[0];
	numTokens_EOF = index_EOF + fifo_i32_get_num_tokens(Scheduler_PCA_EOF, 0);
}

static void read_end_EOF() {
	Scheduler_PCA_EOF->read_inds[0] = index_EOF;
}

static void write_Secondary_Out0() {
	index_Secondary_Out0 = Scheduler_PCA_Secondary_Out0->write_ind;
	numFree_Secondary_Out0 = index_Secondary_Out0 + fifo_float_get_room(Scheduler_PCA_Secondary_Out0, NUM_READERS_Secondary_Out0, SIZE_Secondary_Out0);
}

static void write_end_Secondary_Out0() {
	Scheduler_PCA_Secondary_Out0->write_ind = index_Secondary_Out0;
}
static void write_Sche_Pointer0() {
	index_Sche_Pointer0 = Scheduler_PCA_Sche_Pointer0->write_ind;
	numFree_Sche_Pointer0 = index_Sche_Pointer0 + fifo_i32_get_room(Scheduler_PCA_Sche_Pointer0, NUM_READERS_Sche_Pointer0, SIZE_Sche_Pointer0);
}

static void write_end_Sche_Pointer0() {
	Scheduler_PCA_Sche_Pointer0->write_ind = index_Sche_Pointer0;
}
static void write_Secondary_Out1() {
	index_Secondary_Out1 = Scheduler_PCA_Secondary_Out1->write_ind;
	numFree_Secondary_Out1 = index_Secondary_Out1 + fifo_float_get_room(Scheduler_PCA_Secondary_Out1, NUM_READERS_Secondary_Out1, SIZE_Secondary_Out1);
}

static void write_end_Secondary_Out1() {
	Scheduler_PCA_Secondary_Out1->write_ind = index_Secondary_Out1;
}
static void write_Sche_Pointer1() {
	index_Sche_Pointer1 = Scheduler_PCA_Sche_Pointer1->write_ind;
	numFree_Sche_Pointer1 = index_Sche_Pointer1 + fifo_i32_get_room(Scheduler_PCA_Sche_Pointer1, NUM_READERS_Sche_Pointer1, SIZE_Sche_Pointer1);
}

static void write_end_Sche_Pointer1() {
	Scheduler_PCA_Sche_Pointer1->write_ind = index_Sche_Pointer1;
}
static void write_Secondary_Out2() {
	index_Secondary_Out2 = Scheduler_PCA_Secondary_Out2->write_ind;
	numFree_Secondary_Out2 = index_Secondary_Out2 + fifo_float_get_room(Scheduler_PCA_Secondary_Out2, NUM_READERS_Secondary_Out2, SIZE_Secondary_Out2);
}

static void write_end_Secondary_Out2() {
	Scheduler_PCA_Secondary_Out2->write_ind = index_Secondary_Out2;
}
static void write_Sche_Pointer2() {
	index_Sche_Pointer2 = Scheduler_PCA_Sche_Pointer2->write_ind;
	numFree_Sche_Pointer2 = index_Sche_Pointer2 + fifo_i32_get_room(Scheduler_PCA_Sche_Pointer2, NUM_READERS_Sche_Pointer2, SIZE_Sche_Pointer2);
}

static void write_end_Sche_Pointer2() {
	Scheduler_PCA_Sche_Pointer2->write_ind = index_Sche_Pointer2;
}
static void write_Secondary_Out3() {
	index_Secondary_Out3 = Scheduler_PCA_Secondary_Out3->write_ind;
	numFree_Secondary_Out3 = index_Secondary_Out3 + fifo_float_get_room(Scheduler_PCA_Secondary_Out3, NUM_READERS_Secondary_Out3, SIZE_Secondary_Out3);
}

static void write_end_Secondary_Out3() {
	Scheduler_PCA_Secondary_Out3->write_ind = index_Secondary_Out3;
}
static void write_Sche_Pointer3() {
	index_Sche_Pointer3 = Scheduler_PCA_Sche_Pointer3->write_ind;
	numFree_Sche_Pointer3 = index_Sche_Pointer3 + fifo_i32_get_room(Scheduler_PCA_Sche_Pointer3, NUM_READERS_Sche_Pointer3, SIZE_Sche_Pointer3);
}

static void write_end_Sche_Pointer3() {
	Scheduler_PCA_Sche_Pointer3->write_ind = index_Sche_Pointer3;
}

////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern double get_time();
extern void matrix_get_column_float(float matrix1[10000][10000], float vector[10000], i32 rows1, i32 columns1, i32 column);


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_receive_data_source() {
	i32 result;
	i32 local_received;
	i32 local_rc;

	local_received = received;
	local_rc = Scheduler_PCA_rc;
	result = local_received < local_rc;
	return result;
}

static void receive_data_source() {

	i32 endOfFile;
	i32 idx_Scheduler_In;
	float local_Scheduler_In;
	i32 m;
	i32 local_bands;
	i32 local_received;
	float tmp_array_rec;

	endOfFile = tokens_EOF[(index_EOF + (0)) % SIZE_EOF];
	if (endOfFile == 1) {
		printf("****No hay puto fichero de mis cojones****\n");
	} else {
		idx_Scheduler_In = 0;
		while (idx_Scheduler_In < 221) {
			local_Scheduler_In = tokens_Scheduler_In[(index_Scheduler_In + (idx_Scheduler_In)) % SIZE_Scheduler_In];
			array_rec[idx_Scheduler_In] = local_Scheduler_In;
			idx_Scheduler_In = idx_Scheduler_In + 1;
		}
		m = 0;
		local_bands = Scheduler_PCA_bands;
		while (m <= local_bands - 1) {
			local_received = received;
			tmp_array_rec = array_rec[m];
			image_IN[local_received][m] = tmp_array_rec;
			m = m + 1;
		}
		local_received = received;
		received = local_received + 1;
	}

	// Update ports indexes
	index_Scheduler_In += 221;
	read_end_Scheduler_In();
	index_EOF += 1;

	rate_Scheduler_In += 221;
	rate_EOF += 1;
}
static void receive_data_source_aligned() {

	i32 endOfFile;
	i32 idx_Scheduler_In;
	float local_Scheduler_In;
	i32 m;
	i32 local_bands;
	i32 local_received;
	float tmp_array_rec;

	endOfFile = tokens_EOF[(index_EOF + (0)) % SIZE_EOF];
	if (endOfFile == 1) {
		printf("****No hay puto fichero de mis cojones****\n");
	} else {
		idx_Scheduler_In = 0;
		while (idx_Scheduler_In < 221) {
			local_Scheduler_In = tokens_Scheduler_In[(index_Scheduler_In % SIZE_Scheduler_In) + (idx_Scheduler_In)];
			array_rec[idx_Scheduler_In] = local_Scheduler_In;
			idx_Scheduler_In = idx_Scheduler_In + 1;
		}
		m = 0;
		local_bands = Scheduler_PCA_bands;
		while (m <= local_bands - 1) {
			local_received = received;
			tmp_array_rec = array_rec[m];
			image_IN[local_received][m] = tmp_array_rec;
			m = m + 1;
		}
		local_received = received;
		received = local_received + 1;
	}

	// Update ports indexes
	index_Scheduler_In += 221;
	read_end_Scheduler_In();
	index_EOF += 1;

	rate_Scheduler_In += 221;
	rate_EOF += 1;
}
static i32 isSchedulable_Send_Sche0() {
	i32 result;
	i32 local_token_sent;
	i32 local_band4core1;
	i32 local_received;
	i32 local_rc;

	local_token_sent = token_sent;
	local_band4core1 = Scheduler_PCA_band4core1;
	local_received = received;
	local_rc = Scheduler_PCA_rc;
	result = (local_token_sent < local_band4core1 && local_received >= local_rc);
	return result;
}

static void Send_Sche0() {

	i32 local_token_sent;
	double tmp_get_time;
	i32 local_rc;
	i32 local_bands;
	i32 idx_averageVector;
	float local_averageVector;
	i32 idx_Sche_out0;
	float local_Sche_out0;
	i32 local_pointer0;

	local_token_sent = token_sent;
	if (local_token_sent == 0) {
		printf("****Inicio Scheduler PCA****\n");
		tmp_get_time = get_time();
		tINI = tmp_get_time;
	}
	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out0[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer0 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_Sche_out0 = 0;
	while (idx_Sche_out0 < 10000) {
		local_Sche_out0 = Sche_out0[idx_Sche_out0];
		tokens_Secondary_Out0[(index_Secondary_Out0 + (idx_Sche_out0)) % SIZE_Secondary_Out0] = local_Sche_out0;
		idx_Sche_out0 = idx_Sche_out0 + 1;
	}
	local_pointer0 = pointer0;
	tokens_Sche_Pointer0[(index_Sche_Pointer0 + (0)) % SIZE_Sche_Pointer0] = local_pointer0;

	// Update ports indexes
	index_Secondary_Out0 += 10000;
	write_end_Secondary_Out0();
	index_Sche_Pointer0 += 1;

}
static void Send_Sche0_aligned() {

	i32 local_token_sent;
	double tmp_get_time;
	i32 local_rc;
	i32 local_bands;
	i32 idx_averageVector;
	float local_averageVector;
	i32 idx_Sche_out0;
	float local_Sche_out0;
	i32 local_pointer0;

	local_token_sent = token_sent;
	if (local_token_sent == 0) {
		printf("****Inicio Scheduler PCA****\n");
		tmp_get_time = get_time();
		tINI = tmp_get_time;
	}
	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out0[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer0 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_Sche_out0 = 0;
	while (idx_Sche_out0 < 10000) {
		local_Sche_out0 = Sche_out0[idx_Sche_out0];
		tokens_Secondary_Out0[(index_Secondary_Out0 % SIZE_Secondary_Out0) + (idx_Sche_out0)] = local_Sche_out0;
		idx_Sche_out0 = idx_Sche_out0 + 1;
	}
	local_pointer0 = pointer0;
	tokens_Sche_Pointer0[(index_Sche_Pointer0 + (0)) % SIZE_Sche_Pointer0] = local_pointer0;

	// Update ports indexes
	index_Secondary_Out0 += 10000;
	write_end_Secondary_Out0();
	index_Sche_Pointer0 += 1;

}
static i32 isSchedulable_Send_Sche1() {
	i32 result;
	i32 local_token_sent;
	i32 local_band4core2;
	i32 local_band4core1;

	local_token_sent = token_sent;
	local_band4core2 = Scheduler_PCA_band4core2;
	local_token_sent = token_sent;
	local_band4core1 = Scheduler_PCA_band4core1;
	result = (local_token_sent < local_band4core2 && local_token_sent >= local_band4core1);
	return result;
}

static void Send_Sche1() {

	i32 local_rc;
	i32 local_bands;
	i32 local_token_sent;
	i32 idx_averageVector;
	float local_averageVector;
	i32 idx_Sche_out1;
	float local_Sche_out1;
	i32 local_pointer1;

	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out1[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer1 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_Sche_out1 = 0;
	while (idx_Sche_out1 < 10000) {
		local_Sche_out1 = Sche_out1[idx_Sche_out1];
		tokens_Secondary_Out1[(index_Secondary_Out1 + (idx_Sche_out1)) % SIZE_Secondary_Out1] = local_Sche_out1;
		idx_Sche_out1 = idx_Sche_out1 + 1;
	}
	local_pointer1 = pointer1;
	tokens_Sche_Pointer1[(index_Sche_Pointer1 + (0)) % SIZE_Sche_Pointer1] = local_pointer1;

	// Update ports indexes
	index_Secondary_Out1 += 10000;
	write_end_Secondary_Out1();
	index_Sche_Pointer1 += 1;

}
static void Send_Sche1_aligned() {

	i32 local_rc;
	i32 local_bands;
	i32 local_token_sent;
	i32 idx_averageVector;
	float local_averageVector;
	i32 idx_Sche_out1;
	float local_Sche_out1;
	i32 local_pointer1;

	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out1[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer1 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_Sche_out1 = 0;
	while (idx_Sche_out1 < 10000) {
		local_Sche_out1 = Sche_out1[idx_Sche_out1];
		tokens_Secondary_Out1[(index_Secondary_Out1 % SIZE_Secondary_Out1) + (idx_Sche_out1)] = local_Sche_out1;
		idx_Sche_out1 = idx_Sche_out1 + 1;
	}
	local_pointer1 = pointer1;
	tokens_Sche_Pointer1[(index_Sche_Pointer1 + (0)) % SIZE_Sche_Pointer1] = local_pointer1;

	// Update ports indexes
	index_Secondary_Out1 += 10000;
	write_end_Secondary_Out1();
	index_Sche_Pointer1 += 1;

}
static i32 isSchedulable_Send_Sche2() {
	i32 result;
	i32 local_token_sent;
	i32 local_band4core3;
	i32 local_band4core2;

	local_token_sent = token_sent;
	local_band4core3 = Scheduler_PCA_band4core3;
	local_token_sent = token_sent;
	local_band4core2 = Scheduler_PCA_band4core2;
	result = (local_token_sent < local_band4core3 && local_token_sent >= local_band4core2);
	return result;
}

static void Send_Sche2() {

	i32 local_rc;
	i32 local_bands;
	i32 local_token_sent;
	i32 idx_averageVector;
	float local_averageVector;
	i32 idx_Sche_out2;
	float local_Sche_out2;
	i32 local_pointer2;

	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out2[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer2 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_Sche_out2 = 0;
	while (idx_Sche_out2 < 10000) {
		local_Sche_out2 = Sche_out2[idx_Sche_out2];
		tokens_Secondary_Out2[(index_Secondary_Out2 + (idx_Sche_out2)) % SIZE_Secondary_Out2] = local_Sche_out2;
		idx_Sche_out2 = idx_Sche_out2 + 1;
	}
	local_pointer2 = pointer2;
	tokens_Sche_Pointer2[(index_Sche_Pointer2 + (0)) % SIZE_Sche_Pointer2] = local_pointer2;

	// Update ports indexes
	index_Secondary_Out2 += 10000;
	write_end_Secondary_Out2();
	index_Sche_Pointer2 += 1;

}
static void Send_Sche2_aligned() {

	i32 local_rc;
	i32 local_bands;
	i32 local_token_sent;
	i32 idx_averageVector;
	float local_averageVector;
	i32 idx_Sche_out2;
	float local_Sche_out2;
	i32 local_pointer2;

	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out2[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer2 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	idx_Sche_out2 = 0;
	while (idx_Sche_out2 < 10000) {
		local_Sche_out2 = Sche_out2[idx_Sche_out2];
		tokens_Secondary_Out2[(index_Secondary_Out2 % SIZE_Secondary_Out2) + (idx_Sche_out2)] = local_Sche_out2;
		idx_Sche_out2 = idx_Sche_out2 + 1;
	}
	local_pointer2 = pointer2;
	tokens_Sche_Pointer2[(index_Sche_Pointer2 + (0)) % SIZE_Sche_Pointer2] = local_pointer2;

	// Update ports indexes
	index_Secondary_Out2 += 10000;
	write_end_Secondary_Out2();
	index_Sche_Pointer2 += 1;

}
static i32 isSchedulable_Send_Sche3() {
	i32 result;
	i32 local_token_sent;
	i32 local_bands;
	i32 local_band4core3;

	local_token_sent = token_sent;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	local_band4core3 = Scheduler_PCA_band4core3;
	result = (local_token_sent < local_bands && local_token_sent >= local_band4core3);
	return result;
}

static void Send_Sche3() {

	i32 local_rc;
	i32 local_bands;
	i32 local_token_sent;
	i32 idx_averageVector;
	float local_averageVector;
	double tmp_get_time;
	double local_tEND;
	double local_tINI;
	double local_tDIFF;
	i32 idx_Sche_out3;
	float local_Sche_out3;
	i32 local_pointer3;

	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out3[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer3 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	local_token_sent = token_sent;
	local_bands = Scheduler_PCA_bands;
	if (local_token_sent == local_bands) {
		tmp_get_time = get_time();
		tEND = tmp_get_time;
		local_tEND = tEND;
		local_tINI = tINI;
		tDIFF = local_tEND - local_tINI;
		local_tDIFF = tDIFF;
		printf("El tiempo Scheduler PCA es: %f\n", local_tDIFF);
		printf("****Fin Scheduler PCA****\n");
	}
	idx_Sche_out3 = 0;
	while (idx_Sche_out3 < 10000) {
		local_Sche_out3 = Sche_out3[idx_Sche_out3];
		tokens_Secondary_Out3[(index_Secondary_Out3 + (idx_Sche_out3)) % SIZE_Secondary_Out3] = local_Sche_out3;
		idx_Sche_out3 = idx_Sche_out3 + 1;
	}
	local_pointer3 = pointer3;
	tokens_Sche_Pointer3[(index_Sche_Pointer3 + (0)) % SIZE_Sche_Pointer3] = local_pointer3;

	// Update ports indexes
	index_Secondary_Out3 += 10000;
	write_end_Secondary_Out3();
	index_Sche_Pointer3 += 1;

}
static void Send_Sche3_aligned() {

	i32 local_rc;
	i32 local_bands;
	i32 local_token_sent;
	i32 idx_averageVector;
	float local_averageVector;
	double tmp_get_time;
	double local_tEND;
	double local_tINI;
	double local_tDIFF;
	i32 idx_Sche_out3;
	float local_Sche_out3;
	i32 local_pointer3;

	local_rc = Scheduler_PCA_rc;
	local_bands = Scheduler_PCA_bands;
	local_token_sent = token_sent;
	matrix_get_column_float(image_IN, averageVector, local_rc, local_bands, local_token_sent);
	idx_averageVector = 0;
	while (idx_averageVector < 10000) {
		local_averageVector = averageVector[idx_averageVector];
		Sche_out3[idx_averageVector] = local_averageVector;
		idx_averageVector = idx_averageVector + 1;
	}
	local_token_sent = token_sent;
	pointer3 = local_token_sent;
	local_token_sent = token_sent;
	token_sent = local_token_sent + 1;
	local_token_sent = token_sent;
	local_bands = Scheduler_PCA_bands;
	if (local_token_sent == local_bands) {
		tmp_get_time = get_time();
		tEND = tmp_get_time;
		local_tEND = tEND;
		local_tINI = tINI;
		tDIFF = local_tEND - local_tINI;
		local_tDIFF = tDIFF;
		printf("El tiempo Scheduler PCA es: %f\n", local_tDIFF);
		printf("****Fin Scheduler PCA****\n");
	}
	idx_Sche_out3 = 0;
	while (idx_Sche_out3 < 10000) {
		local_Sche_out3 = Sche_out3[idx_Sche_out3];
		tokens_Secondary_Out3[(index_Secondary_Out3 % SIZE_Secondary_Out3) + (idx_Sche_out3)] = local_Sche_out3;
		idx_Sche_out3 = idx_Sche_out3 + 1;
	}
	local_pointer3 = pointer3;
	tokens_Sche_Pointer3[(index_Sche_Pointer3 + (0)) % SIZE_Sche_Pointer3] = local_pointer3;

	// Update ports indexes
	index_Secondary_Out3 += 10000;
	write_end_Secondary_Out3();
	index_Sche_Pointer3 += 1;

}

////////////////////////////////////////////////////////////////////////////////
// Initializes

void Scheduler_PCA_initialize(schedinfo_t *si) {
	int i = 0;
	write_Secondary_Out0();
	write_Sche_Pointer0();
	write_Secondary_Out1();
	write_Sche_Pointer1();
	write_Secondary_Out2();
	write_Sche_Pointer2();
	write_Secondary_Out3();
	write_Sche_Pointer3();
finished:
	write_end_Secondary_Out0();
	write_end_Sche_Pointer0();
	write_end_Secondary_Out1();
	write_end_Sche_Pointer1();
	write_end_Secondary_Out2();
	write_end_Sche_Pointer2();
	write_end_Secondary_Out3();
	write_end_Sche_Pointer3();
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler
void Scheduler_PCA_scheduler(schedinfo_t *si) {
	int i = 0;
	si->ports = 0;

	read_Scheduler_In();
	read_EOF();
	write_Secondary_Out0();
	write_Sche_Pointer0();
	write_Secondary_Out1();
	write_Sche_Pointer1();
	write_Secondary_Out2();
	write_Sche_Pointer2();
	write_Secondary_Out3();
	write_Sche_Pointer3();

	while (1) {
		if (numTokens_Scheduler_In - index_Scheduler_In >= 221 && numTokens_EOF - index_EOF >= 1 && isSchedulable_receive_data_source()) {
			{
				int isAligned = 1;
				isAligned &= ((index_Scheduler_In % SIZE_Scheduler_In) < ((index_Scheduler_In + 221) % SIZE_Scheduler_In));
				if (isAligned) {
					receive_data_source_aligned();
				} else {
					receive_data_source();
				}
			}
			i++;
		} else if (isSchedulable_Send_Sche0()) {
			int stop = 0;
			if (10000 > SIZE_Secondary_Out0 - index_Secondary_Out0 + Scheduler_PCA_Secondary_Out0->read_inds[0]) {
				stop = 1;
			}
			if (1 > SIZE_Sche_Pointer0 - index_Sche_Pointer0 + Scheduler_PCA_Sche_Pointer0->read_inds[0]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_Secondary_Out0 % SIZE_Secondary_Out0) < ((index_Secondary_Out0 + 10000) % SIZE_Secondary_Out0));
				if (isAligned) {
					Send_Sche0_aligned();
				} else {
					Send_Sche0();
				}
			}
			i++;
		} else if (isSchedulable_Send_Sche1()) {
			int stop = 0;
			if (10000 > SIZE_Secondary_Out1 - index_Secondary_Out1 + Scheduler_PCA_Secondary_Out1->read_inds[0]) {
				stop = 1;
			}
			if (1 > SIZE_Sche_Pointer1 - index_Sche_Pointer1 + Scheduler_PCA_Sche_Pointer1->read_inds[0]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_Secondary_Out1 % SIZE_Secondary_Out1) < ((index_Secondary_Out1 + 10000) % SIZE_Secondary_Out1));
				if (isAligned) {
					Send_Sche1_aligned();
				} else {
					Send_Sche1();
				}
			}
			i++;
		} else if (isSchedulable_Send_Sche2()) {
			int stop = 0;
			if (10000 > SIZE_Secondary_Out2 - index_Secondary_Out2 + Scheduler_PCA_Secondary_Out2->read_inds[0]) {
				stop = 1;
			}
			if (1 > SIZE_Sche_Pointer2 - index_Sche_Pointer2 + Scheduler_PCA_Sche_Pointer2->read_inds[0]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_Secondary_Out2 % SIZE_Secondary_Out2) < ((index_Secondary_Out2 + 10000) % SIZE_Secondary_Out2));
				if (isAligned) {
					Send_Sche2_aligned();
				} else {
					Send_Sche2();
				}
			}
			i++;
		} else if (isSchedulable_Send_Sche3()) {
			int stop = 0;
			if (10000 > SIZE_Secondary_Out3 - index_Secondary_Out3 + Scheduler_PCA_Secondary_Out3->read_inds[0]) {
				stop = 1;
			}
			if (1 > SIZE_Sche_Pointer3 - index_Sche_Pointer3 + Scheduler_PCA_Sche_Pointer3->read_inds[0]) {
				stop = 1;
			}
			if (stop != 0) {
				si->num_firings = i;
				si->reason = full;
				goto finished;
			}
			{
				int isAligned = 1;
				isAligned &= ((index_Secondary_Out3 % SIZE_Secondary_Out3) < ((index_Secondary_Out3 + 10000) % SIZE_Secondary_Out3));
				if (isAligned) {
					Send_Sche3_aligned();
				} else {
					Send_Sche3();
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

	read_end_Scheduler_In();
	read_end_EOF();
	write_end_Secondary_Out0();
	write_end_Sche_Pointer0();
	write_end_Secondary_Out1();
	write_end_Sche_Pointer1();
	write_end_Secondary_Out2();
	write_end_Sche_Pointer2();
	write_end_Secondary_Out3();
	write_end_Sche_Pointer3();
}
