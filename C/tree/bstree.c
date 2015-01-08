
/* binary search tree basic operations
* Author: Peiwen Chen
* Date: Oct 26th, 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"
#include "bstree.h"

BSTNODE* FindBSTNODE(BSTNODE *root, int data) {
	if (!root) {
		return NULL;
	}
	if (data == root->data) {
		return root;
	} else if (data < root->data) {
		return FindBSTNODE(root->leftchild, data);
	} else { 
		return FindBSTNODE(root->rightchild, vlaue);
	}
}

BSTNODE * FindParent(BSTNODE *root, int data) {
	if (!root) {
		return NULL;
	}
	if (data == root->data) {
		return NULL;
	} else if (data < root->data) {
		if ((root->leftchild) && (root->lchild->data == data)) 
			return root;
		else 
			return FindParent(root->leftchild, data);
	} else {
		if ((root->rightchild) && (root->rchild->data == data)) 
			return root;
		else
			return FindParent(root->rightchild, data);
	}
}

/* 
* insert data into a BSTREE.
* allocate and memset the node on the heap.
* if the inseted data is a duplicate: insert it to right
*/
BSTNODE* Insert(BSTNODE * root, int data) {
	if (!root) {
		BSTNODE *newnode = (BSTNODE *)malloc(sizeof(BSTNODE));
		newnode->data = data;
		return newnode;
	}
	InsertBSTNODE(root, data);
	return root;
}

void InsertBSTNODE(BSTNODE *root, int data) {
	if (data < root->data) {
		if (root->leftchild) 
			InsertBSTNODE(root->leftchild, data);
		else {
			// allocate a new node on heap and memset
			BSTNODE *newnode = (BSTNODE *) malloc(sizeof(BSTNODE));
			memset(newnode, 0, sizeof(BSTNODE));
			newnode->data = data;
			root->leftchild = newnode;
		}
	} else if(data > root->data) {
		if (root->rightchild){
			InsertBSTNODE(root->rightchild, data);
		}
		else {
			// allocate a new node and memset 
			BSTNODE *newnode = (BSTNODE *) malloc(sizeof(BSTNODE));
			memset(newnode, 0, sizeof(BSTNODE));
			newnode->data = data;
			root->rightchild = newnode;
		}
	} else { // duplicate
		BSTNODE *newnode = (BSTNODE *)malloc(sizeof(BSTNODE));
        memset(newnode, 0, sizeof(BSTNODE));
        if (root->rightchild) {
			newnode->rightchild = root->rightchild;
		}
        root->rightchild = newnode;
	}
} 

BSTNODE * DeleteBSTNODE(BSTNODE *root, int data) {
	if (!root){
		return NULL;
	}
	BSTNODE *node2del = (BSTNODE *)malloc(sizeof(BSTNODE));
	memset(node2del, 0, sizeof(BSTNODE));
	BSTNODE *parent = (BSTNODE *)malloc(sizeof(BSTNODE));
	memset(parent, 0, sizeof(BSTNODE));

	// find node and parent

	if (!node2del->leftchild && !node2del->rightchild) {
		parent->leftchild = NULL;
		parent->rightchild = NULL;
		free(node2del);
	} else if (!node2del->leftchild && node2del->rightchild) {
		if (parent->leftchild == node2del) 
			parent->leftchild = node2del->rightchild;
		else
			parent->rightchild = node2del->rchild;
		free(node2del);
	} else if (node2del->leftchild && !node2del->rightchild) {
		if (parent->leftchild == node2del) 
			parent->leftchild = node2del->lchild;
		else
			parent->rightchild = node2del->leftchild;
		free(node2del);
	} else { // node has leftchild and rightchild 
		BSTNODE * largest = node->leftchild;
		BSTNODE * largestparent = node;
		// find the largest and its parent in left subtree
		while (largest->rightchild) {
			largestparent = largest;
			largest = largest->rightchild;
		}
		node->data = largest->data;
		// delete the largest node
		if (largest->leftchild) 
			largestparent->rightchild = largest->leftchild;
		else 
			largestparent->rightchild = NULL;
		free(largest);
	}
}

void Preorder_tree(BSTNODE *node) {

    if (!node) {
		return;
    }
    /* callback function traversal */
    printf("node data: %d\n", node->data);
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
