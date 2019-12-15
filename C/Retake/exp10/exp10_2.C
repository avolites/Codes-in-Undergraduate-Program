#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int a;
	struct Node *next;
} *LinkList, ListNode;

int main(){
	LinkList list, p;
	int n;
	list = NULL;
	while(1){
		scanf("%d", &n);
		if(n <= -1)
			break;
		LinkList tempNode = (LinkList) malloc(sizeof(ListNode));
		tempNode->a = n;
		tempNode->next = list;
		list = tempNode;
	}
	p = list;
	while(p){
		printf("%d ", p->a);
		p = p->next;
	}
	return 0;
}
