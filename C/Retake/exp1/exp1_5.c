#include <stdio.h>

int main(){
	int n, i;
	float sum = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		sum += (float)1/i;
	}
	printf("n=%d,sum=%.7f", n, sum);
	return 0;
}
