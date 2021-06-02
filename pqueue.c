#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"

struct PQueue* create_pqueue() {
    struct PQueue* queue = calloc(sizeof(struct PQueue), 1);
    return queue;
}

void destroy_pqueue(struct PQueue* queue) {
    struct PQueueNode* current_node = queue->head;
    while (current_node) {
        struct PQueueNode* next = current_node->next;
        free(current_node);
        current_node = next;
    }
    free(queue);
}

void pqueue_insert(struct PQueue* queue, void* data, const unsigned int key) {
    struct PQueueNode* node = calloc(sizeof(struct PQueueNode), 1);
    node->data = data;
    node->key = key;
    if (queue->size == 0) {
        queue->head = node;
    }
    else if (node->key < queue->head->key) {
        node->next = queue->head;
        queue->head = node;
    }
    else {
        struct PQueueNode* current_node = queue->head;
        while (1) {
            if (!current_node->next) {
                current_node->next = node;
                break;
            } else {
                if (node->key < current_node->next->key) {
                    node->next = current_node->next;
                    current_node->next = node;
                    break;
                }
                else {
                    current_node = current_node->next;
                }
            }
        }
    }
    queue->size++;
}

void* pqueue_pop(struct PQueue* queue) {
    if (queue->size == 0) {
        printf("PQUEUE ERROR: Can't pop empty queue");
        exit(1);
    }
    struct PQueueNode* node = queue->head;
    queue->head = node->next;
    void* data = node->data;
    free(node);
    queue->size--;
    return data;
}

void print_pqueue(struct PQueue* queue) {
    struct PQueueNode* current_node = queue->head;
    while (current_node) {
        printf("%u(%c): %u\n", current_node->data, current_node->data, current_node->key);
        current_node = current_node->next;
    }
}