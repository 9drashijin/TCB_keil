#ifndef  __LINKED_LIST_H__
#define  __LINKED_LIST_H__

#include <stdint.h>

typedef struct Element_t{
	struct Element_t *next;
	uint32_t data;
}Element;

typedef struct {
	Element *head;
	Element *tail;
	uint32_t length;
}LinkedList;

LinkedList *createLinkedList();
void List_addFirst(LinkedList *list, Element *elem);
Element *List_removeFirst(LinkedList *list);
void List_addLast(LinkedList *list, Element *elem);
Element *List_removeLast(LinkedList *list);

#endif //__LINKED_LIST_H__
