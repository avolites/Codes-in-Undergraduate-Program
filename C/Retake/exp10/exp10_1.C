#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char id[20];
	char name[50];
	int score;
} Student;

typedef struct StudentLinkedList{
	Student stu;
	struct StudentLinkedList *next;
} StuListNode, *StuList;

int setStuInfo(Student *stu){
	scanf("%s", stu->id);
	if(!strcmp(stu->id, "0"))
		return 0;
	scanf("%s", stu->name);
	scanf("%d", &stu->score);
	return 1;
}

void printStuInfo(Student *stu){
	printf("%s %s %d\n", stu->id, stu->name, stu->score);
}

int main(){
	StuList list;	//linked list
	StuList p;
	int threshold;
	list = (StuList) malloc(sizeof(StuListNode));
	p = list;
	while(1){
		StuList node = (StuList) malloc(sizeof(StuListNode));
		node->next = NULL;
		if(!setStuInfo(&node->stu))
			break;
		p->next = node;
		p = node;
	}
	scanf("%d", &threshold);
	p = list;
	while(p->next){
		if(p->next->stu.score >= threshold)
			printStuInfo(&p->next->stu);
		p = p->next;
	}
	return 0;
}
