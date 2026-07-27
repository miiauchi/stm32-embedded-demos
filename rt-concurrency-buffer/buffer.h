#ifndef buffer_h
#define buffer_h

extern int Buffer[64];
extern int Snapshot[64];
extern int end;
extern int start;
extern int count;

int  distance(void);
void addToBuffer(int x);
void removeFromBuffer(int y);
void addToSnapshot(void);

#endif
