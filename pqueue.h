struct PQueueNode {
    void* data;
    unsigned int key;
    struct PQueueNode* next;
};

// Higher keys are higher priority
struct PQueue {
    struct PQueueNode* head;
    int size;
};

struct PQueue* create_pqueue();

void destroy_pqueue(struct PQueue* queue);

void pqueue_insert(struct PQueue* queue, void* data, unsigned int key);

void* pqueue_pop(struct PQueue* queue);

void print_pqueue(struct PQueue* queue);