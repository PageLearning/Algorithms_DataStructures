
/*LinkedList.h
**Declarations for LinkedList
*/

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

extern struct Node;

typedef struct Node* PtNode;
typedef PtNode List;

int IsEmpty(List l);
int IsLast(PtNode p);
void Insert(List l, int key, PtNode p);
void Delet(List l, int key);//delete the key
void DeletList(List l);
int MakeEmpty(List l);
PtNode Find(List l, int key);//find the key
PtNode FindPrevious(List l, int key);


#endif