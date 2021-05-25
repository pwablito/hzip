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

void pqueue_insert(struct PQueue* queue, const unsigned char data, const unsigned int key) {
    struct PQueueNode* node = calloc(sizeof(struct PQueueNode), 1);
    node->data = data;
    node->key = key;
    if (queue->size == 0) {
        queue->head = node;
        queue->tail = node;
    }
    else {
        struct PQueueNode* current_node = queue->tail;
        while (1) {
            if (!current_node) {
                node->next = queue->head;
                queue->head->previous = node;
                queue->head = node;
                break;
            } else {
                if (current_node->key <= key) {
                    node->next = current_node->next;
                    node->previous = current_node;
                    if (node->next) {
                        node->next->previous = node;
                    }
                    current_node->next = node;
                    break;
                }
                else {
                    current_node = current_node->previous;
                }
            }
        }
    }
    queue->size++;
    print_pqueue(queue);
    printf("---------\n");
}

unsigned char pqueue_pop(struct PQueue* queue) {
    if (queue->size == 0) {
        printf("PQUEUE ERROR: Can't pop empty queue");
        exit(1);
    }
    queue->size--;
    struct PQueueNode* node = queue->head;
    queue->head = node->next;
    if (node->next) {
        node->next->previous = NULL;
    }
    if (queue->size == 0) {
        queue->tail = NULL;
    }
    unsigned char data = node->data;
    free(node);
    return data;
}

void print_pqueue(struct PQueue* queue) {
    struct PQueueNode* current_node = queue->head;
    while (current_node) {
        printf("%u(%c): %u\n", current_node->data, current_node->data, current_node->key);
        current_node = current_node->next;
    }
}