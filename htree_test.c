#include <assert.h>
#include "huffman_tree.h"
#include "pqueue.h"

int main(int argc, char** argv) {

    // Run huffman tree algorithm- this depends on a functioning pqueue

    struct PQueue* queue = create_pqueue();

    pqueue_insert(queue, create_leaf_tree(10, 'a'), 10);
    pqueue_insert(queue, create_leaf_tree(10, 'b'), 9);
    pqueue_insert(queue, create_leaf_tree(10, 'c'), 8);
    pqueue_insert(queue, create_leaf_tree(10, 'd'), 7);
    pqueue_insert(queue, create_leaf_tree(10, 'e'), 6);
    pqueue_insert(queue, create_leaf_tree(10, 'f'), 5);
    pqueue_insert(queue, create_leaf_tree(10, 'g'), 4);
    pqueue_insert(queue, create_leaf_tree(10, 'h'), 3);
    pqueue_insert(queue, create_leaf_tree(10, 'i'), 2);
    pqueue_insert(queue, create_leaf_tree(10, 'j'), 1);

    while (queue->size > 1) {
        struct HTree* new_tree = combine_trees(pqueue_pop(queue), pqueue_pop(queue));
        pqueue_insert(queue, new_tree, new_tree->freq);
    }

    struct HTree* tree = pqueue_pop(queue);

    assert(!tree->is_leaf);
    assert(!tree->left->is_leaf);
    assert(tree->left->left->left->leaf_data == 'c');



    return 0;
}