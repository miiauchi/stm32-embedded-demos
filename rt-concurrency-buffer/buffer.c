#include "main.h"
#include "buffer.h"

int Buffer[64];
int Snapshot[64];
int end = 0;
int start = 0;
int count = 0;

/* Number of valid elements currently in the circular buffer */
int distance() {
	if(end >= start) {
		return (end - start);
	}
	return (end + 64 - start);
}

/* Enqueue: called from the TIM3 ISR. Drops the write if the buffer is full. */
void addToBuffer(int x) {
	if((end + 1) % 64 == start) {
		return;
	}
	Buffer[end] = count;
	count++;
	end = (end + 1) % 64;
}

/* Dequeue: called from the TIM6 ISR. Removes up to 4 of the oldest elements. */
void removeFromBuffer(int y) {
	if(distance() >= 4) {
		start = (start + 4) % 64;
	}
	else {
		start = end;
	}
}

/* Copy valid buffer contents into Snapshot[], padding with 0xfeedbeef */
void addToSnapshot() {
	int i = 0;
	int j = start;
	while (j != end) {
		Snapshot[i] = Buffer[j];
		i++;
		j = (j + 1) % 64;
	}
	while (i < 64) {
		Snapshot[i] = 0xfeedbeef;
		i++;
	}
}
