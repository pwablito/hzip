#include "frequency.h"

int huffman_compress(const char* in_buffer, char* out_buffer, int size) {

    destroy_frequency_table(generate_frequencies(in_buffer, size));

    int length = 0;
    while (1) {
        if (in_buffer[length]) {
            out_buffer[length] = in_buffer[length];
            length++;
        }
        else {
            break;
        }
    }
    return length;
}