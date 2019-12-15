#include <stdio.h>

typedef struct {
	char id[20];
	char name[50];
	float score;
} Student;

int main(){
	Student stu[10];
	int n, i;
	float avg = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", stu[i].id);
		scanf("%s", stu[i].name);
		scanf("%f", &stu[i].score);
		avg += stu[i].score;
	}
	avg /= n;
	printf("%.2f", avg);
	return 0;
} 
