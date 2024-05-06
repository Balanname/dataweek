#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // 노드 타입을 구조체로 정의한다.
	char name[100];
} element;


typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;


void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data);
	printf("NULL \n");
}

// 맨 앞에 노드 삽입
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	strcpy(p->data.name, value.name);
	p->link = head;
	head = p;
	return head;
}

int main() {
	ListNode* head = NULL;
	element data;
	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);
	return 0;
}