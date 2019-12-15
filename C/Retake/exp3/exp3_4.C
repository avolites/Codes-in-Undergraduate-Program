#include <stdio.h>

int main(){
	int n, count = 0, sum = 0;
	scanf("%d", &n);
	while (n > 0){
		count++;
		sum += n % 10;
		n /= 10;
	}
	printf("%d %d", count, sum);
	return 0;
}
