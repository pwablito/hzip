#include "io.h"
#include "key_table.h"

int write_key_table(unsigned char* buffer, struct KeyTable table) {
    for (unsigned int i = 0; i < 0x100; i++) {
        buffer[3 * i] = (char)i;
        buffer[(3 * i) + 1] = lookup_bit_length(table, (char)i);
        buffer[(3 * i) + 2] = lookup_table_value(table, (char)i);
    }
}