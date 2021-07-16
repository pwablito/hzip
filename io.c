#include "io.h"
#include "key_table.h"

int write_key_table(unsigned char* buffer, struct KeyTable table) {
    for (unsigned int i = 0; i < 0x100; i++) {
        buffer[3 * i] = (char)i;
        buffer[(3 * i) + 1] = lookup_bit_length(table, (char)i);
        buffer[(3 * i) + 2] = lookup_table_value(table, (char)i);
    }
    // TODO return the number of bytes written
    return 0;
}

int write_compressed_buffer(unsigned char* buffer, struct KeyTable table, unsigned char* input, int size) {
    // Write bits to output buffer
    int bytes_written = 0;
    unsigned char output_byte = (unsigned char) 0;
    for (unsigned int input_buffer_position = 0; input_buffer_position < size; input_buffer_position++) {
        int bit_length = lookup_bit_length(table, input[input_buffer_position]);
        int value = lookup_table_value(table, input[input_buffer_position]);
        // Write `bit_length` bits of `value` to output buffer
        // This code doesn't work yet: needs further alignment within byte boundaries (currently writes only one table value per byte)
        for (int i = 0; i < bit_length; i++) {
            output_byte = (output_byte << 1) | (value & 1);
            value = value >> 1;
        }
        // Write output_byte to output buffer
        buffer[bytes_written++] = output_byte;
        output_byte = (unsigned char) 0;
    }
    return bytes_written;

}
