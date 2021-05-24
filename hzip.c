#include "frequency.h"
#include "pqueue.h"

int huffman_compress(const char* in_buffer, char* out_buffer, int size) {

    struct FreqTable table = generate_frequencies(in_buffer, size);
    struct PQueue* queue = create_pqueue();
    for (unsigned char character = 0; character < 0xff; character++) {
        unsigned int frequency = get_frequency(table, character);
        if (frequency) {
            pqueue_insert(queue, character, frequency);
        }
    }
//    print_frequency_table(table);
    print_pqueue(queue);
    destroy_pqueue(queue);
    destroy_frequency_table(table);

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