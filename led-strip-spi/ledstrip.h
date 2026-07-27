#ifndef ledstrip_h
#define ledstrip_h

#include <stdint.h>

/* APA102 / SK9822 color words: 0xE0|brightness, then B, G, R bytes */
#define START   0x00000000
#define END     0x00000000
#define OFF     0x0e000000
#define RED     0xe20000FF
#define ORANGE  0xe2005AFF
#define YELLOW  0xe200FFFF
#define GREEN   0xe200FF00
#define BLUE    0xe2FF0000
#define INDIGO  0xe22800B4
#define VIOLET  0xe208FF08

void spi32(unsigned int c);
void send_array(uint32_t header, uint32_t color, uint32_t end);
void move(uint32_t header, uint32_t color, uint32_t end, uint32_t num);

#endif
