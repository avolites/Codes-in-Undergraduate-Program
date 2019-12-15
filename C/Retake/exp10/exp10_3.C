#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int a;
	struct Node * next;
} *LinkedList, Node;

int isEven(int n){
	if(n % 2 == 0)
		return 1;
	return 0;
}

int main(){
	LinkedList list, p;
	int n;
	list = (LinkedList) malloc(sizeof(Node));
	list->next = NULL;
	p = list;
	while(1){
		scanf("%d", &n);
		if(n < 0)
			break;
		LinkedList tempNode = (LinkedList) malloc(sizeof(Node));
		tempNode->a = n;
		tempNode->next = NULL;
		p->next = tempNode;
		p = p->next;
	}
	LinkedList curr, previous;
	previous = list;
	curr = list->next;
	while(curr && previous){
		if(isEven(curr->a)){
			previous->next = curr->next;
		}
		else{
			previous = previous->next;
		}
		curr = 	curr->next;
	}
	p = list->next;
	while(p){
		printf("%d ", p->a);
		p = p->next;
	}
	return 0;
}
