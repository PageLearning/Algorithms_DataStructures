
#ifndef __BSTREE_H__
#define __BSTREE_H__

/* binary search tree implementation */

typedef bstnode {
	int data;
	BSTNODE *leftchild;
	BSTNODE *rightchild;
}BSTNODE;

typedef bstree {
	int count; /* count of nodes */
	BSTNODE *root;
}BSTREE;

BSTNODE* FindBSTNODE(BSTNODE *root, int data);

BSTNODE * FindParent(BSTNODE *root, int data);
/* 
* insert data into a BSTREE.
* allocate and memset the node on the heap.
* if the inseted data is a duplicate: insert it to right
*/
BSTNODE* Insert(BSTNODE * root, int data); 
void InsertBSTNODE(BSTNODE *root, int data);

BSTNODE * DeleteBSTNODE(BSTNODE *root, int data);

void Preorder_tree(BSTNODE *node);

/* traversal by level */
void Breadth_First(BSTNODE *root);


#endif
