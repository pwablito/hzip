#include "key_table.h"
#include <stdlib.h>


struct KeyTable create_key_table() {
    struct KeyTable table;
    table.table = calloc(0xff, sizeof(struct KeyTableEntry));
    return table;
}

void destroy_key_table(struct KeyTable table) {
    free(table.table);
}

unsigned int lookup_bit_length(struct KeyTable table, char byte) {
    struct KeyTableEntry entry = ((struct KeyTableEntry *) (table.table))[byte];
    return entry.bit_length;
}

unsigned int lookup_table_value(struct KeyTable table, char byte) {
    struct KeyTableEntry entry = ((struct KeyTableEntry *) (table.table))[byte];
    return entry.data;
}

void set_key_table_value(struct KeyTable table, char byte, unsigned int data, unsigned int bit_length) {
    ((struct KeyTableEntry *) (table.table))[byte].data = data;
    ((struct KeyTableEntry *) (table.table))[byte].bit_length = bit_length;
}