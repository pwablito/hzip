#include <assert.h>
#include "pqueue.h"

int main(int argc, char** argv) {
    struct PQueue* queue = create_pqueue();
    pqueue_insert(queue, 'a', 0);
    pqueue_insert(queue, 'b', 10);
    pqueue_insert(queue, 'c', 20);
    pqueue_insert(queue, 'd', 5);
    pqueue_insert(queue, 'e', 6);
    pqueue_insert(queue, 'f', 4);
    pqueue_insert(queue, 'g', 8);
    pqueue_insert(queue, 'h', 30);
    assert(pqueue_pop(queue) == 'a');
    assert(pqueue_pop(queue) == 'f');
    assert(pqueue_pop(queue) == 'd');
    assert(pqueue_pop(queue) == 'e');
    assert(pqueue_pop(queue) == 'g');
    assert(pqueue_pop(queue) == 'b');
    assert(pqueue_pop(queue) == 'c');
    assert(pqueue_pop(queue) == 'h');
    destroy_pqueue(queue);
    return 0;
}