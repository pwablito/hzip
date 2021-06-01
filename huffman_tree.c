#include "huffman_tree.h"
#include <stdlib.h>
#include <assert.h>

struct HTree* combine_trees(struct HTree* tree_1, struct HTree* tree_2) {
    assert(tree_1 != NULL);
    assert(tree_2 != NULL);
    struct HTree* new_tree = calloc(1, sizeof(struct HTree));
    if (tree_1->freq <= tree_2->freq) {
        new_tree->left = tree_1;
        new_tree->right = tree_2;
    } else {
        new_tree->left = tree_2;
        new_tree->right = tree_1;
    }
    new_tree->freq = tree_1->freq + tree_2->freq;
    return new_tree;
}

struct HTree* create_leaf_tree(int freq, char data) {
    struct HTree* new_tree = calloc(1, sizeof(struct HTree));
    new_tree->freq = freq;
    new_tree->is_leaf = true;
    new_tree->leaf_data = data;
    return new_tree;
}

void destroy_tree(struct HTree* tree) {
    if (!tree->is_leaf) {
        destroy_tree(tree->left);
        destroy_tree(tree->right);
    }
    free(tree);
}