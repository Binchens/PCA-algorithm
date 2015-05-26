// Source file is "L/hsi_system_1st_Step/src/Source.cal"

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
extern actor_t Source;

////////////////////////////////////////////////////////////////////////////////
// Output FIFOs
extern fifo_float_t *Source_Stream;
extern fifo_i32_t *Source_EOF;

////////////////////////////////////////////////////////////////////////////////
// Output Fifo control variables
static unsigned int index_Stream;
static unsigned int numFree_Stream;
#define NUM_READERS_Stream 2
#define SIZE_Stream SIZE
#define tokens_Stream Source_Stream->contents

static unsigned int index_EOF;
static unsigned int numFree_EOF;
#define NUM_READERS_EOF 2
#define SIZE_EOF SIZE
#define tokens_EOF Source_EOF->contents

////////////////////////////////////////////////////////////////////////////////
// Successors
extern actor_t Constructor_PCA;
extern actor_t Scheduler_PCA;
extern actor_t Scheduler_PCA;
extern actor_t Constructor_PCA;


////////////////////////////////////////////////////////////////////////////////
// State variables of the actor
#define Source_bands 221
static i32 DEBUG = 0;
#define NB_TOKEN_TO_SENT 1
static u8 bytesRead[1];
static u16 elementsRead[1];
static u8 tokenByte[221];
static u16 tokenElement[221];
static u64 iterationLoop = 0;
static u64 nbByteToSend = 0;
static u64 nbByteSent = 0;
static u64 nbIteration;
static u64 offset = 0;
static u64 seq_sum = 10000;
static u64 seq_displ = 0;
static u64 loop = 0;
static u8 numBytes = 2;
static u32 contador = 0;
static i32 lastIterationDone = 0;
static i32 endOfFile = 0;

////////////////////////////////////////////////////////////////////////////////
// Initial FSM state of the actor
enum states {
	my_state_ReadFile,
	my_state_ReadFileDone,
	my_state_ReadInit,
	my_state_SendData,
	my_state_SendLastData
};

static char *stateNames[] = {
	"ReadFile",
	"ReadFileDone",
	"ReadInit",
	"SendData",
	"SendLastData"
};

static enum states _FSM_state;



////////////////////////////////////////////////////////////////////////////////
// Token functions

static void write_Stream() {
	index_Stream = Source_Stream->write_ind;
	numFree_Stream = index_Stream + fifo_float_get_room(Source_Stream, NUM_READERS_Stream, SIZE_Stream);
}

static void write_end_Stream() {
	Source_Stream->write_ind = index_Stream;
}
static void write_EOF() {
	index_EOF = Source_EOF->write_ind;
	numFree_EOF = index_EOF + fifo_i32_get_room(Source_EOF, NUM_READERS_EOF, SIZE_EOF);
}

static void write_end_EOF() {
	Source_EOF->write_ind = index_EOF;
}

////////////////////////////////////////////////////////////////////////////////
// Functions/procedures
extern i32 source_sizeOfFile();
extern u32 source_getNbLoop();
extern void source_init();
extern void source_readNBytes(u8 outTable[1], u16 nbTokenToRead);
extern void source_readNWordsTwoBytes(u16 outTable[1], u16 nbTokenToRead);
extern void source_setFilePosition(u64 offset);
extern void source_rewind();
extern void source_close();


////////////////////////////////////////////////////////////////////////////////
// Actions
static i32 isSchedulable_getFileSize() {
	i32 result;
	i32 tmp_source_sizeOfFile;

	tmp_source_sizeOfFile = source_sizeOfFile();
	result = tmp_source_sizeOfFile > 0;
	return result;
}

static void getFileSize() {

	u64 nbElements;
	i32 tmp_source_sizeOfFile;
	u8 local_numBytes;
	u32 local_NB_TOKEN_TO_SENT;
	i32 local_DEBUG;

	tmp_source_sizeOfFile = source_sizeOfFile();
	local_numBytes = numBytes;
	nbElements = tmp_source_sizeOfFile / local_numBytes;
	local_NB_TOKEN_TO_SENT = NB_TOKEN_TO_SENT;
	nbIteration = nbElements / local_NB_TOKEN_TO_SENT;
	local_DEBUG = DEBUG;
	if (local_DEBUG) {
		printf("Source ACTION: getFileSize\n");
		printf("Source STATE: ReadFile\n");
		printf("-------------------------\n");
	}

	// Update ports indexes

}
static i32 isSchedulable_readNBytes() {
	i32 result;
	u64 local_iterationLoop;
	u64 local_nbIteration;

	local_iterationLoop = iterationLoop;
	local_nbIteration = nbIteration;
	result = local_iterationLoop < local_nbIteration - 1;
	return result;
}

static void readNBytes() {

	u32 local_contador;
	i32 i;
	i32 local_bands;
	u64 local_loop;
	u64 local_seq_displ;
	u64 local_seq_sum;
	u8 local_numBytes;
	u64 local_offset;
	u32 local_NB_TOKEN_TO_SENT;
	u8 tmp_bytesRead;
	u16 tmp_elementsRead;
	u64 local_iterationLoop;
	i32 local_DEBUG;

	local_contador = contador;
	if (local_contador == 0) {
		printf("Send data: start\n");
	}
	local_contador = contador;
	contador = local_contador + 1;
	i = 0;
	local_bands = Source_bands;
	while (i <= local_bands - 1) {
		local_loop = loop;
		local_bands = Source_bands;
		if (local_loop == local_bands - 1) {
			local_seq_displ = seq_displ;
			local_seq_sum = seq_sum;
			local_loop = loop;
			offset = local_seq_displ + local_seq_sum * local_loop;
			loop = 0;
			local_seq_displ = seq_displ;
			seq_displ = local_seq_displ + 1;
		} else {
			local_seq_displ = seq_displ;
			local_seq_sum = seq_sum;
			local_loop = loop;
			offset = local_seq_displ + local_seq_sum * local_loop;
			local_loop = loop;
			loop = local_loop + 1;
		}
		local_numBytes = numBytes;
		local_offset = offset;
		source_setFilePosition(local_numBytes * local_offset);
		local_numBytes = numBytes;
		if (local_numBytes == 1) {
			local_NB_TOKEN_TO_SENT = NB_TOKEN_TO_SENT;
			source_readNBytes(bytesRead, local_NB_TOKEN_TO_SENT);
			tmp_bytesRead = bytesRead[0];
			tokenByte[i] = tmp_bytesRead;
		} else {
			local_NB_TOKEN_TO_SENT = NB_TOKEN_TO_SENT;
			source_readNWordsTwoBytes(elementsRead, local_NB_TOKEN_TO_SENT);
			tmp_elementsRead = elementsRead[0];
			tokenElement[i] = tmp_elementsRead;
		}
		local_iterationLoop = iterationLoop;
		iterationLoop = local_iterationLoop + 1;
		i = i + 1;
	}
	local_NB_TOKEN_TO_SENT = NB_TOKEN_TO_SENT;
	nbByteToSend = local_NB_TOKEN_TO_SENT;
	nbByteSent = 0;
	local_DEBUG = DEBUG;
	if (local_DEBUG) {
		printf("Source ACTION: readNbytes\n");
		printf("Source STATE: SendData\n");
		printf("-------------------------\n");
	}

	// Update ports indexes

}
static i32 isSchedulable_closeFile() {
	i32 result;
	i32 local_endOfFile;

	local_endOfFile = endOfFile;
	result = local_endOfFile == 0;
	return result;
}

static void closeFile() {

	i32 local_DEBUG;
	i32 local_endOfFile;

	source_close();
	local_DEBUG = DEBUG;
	if (local_DEBUG) {
		printf("Source ACTION: closeFile\n");
		printf("Source STATE: ReadFileDone\n");
		printf("-------------------------\n");
	}
	endOfFile = 1;
	local_endOfFile = endOfFile;
	tokens_EOF[(index_EOF + (0)) % SIZE_EOF] = local_endOfFile;

	// Update ports indexes
	index_EOF += 1;

}
static i32 isSchedulable_sendData_launch() {
	i32 result;
	u64 local_nbByteToSend;
	u64 local_nbByteSent;

	local_nbByteToSend = nbByteToSend;
	local_nbByteSent = nbByteSent;
	result = local_nbByteToSend > local_nbByteSent;
	return result;
}

static void sendData_launch() {

	u8 local_numBytes;
	i32 idx_tokenByte;
	float local_tokenByte;
	i32 idx_tokenElement;
	float local_tokenElement;
	u64 local_nbByteSent;
	i32 local_DEBUG;
	u64 local_iterationLoop;
	u64 local_nbIteration;
	i32 local_lastIterationDone;
	i32 local_endOfFile;

	local_numBytes = numBytes;
	if (local_numBytes == 1) {
		idx_tokenByte = 0;
		while (idx_tokenByte < 221) {
			local_tokenByte = tokenByte[idx_tokenByte];
			tokens_Stream[(index_Stream + (idx_tokenByte)) % SIZE_Stream] = local_tokenByte;
			idx_tokenByte = idx_tokenByte + 1;
		}
	} else {
		idx_tokenElement = 0;
		while (idx_tokenElement < 221) {
			local_tokenElement = tokenElement[idx_tokenElement];
			tokens_Stream[(index_Stream + (idx_tokenElement)) % SIZE_Stream] = local_tokenElement;
			idx_tokenElement = idx_tokenElement + 1;
		}
	}
	local_nbByteSent = nbByteSent;
	nbByteSent = local_nbByteSent + 1;
	local_DEBUG = DEBUG;
	if (local_DEBUG) {
		printf("Source ACTION: sendData.launch\n");
		local_iterationLoop = iterationLoop;
		local_nbIteration = nbIteration;
		local_lastIterationDone = lastIterationDone;
		if ((local_iterationLoop == local_nbIteration && local_lastIterationDone)) {
			printf("Source STATE: SendLastData\n");
			printf("-------------------------\n");
		} else {
			printf("Source STATE: SendData\n");
			printf("-------------------------\n");
		}
	}
	local_endOfFile = endOfFile;
	tokens_EOF[(index_EOF + (0)) % SIZE_EOF] = local_endOfFile;

	// Update ports indexes
	index_Stream += 221;
	write_end_Stream();
	index_EOF += 1;

}
static void sendData_launch_aligned() {

	u8 local_numBytes;
	i32 idx_tokenByte;
	float local_tokenByte;
	i32 idx_tokenElement;
	float local_tokenElement;
	u64 local_nbByteSent;
	i32 local_DEBUG;
	u64 local_iterationLoop;
	u64 local_nbIteration;
	i32 local_lastIterationDone;
	i32 local_endOfFile;

	local_numBytes = numBytes;
	if (local_numBytes == 1) {
		idx_tokenByte = 0;
		while (idx_tokenByte < 221) {
			local_tokenByte = tokenByte[idx_tokenByte];
			tokens_Stream[(index_Stream % SIZE_Stream) + (idx_tokenByte)] = local_tokenByte;
			idx_tokenByte = idx_tokenByte + 1;
		}
	} else {
		idx_tokenElement = 0;
		while (idx_tokenElement < 221) {
			local_tokenElement = tokenElement[idx_tokenElement];
			tokens_Stream[(index_Stream % SIZE_Stream) + (idx_tokenElement)] = local_tokenElement;
			idx_tokenElement = idx_tokenElement + 1;
		}
	}
	local_nbByteSent = nbByteSent;
	nbByteSent = local_nbByteSent + 1;
	local_DEBUG = DEBUG;
	if (local_DEBUG) {
		printf("Source ACTION: sendData.launch\n");
		local_iterationLoop = iterationLoop;
		local_nbIteration = nbIteration;
		local_lastIterationDone = lastIterationDone;
		if ((local_iterationLoop == local_nbIteration && local_lastIterationDone)) {
			printf("Source STATE: SendLastData\n");
			printf("-------------------------\n");
		} else {
			printf("Source STATE: SendData\n");
			printf("-------------------------\n");
		}
	}
	local_endOfFile = endOfFile;
	tokens_EOF[(index_EOF + (0)) % SIZE_EOF] = local_endOfFile;

	// Update ports indexes
	index_Stream += 221;
	write_end_Stream();
	index_EOF += 1;

}
static i32 isSchedulable_sendData_done() {
	i32 result;
	u64 local_nbByteToSend;
	u64 local_nbByteSent;

	local_nbByteToSend = nbByteToSend;
	local_nbByteSent = nbByteSent;
	result = local_nbByteToSend == local_nbByteSent;
	return result;
}

static void sendData_done() {

	i32 local_DEBUG;
	u64 local_iterationLoop;
	u64 local_nbIteration;
	i32 local_lastIterationDone;

	local_DEBUG = DEBUG;
	if (local_DEBUG) {
		printf("Source ACTION: sendData.done\n");
		local_iterationLoop = iterationLoop;
		local_nbIteration = nbIteration;
		local_lastIterationDone = lastIterationDone;
		if ((local_iterationLoop == local_nbIteration && local_lastIterationDone)) {
			printf("Source STATE: ReadFileDone\n");
			printf("-------------------------\n");
		} else {
			printf("Source STATE: ReadFile\n");
			printf("-------------------------\n");
			local_iterationLoop = iterationLoop;
			local_nbIteration = nbIteration;
			if (local_iterationLoop == local_nbIteration) {
				lastIterationDone = 1;
			}
		}
	}

	// Update ports indexes

}

////////////////////////////////////////////////////////////////////////////////
// Initializes
static i32 isSchedulable_untagged_0() {
	i32 result;

	result = 1;
	return result;
}

static void untagged_0() {

	i32 local_DEBUG;

	source_init();
	local_DEBUG = DEBUG;
	if (local_DEBUG) {
		printf("Source ACTION: initialize\n");
		printf("Source STATE: ReadInit\n");
		printf("-------------------------\n");
	}

	// Update ports indexes

}

void Source_initialize(schedinfo_t *si) {
	int i = 0;
	write_Stream();
	write_EOF();
	/* Set initial state to current FSM state */
	_FSM_state = my_state_ReadInit;
	if(isSchedulable_untagged_0()) {
		untagged_0();
	}
finished:
	write_end_Stream();
	write_end_EOF();
	return;
}

////////////////////////////////////////////////////////////////////////////////
// Action scheduler

void Source_scheduler(schedinfo_t *si) {
	int i = 0;

	write_Stream();
	write_EOF();

	// jump to FSM state
	switch (_FSM_state) {
	case my_state_ReadFile:
		goto l_ReadFile;
	case my_state_ReadFileDone:
		goto l_ReadFileDone;
	case my_state_ReadInit:
		goto l_ReadInit;
	case my_state_SendData:
		goto l_SendData;
	case my_state_SendLastData:
		goto l_SendLastData;
	default:
		printf("unknown state in Source.c : %s\n", stateNames[_FSM_state]);
		exit(1);
	}

	// FSM transitions
l_ReadFile:
	if (isSchedulable_readNBytes()) {
		readNBytes();
		i++;
		goto l_SendData;
	} else if (isSchedulable_sendData_done()) {
		sendData_done();
		i++;
		goto l_ReadFileDone;
	} else {
		si->num_firings = i;
		si->reason = starved;
		_FSM_state = my_state_ReadFile;
		goto finished;
	}
l_ReadFileDone:
	if (isSchedulable_closeFile()) {
		int stop = 0;
		if (1 > SIZE_EOF - index_EOF + Source_EOF->read_inds[0]) {
			stop = 1;
		}
		if (1 > SIZE_EOF - index_EOF + Source_EOF->read_inds[1]) {
			stop = 1;
		}
		if (stop != 0) {
			_FSM_state = my_state_ReadFileDone;
			si->num_firings = i;
			si->reason = full;
			goto finished;
		}
		closeFile();
		i++;
		goto l_ReadFileDone;
	} else {
		si->num_firings = i;
		si->reason = starved;
		_FSM_state = my_state_ReadFileDone;
		goto finished;
	}
l_ReadInit:
	if (isSchedulable_getFileSize()) {
		getFileSize();
		i++;
		goto l_ReadFile;
	} else {
		si->num_firings = i;
		si->reason = starved;
		_FSM_state = my_state_ReadInit;
		goto finished;
	}
l_SendData:
	if (isSchedulable_sendData_launch()) {
		int stop = 0;
		if (221 > SIZE_Stream - index_Stream + Source_Stream->read_inds[0]) {
			stop = 1;
		}
		if (221 > SIZE_Stream - index_Stream + Source_Stream->read_inds[1]) {
			stop = 1;
		}
		if (1 > SIZE_EOF - index_EOF + Source_EOF->read_inds[0]) {
			stop = 1;
		}
		if (1 > SIZE_EOF - index_EOF + Source_EOF->read_inds[1]) {
			stop = 1;
		}
		if (stop != 0) {
			_FSM_state = my_state_SendData;
			si->num_firings = i;
			si->reason = full;
			goto finished;
		}
		{
			int isAligned = 1;
			isAligned &= ((index_Stream % SIZE_Stream) < ((index_Stream + 221) % SIZE_Stream));
			if (isAligned) {
				sendData_launch_aligned();
			} else {
				sendData_launch();
			}
		}
		i++;
		goto l_SendData;
	} else if (isSchedulable_sendData_done()) {
		sendData_done();
		i++;
		goto l_ReadFile;
	} else {
		si->num_firings = i;
		si->reason = starved;
		_FSM_state = my_state_SendData;
		goto finished;
	}
l_SendLastData:
	if (isSchedulable_sendData_launch()) {
		int stop = 0;
		if (221 > SIZE_Stream - index_Stream + Source_Stream->read_inds[0]) {
			stop = 1;
		}
		if (221 > SIZE_Stream - index_Stream + Source_Stream->read_inds[1]) {
			stop = 1;
		}
		if (1 > SIZE_EOF - index_EOF + Source_EOF->read_inds[0]) {
			stop = 1;
		}
		if (1 > SIZE_EOF - index_EOF + Source_EOF->read_inds[1]) {
			stop = 1;
		}
		if (stop != 0) {
			_FSM_state = my_state_SendLastData;
			si->num_firings = i;
			si->reason = full;
			goto finished;
		}
		{
			int isAligned = 1;
			isAligned &= ((index_Stream % SIZE_Stream) < ((index_Stream + 221) % SIZE_Stream));
			if (isAligned) {
				sendData_launch_aligned();
			} else {
				sendData_launch();
			}
		}
		i++;
		goto l_SendLastData;
	} else if (isSchedulable_sendData_done()) {
		sendData_done();
		i++;
		goto l_ReadFileDone;
	} else {
		si->num_firings = i;
		si->reason = starved;
		_FSM_state = my_state_SendLastData;
		goto finished;
	}
finished:
	write_end_Stream();
	write_end_EOF();
}
