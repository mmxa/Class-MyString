#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINKNODE {
	void* data;
	struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST {
	LinkNode* head;
	int size;
}LinkList;

typedef void(*PRINTLINKNODE)(void*);

LinkList* Init_LinkList();

void Insert_LinkList(LinkList* list, int pos, void* data);

void RemoveByPos_LinkList(LinkList* list, int pos);

int Size_LinkList(LinkList* list);

void* Front_LinkList(LinkList* list);

int Find_LinkList(LinkList* list, void* data);

void Print_LinkList(LinkList* list, PRINTLINKNODE print);

void FreeSpace_LinkList(LinkList* list);
#endif