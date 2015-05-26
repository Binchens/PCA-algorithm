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

#define SIZE 2048

/////////////////////////////////////////////////
// FIFO allocation
DECLARE_FIFO(float, SIZE, 0, 1)
DECLARE_FIFO(float, SIZE, 1, 1)
DECLARE_FIFO(i32, SIZE, 2, 2)
DECLARE_FIFO(float, SIZE, 3, 2)
DECLARE_FIFO(float, SIZE, 4, 1)
DECLARE_FIFO(i32, SIZE, 5, 1)
DECLARE_FIFO(float, SIZE, 6, 1)
DECLARE_FIFO(i32, SIZE, 7, 1)
DECLARE_FIFO(i32, SIZE, 8, 1)
DECLARE_FIFO(float, SIZE, 9, 1)
DECLARE_FIFO(float, SIZE, 10, 1)
DECLARE_FIFO(i32, SIZE, 11, 1)
DECLARE_FIFO(float, SIZE, 12, 1)
DECLARE_FIFO(float, SIZE, 13, 1)
DECLARE_FIFO(i32, SIZE, 14, 1)
DECLARE_FIFO(float, SIZE, 15, 1)
DECLARE_FIFO(float, SIZE, 16, 1)
DECLARE_FIFO(i32, SIZE, 17, 1)
DECLARE_FIFO(i32, SIZE, 18, 1)
DECLARE_FIFO(i32, SIZE, 19, 1)
DECLARE_FIFO(float, SIZE, 20, 2)

/////////////////////////////////////////////////
// FIFO pointer assignments
fifo_float_t *VCA_VCA_out = &fifo_0;
fifo_float_t *LSU_LSU_in = &fifo_0;

fifo_float_t *LSU_LSU_out = &fifo_1;
fifo_float_t *Display_stream = &fifo_1;

fifo_i32_t *Source_EOF = &fifo_2;
fifo_i32_t *Scheduler_PCA_EOF = &fifo_2;
fifo_i32_t *Constructor_PCA_EOF = &fifo_2;

fifo_float_t *Source_Stream = &fifo_3;
fifo_float_t *Constructor_PCA_PCA_in = &fifo_3;
fifo_float_t *Scheduler_PCA_Scheduler_In = &fifo_3;

fifo_float_t *Secondary_PCA_0_PCA_Secondary_out = &fifo_4;
fifo_float_t *Constructor_PCA_Constructor_in0 = &fifo_4;

fifo_i32_t *Secondary_PCA_0_Sec_Pointer = &fifo_5;
fifo_i32_t *Constructor_PCA_Sec_Pointer0 = &fifo_5;

fifo_float_t *Secondary_PCA_1_PCA_Secondary_out = &fifo_6;
fifo_float_t *Constructor_PCA_Constructor_in1 = &fifo_6;

fifo_i32_t *Secondary_PCA_1_Sec_Pointer = &fifo_7;
fifo_i32_t *Constructor_PCA_Sec_Pointer1 = &fifo_7;

fifo_i32_t *Secondary_PCA_2_Sec_Pointer = &fifo_8;
fifo_i32_t *Constructor_PCA_Sec_Pointer2 = &fifo_8;

fifo_float_t *Secondary_PCA_2_PCA_Secondary_out = &fifo_9;
fifo_float_t *Constructor_PCA_Constructor_in2 = &fifo_9;

fifo_float_t *Secondary_PCA_3_PCA_Secondary_out = &fifo_10;
fifo_float_t *Constructor_PCA_Constructor_in3 = &fifo_10;

fifo_i32_t *Secondary_PCA_3_Sec_Pointer = &fifo_11;
fifo_i32_t *Constructor_PCA_Sec_Pointer3 = &fifo_11;

fifo_float_t *Scheduler_PCA_Secondary_Out0 = &fifo_12;
fifo_float_t *Secondary_PCA_0_PCA_Secondary_in = &fifo_12;

fifo_float_t *Scheduler_PCA_Secondary_Out2 = &fifo_13;
fifo_float_t *Secondary_PCA_2_PCA_Secondary_in = &fifo_13;

fifo_i32_t *Scheduler_PCA_Sche_Pointer3 = &fifo_14;
fifo_i32_t *Secondary_PCA_3_Sche_Pointer = &fifo_14;

fifo_float_t *Scheduler_PCA_Secondary_Out3 = &fifo_15;
fifo_float_t *Secondary_PCA_3_PCA_Secondary_in = &fifo_15;

fifo_float_t *Scheduler_PCA_Secondary_Out1 = &fifo_16;
fifo_float_t *Secondary_PCA_1_PCA_Secondary_in = &fifo_16;

fifo_i32_t *Scheduler_PCA_Sche_Pointer0 = &fifo_17;
fifo_i32_t *Secondary_PCA_0_Sche_Pointer = &fifo_17;

fifo_i32_t *Scheduler_PCA_Sche_Pointer1 = &fifo_18;
fifo_i32_t *Secondary_PCA_1_Sche_Pointer = &fifo_18;

fifo_i32_t *Scheduler_PCA_Sche_Pointer2 = &fifo_19;
fifo_i32_t *Secondary_PCA_2_Sche_Pointer = &fifo_19;

fifo_float_t *Constructor_PCA_PCA_Constructor_out = &fifo_20;
fifo_float_t *VCA_VCA_in = &fifo_20;
fifo_float_t *LSU_pixels = &fifo_20;




/////////////////////////////////////////////////
// Actor functions
extern void VCA_initialize(schedinfo_t *si);
extern void VCA_scheduler(schedinfo_t *si);
extern void LSU_initialize(schedinfo_t *si);
extern void LSU_scheduler(schedinfo_t *si);
extern void Source_initialize(schedinfo_t *si);
extern void Source_scheduler(schedinfo_t *si);
extern void Display_initialize(schedinfo_t *si);
extern void Display_scheduler(schedinfo_t *si);
extern void Secondary_PCA_0_initialize(schedinfo_t *si);
extern void Secondary_PCA_0_scheduler(schedinfo_t *si);
extern void Secondary_PCA_1_initialize(schedinfo_t *si);
extern void Secondary_PCA_1_scheduler(schedinfo_t *si);
extern void Secondary_PCA_2_initialize(schedinfo_t *si);
extern void Secondary_PCA_2_scheduler(schedinfo_t *si);
extern void Secondary_PCA_3_initialize(schedinfo_t *si);
extern void Secondary_PCA_3_scheduler(schedinfo_t *si);
extern void Scheduler_PCA_initialize(schedinfo_t *si);
extern void Scheduler_PCA_scheduler(schedinfo_t *si);
extern void Constructor_PCA_initialize(schedinfo_t *si);
extern void Constructor_PCA_scheduler(schedinfo_t *si);

/////////////////////////////////////////////////
// Declaration of the actors array
actor_t VCA = {"VCA", VCA_initialize, VCA_scheduler, 0, 0, 0, 0, NULL, -1, 0, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t LSU = {"LSU", LSU_initialize, LSU_scheduler, 0, 0, 0, 0, NULL, -1, 1, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Source = {"Source", Source_initialize, Source_scheduler, 0, 0, 0, 0, NULL, -1, 2, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Display = {"Display", Display_initialize, Display_scheduler, 0, 0, 0, 0, NULL, -1, 3, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Secondary_PCA_0 = {"Secondary_PCA_0", Secondary_PCA_0_initialize, Secondary_PCA_0_scheduler, 0, 0, 0, 0, NULL, -1, 4, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Secondary_PCA_1 = {"Secondary_PCA_1", Secondary_PCA_1_initialize, Secondary_PCA_1_scheduler, 0, 0, 0, 0, NULL, -1, 5, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Secondary_PCA_2 = {"Secondary_PCA_2", Secondary_PCA_2_initialize, Secondary_PCA_2_scheduler, 0, 0, 0, 0, NULL, -1, 6, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Secondary_PCA_3 = {"Secondary_PCA_3", Secondary_PCA_3_initialize, Secondary_PCA_3_scheduler, 0, 0, 0, 0, NULL, -1, 7, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Scheduler_PCA = {"Scheduler_PCA", Scheduler_PCA_initialize, Scheduler_PCA_scheduler, 0, 0, 0, 0, NULL, -1, 8, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};
actor_t Constructor_PCA = {"Constructor_PCA", Constructor_PCA_initialize, Constructor_PCA_scheduler, 0, 0, 0, 0, NULL, -1, 9, 0, 1, 0, 0, 0, NULL, 0, 0, "", 0, 0, 0};

actor_t *actors[] = {
	&VCA,
	&LSU,
	&Source,
	&Display,
	&Secondary_PCA_0,
	&Secondary_PCA_1,
	&Secondary_PCA_2,
	&Secondary_PCA_3,
	&Scheduler_PCA,
	&Constructor_PCA
};

/////////////////////////////////////////////////
// Declaration of the connections array
connection_t connection_LSU_LSU_in = {&VCA, &LSU, 0, 0};
connection_t connection_Display_stream = {&LSU, &Display, 0, 0};
connection_t connection_Scheduler_PCA_EOF = {&Source, &Scheduler_PCA, 0, 0};
connection_t connection_VCA_VCA_in = {&Constructor_PCA, &VCA, 0, 0};
connection_t connection_Constructor_PCA_Sec_Pointer0 = {&Secondary_PCA_0, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_Sec_Pointer1 = {&Secondary_PCA_1, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_Sec_Pointer2 = {&Secondary_PCA_2, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_Sec_Pointer3 = {&Secondary_PCA_3, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_PCA_in = {&Source, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_EOF = {&Source, &Constructor_PCA, 0, 0};
connection_t connection_Secondary_PCA_0_PCA_Secondary_in = {&Scheduler_PCA, &Secondary_PCA_0, 0, 0};
connection_t connection_Secondary_PCA_1_PCA_Secondary_in = {&Scheduler_PCA, &Secondary_PCA_1, 0, 0};
connection_t connection_Secondary_PCA_2_PCA_Secondary_in = {&Scheduler_PCA, &Secondary_PCA_2, 0, 0};
connection_t connection_Secondary_PCA_0_Sche_Pointer = {&Scheduler_PCA, &Secondary_PCA_0, 0, 0};
connection_t connection_Secondary_PCA_1_Sche_Pointer = {&Scheduler_PCA, &Secondary_PCA_1, 0, 0};
connection_t connection_Secondary_PCA_2_Sche_Pointer = {&Scheduler_PCA, &Secondary_PCA_2, 0, 0};
connection_t connection_Secondary_PCA_3_Sche_Pointer = {&Scheduler_PCA, &Secondary_PCA_3, 0, 0};
connection_t connection_Secondary_PCA_3_PCA_Secondary_in = {&Scheduler_PCA, &Secondary_PCA_3, 0, 0};
connection_t connection_Constructor_PCA_Constructor_in0 = {&Secondary_PCA_0, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_Constructor_in1 = {&Secondary_PCA_1, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_Constructor_in2 = {&Secondary_PCA_2, &Constructor_PCA, 0, 0};
connection_t connection_Constructor_PCA_Constructor_in3 = {&Secondary_PCA_3, &Constructor_PCA, 0, 0};
connection_t connection_LSU_pixels = {&Constructor_PCA, &LSU, 0, 0};
connection_t connection_Scheduler_PCA_Scheduler_In = {&Source, &Scheduler_PCA, 0, 0};

connection_t *connections[] = {
	&connection_LSU_LSU_in,
	&connection_Display_stream,
	&connection_Scheduler_PCA_EOF,
	&connection_VCA_VCA_in,
	&connection_Constructor_PCA_Sec_Pointer0,
	&connection_Constructor_PCA_Sec_Pointer1,
	&connection_Constructor_PCA_Sec_Pointer2,
	&connection_Constructor_PCA_Sec_Pointer3,
	&connection_Constructor_PCA_PCA_in,
	&connection_Constructor_PCA_EOF,
	&connection_Secondary_PCA_0_PCA_Secondary_in,
	&connection_Secondary_PCA_1_PCA_Secondary_in,
	&connection_Secondary_PCA_2_PCA_Secondary_in,
	&connection_Secondary_PCA_0_Sche_Pointer,
	&connection_Secondary_PCA_1_Sche_Pointer,
	&connection_Secondary_PCA_2_Sche_Pointer,
	&connection_Secondary_PCA_3_Sche_Pointer,
	&connection_Secondary_PCA_3_PCA_Secondary_in,
	&connection_Constructor_PCA_Constructor_in0,
	&connection_Constructor_PCA_Constructor_in1,
	&connection_Constructor_PCA_Constructor_in2,
	&connection_Constructor_PCA_Constructor_in3,
	&connection_LSU_pixels,
	&connection_Scheduler_PCA_Scheduler_In
};

/////////////////////////////////////////////////
// Declaration of the network
network_t network = {".hsi_system", actors, connections, 10, 24};


////////////////////////////////////////////////////////////////////////////////
// Main
int main(int argc, char *argv[]) {
	
	options_t *opt = init_orcc(argc, argv);
	set_scheduling_strategy("RR", opt);
	
	launcher(opt, &network);
	return compareErrors;
}
