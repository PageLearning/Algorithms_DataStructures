
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




#endif
