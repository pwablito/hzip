#include <string.h>
#include "frequency.h"
#include "pqueue.h"

int huffman_compress(unsigned char* in_buffer, unsigned char* out_buffer, int size) {

    struct FreqTable table = generate_frequencies(in_buffer, size);
    struct PQueue* queue = create_pqueue();
    for (unsigned int character = 0; character <= 0xff; character++) {
        unsigned int frequency = get_frequency(table, character);
        if (frequency) {
            pqueue_insert(queue, character, frequency);
        }
    }

    print_pqueue(queue);
    
    destroy_pqueue(queue);
    destroy_frequency_table(table);

    //TODO remove this and write compressed buffer into output
    memcpy(out_buffer, in_buffer, size);

    return size;
}