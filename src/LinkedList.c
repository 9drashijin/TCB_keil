#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void List_addFirst(LinkedList *list, Element *elem){
	if(list->head == NULL && list-> tail == NULL){
		list->head = elem;
		list->tail = elem;
		list->tail->next = NULL;
	}
	else{
		elem->next = list->head;
		list->head = elem;
	}
	if(elem == NULL)
		list->length = 0;
	else
		list->length++;
}

void List_addLast(LinkedList *list, Element *elem){
	Element *cPtr;
	cPtr = list->head;

	if(list->head == NULL && list-> tail == NULL){
		list->head = elem;
		list->tail = elem;
	}

	if(list->head != list->tail){
		cPtr = cPtr->next;
		while(cPtr != list->tail){
			cPtr = cPtr->next;
		}

		if(cPtr == list->tail){
		  list->tail = elem;
		  cPtr->next = elem;
		}
	}
	else if(list->head == list->tail){
		list->head->next = elem;
		list->tail = elem;
	}

	list->length++;
}

Element *List_removeFirst(LinkedList *list){

	Element *tempElem;
	tempElem = list->head;

	if(list->head == NULL && list-> tail == NULL)
		return NULL;

	else if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}
	else{
		 list->head = list->head->next;
		 list->tail->next = NULL;
	}
	list->length--;

	return tempElem;
}

Element *List_removeLast(LinkedList *list){

	Element *tempElem, *cPtr;
	tempElem = list->head;
	cPtr = list->head;

	if(list->head == NULL && list-> tail == NULL){
		return NULL;
	}
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}
	else{
		while(cPtr->next != list->tail)
			cPtr = cPtr->next;

		if(cPtr->next == list->tail){
		  list->tail = cPtr;
		  list->tail->next = NULL;
		}
	}
	list->length--;

	return tempElem;
}
