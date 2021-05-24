#include <stdlib.h>
#include <stdio.h>
#include "frequency.h"

struct FreqTable create_frequency_table() {
    int size = sizeof(unsigned int) * 0xff;
    struct FreqTable table;
    table.table = calloc(size, 1);
    return table;
}

void destroy_frequency_table(struct FreqTable table) {
    free(table.table);
}

unsigned int get_frequency(const struct FreqTable table, const unsigned char byte) {
    return table.table[byte];
}

void set_frequency(struct FreqTable table, const char byte, const unsigned int value) {
    table.table[byte] = value;
}

struct FreqTable generate_frequencies(const char* buffer, int size) {
    struct FreqTable table = create_frequency_table();
    for (unsigned int position = 0; position < size; position++) {
        set_frequency(table, buffer[position], get_frequency(table, buffer[position]) + 1);
    }
    print_frequency_table(table);
    return table;
}

void print_frequency_table(struct FreqTable table) {
    for (unsigned char character = 0; character < 0xff; character++) {
        printf("%u(%c): %d\n", character, character, get_frequency(table, character));
    }
}
