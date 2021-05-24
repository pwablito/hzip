struct PQueueNode {
    unsigned char data;
    unsigned int key;
    struct PQueueNode* previous;
    struct PQueueNode* next;
};

// Higher keys are higher priority
struct PQueue {
    struct PQueueNode* head;
    struct PQueueNode* tail;
    int size;
};

struct PQueue* create_pqueue();

void destroy_pqueue(struct PQueue* queue);

void pqueue_insert(struct PQueue* queue, unsigned char data, unsigned int key);

unsigned char pqueue_pop(struct PQueue* queue);

void print_pqueue(struct PQueue* queue);