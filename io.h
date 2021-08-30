#ifndef IO_H
#define IO_H

#include "key_table.h"

int write_key_table(unsigned char* buffer, struct KeyTable table); // Returns # of bits written
int read_key_table(unsigned char* buffer, struct KeyTable* table); // Returns # of bits read
int write_compressed_buffer(unsigned char* buffer, struct KeyTable table, unsigned char* input, int size); // returns # of bits written
int read_compressed_buffer(unsigned char* buffer, struct KeyTable table, unsigned char* input, int size); // returns # of bits read

#endif
