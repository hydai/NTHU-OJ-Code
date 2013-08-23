#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char str[60];
	struct node *next;
}*head, *curr, *prev;

typedef struct node Node;

void insert(char *in){
	curr = (Node*) malloc(sizeof(Node));
	strcpy(curr -> str, in);
	curr -> next = NULL;
	if(head == NULL){
		head = curr;
		return;
	}
	curr -> next = head;
	head = curr;
}

void print(int n){
	int i;
	curr = prev = head;
	for(i = 0; i < n - 1; i++){
		prev = curr;
		curr = curr -> next;
	}
	printf(curr -> str);
	if(n - 1){
		prev -> next = curr -> next;
		curr -> next = head;
		head = curr;
	}
}

int main(){
	char in[100], c, i;
	while((c = getchar()) != EOF){
		if(c == 48) return 0;
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
			i = 0;
			while((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
				in[i++] = c;
				putchar(c);
				c = getchar();
			}
			in[i] = 0;
			insert(in);
		}
		if(c >= 48 && c <= 57){
			i = 0;
			while(c >= 48 && c <= 57){
				in[i++] = c;
				c = getchar();
			}
			in[i] = 0;
			print(atoi(in));
		}
		putchar(c);
	}
	return 0;
}
