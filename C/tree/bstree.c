
#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"

void traversal(BSTNODE *node) {
	printf("node data: %d\n", node->data);
}

void
Preorder_tree(BSTNODE *node) {

    if (!node) {
	return;
    }
    /* callback function traversal */
    traversal(node);
    Preorder_tree(node->leftchild);
    Preorder_tree(node->rightchild);

}

/* traversal by level */
void Breadth_First(BSTNODE *root) {
    
    if (!root) {
	return;
    }

    QUEUE *q = queue_init();
	QNODE *node = malloc(sizeof(QNODE));
	node->data = root;
	/* enqueue the root node */
    enqueue(q, node);

    while (!queue_empty(q)) {
		QNODE *qnode = dequeue(q);
		traversal(qnode);
		free(qnode);
		QNODE *leftnode = malloc(sizeof(QNODE));
		QNODE *rightnode = malloc(sizeof(QNODE));
		leftnode->data = root->leftchild;
		rightnode->data = root->rightchild;
		enqueue(q, leftnode);
		enqueue(q, rightnode);
    }
    return;
}

