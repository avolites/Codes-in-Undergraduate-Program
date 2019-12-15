#include <stdio.h>

int main(){
	int n, i, j;
	scanf("%d", &n);
	if(n > 0 && n <= 6){
		for(i = 1; i <= n; i++)
			printf("%-2d ", i);
		puts("");
		for(i = 0; i < n - 2; i++){
			printf("%-2d ", (n - 2) * 4 + 4 - i);
			for(j = 0; j < n - 2; j++)
				printf("%-2d ", 0);
			printf("%-2d \n", n + i + 1);
		}
		for(i = (n - 2) * 4 + 4 - n + 2; i >= ((n - 2) * 4 + 4) / 2 + 1; i--)
			printf("%-2d ", i);
	}
	return 0;
}
