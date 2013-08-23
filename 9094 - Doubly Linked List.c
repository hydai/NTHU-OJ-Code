#include <stdio.h>
#include <stdlib.h>

struct node{
	int num;
	struct node *prev;
	struct node *next;
}*head, *middle, *tail, *temp;

typedef struct node Node;

int tot;

void IH(int n){
	temp = (Node*) malloc(sizeof(Node));
	temp -> num = n;
	temp -> prev = NULL;
	temp -> next = NULL;
	if(head == NULL){
		head = tail = middle = temp;
		tot++;
		return;
	}
	head -> prev = temp;
	temp -> next = head;
	head = temp;
	tot++;
	if(tot == 2)
		middle = head;
	else if(tot % 2)
		middle = middle -> prev;
}

void IT(int n){
	temp = (Node*) malloc(sizeof(Node));
	temp -> num = n;
	temp -> prev = NULL;
	temp -> next = NULL;
	if(tail == NULL){
		tail = head = middle = temp;
		tot++;
		return;
	}
	temp -> prev = tail;
	tail -> next = temp;
	tail = temp;
	tot++;
	if(tot == 2)
		middle = head;
	else if(tot % 2 == 0)
		middle = middle -> next;
}

void RH(){
	if(tot == 0)
		return;
	printf("%d\n", head -> num);
	if(tot == 1){
		free(head);
		head = tail = middle = NULL;
		tot--;
		return;
	}
	temp = head -> next;
	temp -> prev = NULL;
	free(head);
	head = temp;
	tot--;
	if(tot == 1)
		middle = tail;
	else if(tot == 2)
		middle = head;
	else if(tot % 2 == 0)
		middle = middle -> next;
}

void RT(){
	if(tot == 0)
		return;
	printf("%d\n", tail -> num);
	if(tot == 1){
		free(tail);
		head = tail = middle = NULL;
		tot--;
		return;
	}
	temp = tail -> prev;
	temp -> next = NULL;
	free(tail);
	tail = temp;
	tot--;
	if(tot == 1)
		middle = head;
	else if(tot == 2)
		middle = head;
	else if(tot % 2)
		middle = middle -> prev;
}

void S(){
	if(tot == 0)
		return;
	head -> prev = tail;
	tail -> next = head;
	temp = middle;
	if(tot % 2)
		middle = tail -> prev;
	else
		middle = tail;
	head = temp -> next;
	head -> prev = NULL;
	tail = temp;
	tail -> next = NULL;
}
/*
void print(){
	temp = head;
	while(temp != NULL)
		printf("%d ", temp -> num), temp = temp -> next;
	putchar(10);
	if(middle != NULL)
		printf("middle num = %d\n", middle -> num);
}
*/
int main(){
	int num;
	char cmd[3];
	while(scanf("%s", cmd) > 0){
		if(cmd[0] == 'I'){
			scanf("%d", &num);
			if(cmd[1] == 'H')
				IH(num);
			else
				IT(num);
		}
		else if(cmd[0] == 'R'){
			if(cmd[1] == 'H')
				RH();
			else
				RT();
		}
		else
			S();
/*		print();*/
	}
	return 0;
}
