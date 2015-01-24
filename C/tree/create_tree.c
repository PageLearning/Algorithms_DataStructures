/* given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
* create a binary search tree, # of left = # of right
* Author: Peiwen Chen
* Date: Jan 19, 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bstnode {
	int data;
	struct bstnode *leftchild;
	struct bstnode *rightchild;
}BSTNODE;

typedef struct bstree {
	int count; /* count of nodes */
	BSTNODE *root;
}BSTREE;
void PreorderTree(BSTNODE *);
void BinaryInsert(int *, int, int, BSTNODE*);
BSTNODE* CreateBST(int *, int);

/* given a sorted array and its len */
BSTNODE* CreateBST(int array[], int len) {
	int low = 0;
	int high = len - 1;
	int mid = (low+high)/2;

	BSTNODE * root = (BSTNODE *)malloc(sizeof(BSTNODE));
	memset(root, 0, sizeof(BSTNODE));
	root->data = array[mid];	
	
	BinaryInsert(array, low, mid-1, root);
	BinaryInsert(array, mid+1, high, root);
	return root;
}

/*
 * create a node between low and high, append it to existing root node 
 */
void BinaryInsert(int array[], int low, int high, BSTNODE *root) {
	if (low > high) {
		return;
	}
	int mid = (low+high)/2;
	printf("low:%d, high:%d, mid:%d\n", low,high,mid);

	if (!root) {
		printf("root is NULL\n");
		return;
	} else {
		BSTNODE * newnode = (BSTNODE *)malloc(sizeof(BSTNODE));
		memset(newnode, 0, sizeof(BSTNODE));
		newnode->data = array[mid];
		
		if (newnode->data < root->data) {
			printf("newnode->data:%d, go to left\n",newnode->data);
			root->leftchild = newnode;
		}
		else {
		    printf("newnode->data:%d, go to right\n",newnode->data);	
			root->rightchild = newnode;
		}

		root = newnode;
	}
	BinaryInsert(array, low, mid-1, root);
	BinaryInsert(array, mid+1, high, root);
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

int main(void) {
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("starting to create a tree given an array \n");
	BSTNODE *root = CreateBST(array, 10);
	Preorder_tree(root);
	printf("preorder done \n");
	return 0;
}


