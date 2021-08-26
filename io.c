#include "io.h"
#include "key_table.h"

int write_key_table(unsigned char* buffer, struct KeyTable table) {
    // TODO optimize this
    memcpy(buffer, table.table, 0x100 * sizeof(struct KeyTableEntry));
    return (0x100 * sizeof(struct KeyTableEntry)) * 8;
}

int read_key_table(unsigned char* buffer, struct KeyTable* table) {
    // TODO optimize this
    memcpy(table->table, buffer, 0x100 * sizeof(struct KeyTableEntry));
    return (0x100 * sizeof(struct KeyTableEntry)) * 8;
}

int write_compressed_buffer(unsigned char* buffer, struct KeyTable table, unsigned char* input, int size) {
    unsigned int buffer_pos = 0;
    unsigned int input_pos = 0;
    unsigned char current_chunk = 0;
    unsigned int current_chunk_filled = 0;
    while (input_pos < size) {
        unsigned int encoded_length = lookup_bit_length(table, input[input_pos]);
        unsigned int encoded_value = lookup_table_value(table, input[input_pos]);
        for (unsigned int current_value_pos = 0; current_value_pos < encoded_length; current_value_pos++) {
            current_chunk<<=1;
            current_chunk |= (encoded_value >> (encoded_length - current_value_pos - 1)) & 1;
            current_chunk_filled++;
            if (current_chunk_filled == 8) {
                buffer[buffer_pos] = current_chunk;
                current_chunk = 0;
                current_chunk_filled = 0;
                buffer_pos++;
            }
        }
        input_pos++;
    }
    if (current_chunk_filled > 0) {
        buffer[buffer_pos] = current_chunk;
        buffer_pos++;
    }
    return (buffer_pos * 8) + current_chunk_filled;
}

int read_compressed_buffer(unsigned char* buffer, struct KeyTable table, unsigned char* output, int size) {
    printf("Not implemented");
    return 0;
}