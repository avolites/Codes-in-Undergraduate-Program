#include <stdio.h>

int main(){
	int a[4][4];
	int i, j;
	int max, y, x;
	int flag, flag2;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			scanf("%d", *(a + i) + j);
	flag2 = 0;
	for(i = 0; i < 4; i++){
		max = a[i][0];
		x = 0;
		flag = 0;
		for(j = 0; j < 4; j++){
			if(a[i][j] > max){
				max = a[i][j];
				x = j;
				y = i;
			}
		}
		for(j = 0; j < 4; j++){
			if(a[j][x] < max){
				flag = 1;
			}
		}
		if(!flag){
			printf("[%d][%d] %d", y, x, max);
			flag2 = 1;
		}
	}
	if(!flag2)
		printf("NO");
	return 0;
}
