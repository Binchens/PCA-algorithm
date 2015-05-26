// Source file is "L/hsi_system/src/Display.cal"

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
extern actor_t Display;

////////////////////////////////////////////////////////////////////////////////
// Input FIFOs
extern fifo_float_t *Display_stream;

////////////////////////////////////////////////////////////////////////////////
// Input Fifo control variables
static unsigned int index_stream;
static unsigned int numTokens_stream;
#define SIZE_stream SIZE
#define tokens_stream Display_stream->contents

extern connection_t connection_Display_stream;
#define rate_stream connection_Display_stream.rate

////////////////////////////////////////////////////////////////////////////////
// Predecessors
extern actor_t LSU;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define Display_rc 10000
#define Display_num_Endmembers 20
#define Display_int_Endmembers 20
#define Display_rows 100
#define Display_columns 100
#define Display_num_PC 100
static i32 received = 0;
static float array_rec[100];
static double image_ABUND[20][10000];



////////////////////////////////////////////////////////////////////////////////
// Token functions
static void read_stream() {
	index_stream = Display_stream->read_inds[0];
	numTokens_stream = index_stream + fifo_float_get_num_tokens(Display_stream, 0);
}

static void read_end_stream() {
	Display_stream->read_inds[0] = index_stream;
}


////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern double float_to_double(float value);
extern void gen_hdr(double matrixOut[10000][10000], i32 rows, i32 columns, i32 lines, i32 samples, i32 bands, i32 numEnd, char * path, char * fileName, i32 typeFile);
extern void end_program();


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_receive_abundances() {
	i32 result;
	i32 local_received;
	i32 local_rc;

	local_received = received;
	local_rc = Display_rc;
	result = local_received < local_rc;
	return result;
}

static void receive_abundances() {

	i32 idx_stream;
	float local_stream;
	i32 m;
	double local_num_Endmembers;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_rc;
	i32 local_int_Endmembers;
	i32 local_rows;
	i32 local_columns;
	i32 local_num_PC;

	idx_stream = 0;
	while (idx_stream < 100) {
		local_stream = tokens_stream[(index_stream + (idx_stream)) % SIZE_stream];
		array_rec[idx_stream] = local_stream;
		idx_stream = idx_stream + 1;
	}
	m = 0;
	local_num_Endmembers = Display_num_Endmembers;
	while (m <= local_num_Endmembers - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_ABUND[m][local_received] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;
	local_received = received;
	local_rc = Display_rc;
	if (local_received == local_rc) {
		local_int_Endmembers = Display_int_Endmembers;
		local_rc = Display_rc;
		local_rows = Display_rows;
		local_columns = Display_columns;
		local_num_PC = Display_num_PC;
		local_int_Endmembers = Display_int_Endmembers;
		gen_hdr(image_ABUND, local_int_Endmembers, local_rc, local_rows, local_columns, local_num_PC, local_int_Endmembers, "/home/rlazcano/Dropbox/PFG-GDEM/workspace_ultimo/HSI_SYSTEM/compiled/bin/abund", "abund", 3);
		printf("Display: done\n");
		printf("FIN PROCESAMIENTO\n");
		end_program();
	}

	// Update ports indexes
	index_stream += 20;
	read_end_stream();

	rate_stream += 20;
}
static void receive_abundances_aligned() {

	i32 idx_stream;
	float local_stream;
	i32 m;
	double local_num_Endmembers;
	i32 local_received;
	float tmp_array_rec;
	double tmp_float_to_double;
	i32 local_rc;
	i32 local_int_Endmembers;
	i32 local_rows;
	i32 local_columns;
	i32 local_num_PC;

	idx_stream = 0;
	while (idx_stream < 100) {
		local_stream = tokens_stream[(index_stream % SIZE_stream) + (idx_stream)];
		array_rec[idx_stream] = local_stream;
		idx_stream = idx_stream + 1;
	}
	m = 0;
	local_num_Endmembers = Display_num_Endmembers;
	while (m <= local_num_Endmembers - 1) {
		local_received = received;
		tmp_array_rec = array_rec[m];
		tmp_float_to_double = float_to_double(tmp_array_rec);
		image_ABUND[m][local_received] = tmp_float_to_double;
		m = m + 1;
	}
	local_received = received;
	received = local_received + 1;
	local_received = received;
	local_rc = Display_rc;
	if (local_received == local_rc) {
		local_int_Endmembers = Display_int_Endmembers;
		local_rc = Display_rc;
		local_rows = Display_rows;
		local_columns = Display_columns;
		local_num_PC = Display_num_PC;
		local_int_Endmembers = Display_int_Endmembers;
		gen_hdr(image_ABUND, local_int_Endmembers, local_rc, local_rows, local_columns, local_num_PC, local_int_Endmembers, "/home/rlazcano/Dropbox/PFG-GDEM/workspace_ultimo/HSI_SYSTEM/compiled/bin/abund", "abund", 3);
		printf("Display: done\n");
		printf("FIN PROCESAMIENTO\n");
		end_program();
	}

	// Update ports indexes
	index_stream += 20;
	read_end_stream();

	rate_stream += 20;
}

////////////////////////////////////////////////////////////////////////////////
// Initializes

void Display_initialize(schedinfo_t *si) {
	int i = 0;
finished:
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler
void Display_scheduler(schedinfo_t *si) {
	int i = 0;
	si->ports = 0;

	read_stream();

	while (1) {
		if (numTokens_stream - index_stream >= 20 && isSchedulable_receive_abundances()) {
			{
				int isAligned = 1;
				isAligned &= ((index_stream % SIZE_stream) < ((index_stream + 20) % SIZE_stream));
				if (isAligned) {
					receive_abundances_aligned();
				} else {
					receive_abundances();
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

	read_end_stream();
}
