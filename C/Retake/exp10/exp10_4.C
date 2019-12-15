#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
	int a;
	struct LinkedList *next;
} Node, *List;

int main(){
	List list = NULL, ptr, node;
	int n;
	//create a linked list without the head blank node
	scanf("%d", &n);
	if(n > -1){
		node = (List)malloc(sizeof(Node));
		node->a = n;
		node->next = NULL;
		list = node;
		ptr = list;
		while(1){
			scanf("%d",&n);
			if(n < 0)
				break;
			node = (List)malloc(sizeof(Node));
			node->a = n;
			node->next = NULL;
			ptr->next = node;
			ptr = ptr->next;
		}
		//reverse the linked list
		List p1, p2, p3;
		if(list != NULL){
			p1 = list;
			p2 = list->next;
			if(p2 != NULL){
				p3 = p2->next;
				p1->next = NULL;
				p2->next = p1;
				if(p3 != NULL){
					while(1){
						p1 = p2;
						p2 = p3;
						p3 = p3->next;
						p2->next = p1;
						if(p3 == NULL)
							break;
					}	//while
				}	//if p3 != NULL
				list = p2;
			}	// if p2 != NULL
		}
		//print the reversed linked list 
		ptr = list;
		while(ptr){
			printf("%d ", ptr->a);
			ptr = ptr->next;
		}
	}
	return 0;
}
