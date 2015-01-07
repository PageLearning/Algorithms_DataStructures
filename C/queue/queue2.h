

#ifndef __QUEUE2_H__
#define __QUEUE2_H__

/*
 * Linked List implemented Queue
 */

#include <stdlio.h>
#include <stdlib.h>

typedef MAX 999;

typedef struct node {
    void *data;
    QNODE *prev;
    QNODE *next;
} QNODE;

typedef struct queue {
    int count; /* queue node count */
    QNODE *head;
    QNODE *tail;
}QUEUE;


/* init a queue */
extern QUEUE * queue_init(void);
/* return 1 if queue is empty */
extern bool queue_empty(QUEUE *); 
/* return 1 if queue is full; */
extern bool queue_full(QUEUE *);
/* determine the size of queue */
extern int queue_get_size(QUEUE *);
/* append a new entry to a queue */
extern void enqueue(QUEUE *, QNODE *);
/* remove the entry at front of a queue */
extern void queue_remove(QUEUE *);
extern QNODE * dequeue(QUEUE *);
/* clear a queue */
extern void queue_clear (QUEUE *);
/* destroy a queue */
extern void queue_destroy(QUEUE *); 


#endif

