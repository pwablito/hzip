#include <stdbool.h>

struct HTree {
    struct HTree* left;
    struct HTree* right;
    unsigned int freq;
    bool is_leaf;
    char leaf_data;
};

struct HTree* combine_trees(struct HTree* tree_1, struct HTree* tree_2);
struct HTree* create_leaf_tree(unsigned int freq, char data);
void destroy_tree(struct HTree* tree);
