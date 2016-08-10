#ifndef  __LINKED_LIST_H__
#define  __LINKED_LIST_H__

#include <stdint.h>
#include "TCB.h"

typedef struct Element_t{
	struct Element_t *next;
	uint32_t data;
}Element;

typedef struct {
	Tcb *head;
	Tcb *tail;
	uint32_t length;
}LinkedList;

extern LinkedList *list;

LinkedList *createLinkedList();
void List_addFirst(LinkedList *list, Tcb *elem);
Tcb *List_removeFirst(LinkedList *list);
void List_addLast(LinkedList *list, Tcb *elem);
Tcb *List_removeLast(LinkedList *list);

#endif //__LINKED_LIST_H__
