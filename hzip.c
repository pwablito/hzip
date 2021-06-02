#include <string.h>
#include <assert.h>
#include "frequency.h"
#include "pqueue.h"
#include "huffman_tree.h"

int huffman_compress(unsigned char* in_buffer, unsigned char* out_buffer, int size) {

    struct FreqTable table = generate_frequencies(in_buffer, size);
    struct PQueue* queue = create_pqueue();
    for (unsigned int character = 0; character < 0x100; character++) {
        unsigned int frequency = get_frequency(table, character);
        if (frequency) {
            struct HTree* tree = create_leaf_tree(frequency, character);
            pqueue_insert(queue, tree, frequency);
        }
    }

    while (queue->size > 1) {
        struct HTree* new_tree = combine_trees(pqueue_pop(queue), pqueue_pop(queue));
        pqueue_insert(queue, new_tree, new_tree->freq);
    }

    struct HTree* tree = pqueue_pop(queue);
    assert(queue->size == 0);

    // Traverse tree and fill in key table
    struct KeyTable key_table = convert_tree_to_keys(tree);

    destroy_key_table(key_table);
    destroy_pqueue(queue);
    destroy_frequency_table(table);

    //TODO remove this and write compressed buffer into output
    memcpy(out_buffer, in_buffer, size);

    return size;
}