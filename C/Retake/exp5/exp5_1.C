#include <stdio.h>

int main(){
	int a[10], i, j, flag, flag2 = 0;
	for(i = 0; i < 10; i++)
		scanf("%d", a+i);
	for(i = 0; i < 10; i++){
		flag = 0;
		for(j = 0; j < 10; j++){
			if(a[i] == a[j] && i != j){
				flag = 1;
				break;
			}
		}
		if(!flag){
			printf("%d ", a[i]);
			flag2 = 1;
		}
	}
	if(!flag2)
		printf("None");
	return 0;
}
