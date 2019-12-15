#include <stdio.h>

int main(){
	int m, n, a, b, c;
	puts("Input m,n:");
	scanf("%d%d", &m, &n);
	a = m;
	b = n;
	while(b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	printf("%d %d", a, (n * m) / a);
} 
