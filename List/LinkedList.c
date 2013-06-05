/*LinkedList.h
**Implementations for LinkedList
*/

#include <stdio.h>
#include "LinkedList.h"


int IsEmpty(List l)
{
  return (l== NULL);
}

int IsLast(PtNode p)
{
  return (p->next == NULL); 
}

void Insert(List l, int key, PtNode p)
{
  if (l == NULL) return;
  else
  {  
    PtNode pt=l->next;
    PtNode q=(PtNode)malloc(sizeof(struct Node));
    while(pt->next!=p)
    {
      pt=pt->next;
    }
    q->data=key;
    pt->next=q;
    q->next=p->next;
    
  }  
}

void Delet(List l, int key)
{
  if (l == NULL) return;
  else 
  {
    PtNode p = l->next;
    PtNode prev = p;
    while(p->next != NULL && p->data != key)
      { prev=p;  
        p=p->next;
      } 
    prev->next=p->next;
    free(p);
  }
}
int MakeEmpty(List l)
{
  return l=NULL;
}

PtNode Find(List l, int key)
{
  if (l == NULL)
    return NULL;
  else 
  {  
    PtNode p = l->next;
    while(p->next!= NULL && p->data != key)
      p=p->next;
    return p;
  }
}

void DeletList(List l)
{
  if (l==NULL) return;
  else 
  {
    PtNode p,q;
    l->next=NULL;
    p=l;
    while(p->next!=NULL)
    {
      q=p;
      free(p);
      p=q->next;      
    }
  
  }
}

PtNode FindPrevious(List l, int key)
{}
