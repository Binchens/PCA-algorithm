// Generated from ".hsi_system"

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "fifo.h"
#include "util.h"
#include "dataflow.h"
#include "serialize.h"
#include "options.h"
#include "scheduler.h"

#define SIZE 512

/////////////////////////////////////////////////
// FIFO allocation
DECLARE_FIFO(float, SIZE, 0, 2)
DECLARE_FIFO(float, SIZE, 1, 1)
DECLARE_FIFO(float, SIZE, 2, 1)
DECLARE_FIFO(float, SIZE, 3, 1)
DECLARE_FIFO(i32, SIZE, 4, 1)

/////////////////////////////////////////////////
// FIFO pointer assignments
fifo_float_t *PCA_PCA_out = &fifo_0;
fifo_float_t *VCA_VCA_in = &fifo_0;
fifo_float_t *LSU_pixels = &fifo_0;

fifo_float_t *VCA_VCA_out = &fifo_1;
fifo_float_t *LSU_LSU_in = &fifo_1;

fifo_float_t *LSU_LSU_out = &fifo_2;
fifo_float_t *Display_stream = &fifo_2;

fifo_float_t *Source_Stream = &fifo_3;
fifo_float_t *PCA_PCA_in = &fifo_3;

fifo_i32_t *Source_EOF = &fifo_4;
fifo_i32_t *PCA_EOF = &fifo_4;




/////////////////////////////////////////////////
// Actor functions
extern void PCA_initialize(schedinfo_t *si);
extern void PCA_scheduler(schedinfo_t *si);
extern void VCA_initialize(schedinfo_t *si);
extern void VCA_scheduler(schedinfo_t *si);
extern void LSU_initialize(schedinfo_t *si);
extern void LSU_scheduler(schedinfo_t *si);
extern void Source_initialize(schedinfo_t *si);
extern void Source_scheduler(schedinfo_t *si);
extern void Display_initialize(schedinfo_t *si);
extern void Display_scheduler(schedinfo_t *si);

/////////////////////////////////////////////////
// Declaration of the actors array
actor_t PCA = {"PCA", PCA_initialize, PCA_scheduler, 0, 0, 0, 0, NULL, -1, 0, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t VCA = {"VCA", VCA_initialize, VCA_scheduler, 0, 0, 0, 0, NULL, -1, 1, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t LSU = {"LSU", LSU_initialize, LSU_scheduler, 0, 0, 0, 0, NULL, -1, 2, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Source = {"Source", Source_initialize, Source_scheduler, 0, 0, 0, 0, NULL, -1, 3, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Display = {"Display", Display_initialize, Display_scheduler, 0, 0, 0, 0, NULL, -1, 4, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};

actor_t *actors[] = {
	&PCA,
	&VCA,
	&LSU,
	&Source,
	&Display
};

/////////////////////////////////////////////////
// Declaration of the connections array
connection_t connection_VCA_VCA_in = {&PCA, &VCA, 0, 0};
connection_t connection_PCA_PCA_in = {&Source, &PCA, 0, 0};
connection_t connection_LSU_LSU_in = {&VCA, &LSU, 0, 0};
connection_t connection_LSU_pixels = {&PCA, &LSU, 0, 0};
connection_t connection_Display_stream = {&LSU, &Display, 0, 0};
connection_t connection_PCA_EOF = {&Source, &PCA, 0, 0};

connection_t *connections[] = {
	&connection_VCA_VCA_in,
	&connection_PCA_PCA_in,
	&connection_LSU_LSU_in,
	&connection_LSU_pixels,
	&connection_Display_stream,
	&connection_PCA_EOF
};

/////////////////////////////////////////////////
// Declaration of the network
network_t network = {".hsi_system", actors, connections, 5, 6};


////////////////////////////////////////////////////////////////////////////////
// Main
int main(int argc, char *argv[]) {
	
	options_t *opt = init_orcc(argc, argv);
	set_scheduling_strategy("RR", opt);
	
	launcher(opt, &network);
	return compareErrors;
}
