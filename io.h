#ifndef IO_H
#define IO_H

#include "key_table.h"

int write_key_table(unsigned char* buffer, struct KeyTable table); // Returns # of bytes written

#endif
