#include "avl/avl.h"

static unsigned int
subtree_cardinality(
    struct avl_el const* subtree
) {
    if(!subtree) {
        return 0;
    }

    return subtree_cardinality(subtree->l) +
            subtree_cardinality(subtree->r) +
            ll_count(&subtree->ll);
}

unsigned int
avl_cardinality(
    struct avl const* avl
) {
    if(!avl) {
        return 0;
    }

    return subtree_cardinality(avl->root);
}
