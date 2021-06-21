#include "huffman_tree.h"
#include "key_table.h"
#include <stdlib.h>
#include <assert.h>

struct HTree* combine_trees(struct HTree* tree_1, struct HTree* tree_2) {
    assert(tree_1 != NULL);
    assert(tree_2 != NULL);
    struct HTree* new_tree = calloc(1, sizeof(struct HTree));
    assert(new_tree);
    if (tree_1->freq <= tree_2->freq) {
        new_tree->left = tree_1;
        new_tree->right = tree_2;
    } else {
        new_tree->left = tree_2;
        new_tree->right = tree_1;
    }
    new_tree->is_leaf = false;
    new_tree->freq = tree_1->freq + tree_2->freq;
    return new_tree;
}

struct HTree* create_leaf_tree(unsigned int freq, char data) {
    struct HTree* new_tree = calloc(1, sizeof(struct HTree));
    assert(new_tree);
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

void insert_tree_to_table(struct HTree* tree, struct KeyTable table, unsigned int prefix_data, unsigned int prefix_length) {
    if (tree->is_leaf) {
        // assert(!tree->left);
        if (tree->left || tree->right) {
            assert(0);
        }
        set_key_table_value(table, tree->leaf_data, prefix_data, prefix_length);
    } else {
        unsigned int next_data = prefix_data << 1;
        insert_tree_to_table(tree->left, table, next_data, prefix_length + 1);
        insert_tree_to_table(tree->right, table, next_data|1, prefix_length + 1);
    }

}

struct KeyTable convert_tree_to_keys(struct HTree* tree) {
    struct KeyTable table = create_key_table();
    insert_tree_to_table(tree, table, 0, 0);
    return table;
}