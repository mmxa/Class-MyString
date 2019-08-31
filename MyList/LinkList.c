#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"


LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	list->size = 0;
	return list;
}

void Insert_LinkList(LinkList* list, int pos, void* data) {
	if (list == NULL || data==NULL)
		return;
	if (pos<0 || pos > list->size) {
		pos = list->size;
	}
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->next = NULL;
	newnode->data = data;
	LinkNode* temp = list->head;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	list->size++;
}


void RemoveByPos_LinkList(LinkList* list, int pos) {
	if (list == NULL)
		return;
	if (pos<0 || pos > list->size) 
		return;
	LinkNode* temp = list->head;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	LinkNode* pdel = temp->next;
	temp->next = pdel->next;
	free(pdel);
	list->size--;
}

int Size_LinkList(LinkList* list){
	return list->size;
}
void* Front_LinkList(LinkList* list)
{
	return list->head->next;
}
int Find_LinkList(LinkList* list, void* data){
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	LinkNode* temp = list->head->next;
	int res=0;
	while (temp->next!=NULL) {
		if (temp->data == data)
			break;
		temp = temp->next;
		res++;
	}

	return res;
}

void Print_LinkList(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
		return;
	LinkNode* temp = list->head->next;
	while (temp != NULL) {
		print(temp->data);
		temp = temp->next;
	}

}
void FreeSpace_LinkList(LinkList* list) {
	if (list == NULL)
		return;
	LinkNode* temp = list->head;
	while (temp != NULL)
	{
		LinkNode* pnext = temp->next;
		free(temp);
		temp = pnext;

	}
}

