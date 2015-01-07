/* implement queue with linked list */
/* Author: Peiwen Chen */
/* Date: Jan 5 2015 */


/*create a queue */

QUEUE *
queue_init(void) {
    QUEUE *q = malloc(sizeof(QUEUE));
    q->count = 0;
    q->head = NULL;
    q->tail = NULL;
    /* caller should free this queue */
    return q;
}

/* return 1 if a queue is empty */
bool 
queue_empty(QUEUE *q) {
    return q->count == 0;
}

/* return 1 if a queue is full; */
bool 
queue_full(QUEUE *q) {
    return q->count == MAX - 1;
}

/* determine the size of queue */
int 
queue_get_size(QUEUE *q) {
    return q->count;
}

void
enqueue(QUEUE *q, QNODE *node) {
    
    if (queue_full(q)) {
		printf("queue is full!");
		return NULL;
    }
    q->tail->next = node;
    q->tail = node;

    return;
}

QNODE *node 
dequeue(QUEUE *q ) {
    if (queue_empty(q)) {
		printf("queue is empty !");
		return NULL;
    }
    QNODE *node = q->head;
	/* node in the queue is in the heap */
    node->data = q->head->data;
    node->prev = NULL;
    node->next = NULL;
	/* caller should free this dequeued node */
    return node;
}

/* remove the entry at front of a queue */
void 
queue_remove(QUEUE *q) {
    if (queue_empty(q)) {
		printf("queue is null !");
		return NULL;
    }
    NODE *node = q->head;
    q->head = q->head->next;
    free(node);
    return ;
}

/* clear a queue */
void queue_clear (QUEUE *q) {
    if(queue_empty(q)) {
		printf("queue is empty !");
		return NULL; 
    }

    NODE *node = head;
    for (; node->next != NULL; node = node->next) {
		node->data = NULL;
    }
    return;
}

void queue_destroy(QUEUE *q) {
    NODE *node = NULL;

    while (head->next != NULL) {
		node = q->head;
		free(node);
		q->head = q->head->next;
    }
    node = q->head;
    free(node);
    q->head = q->tail = NULL;
    
    return ;
}

