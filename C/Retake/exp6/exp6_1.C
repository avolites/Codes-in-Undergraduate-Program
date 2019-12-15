#include <stdio.h>

#define LEN 7

void insert(int*, int, int, int);

int main(){
	int a[LEN], n, i;
	for(i = 0; i < 6; i++)
		scanf("%d", a + i);
	scanf("%d", &n);
	for(i = 0; i < 6; i++){
		if(i == 0 && n < a[i])
			insert(a, 0, n, LEN);
		else if((n < a[i] && n > a[i - 1]) || (a[i] == n))
			insert(a, i, n, LEN);
		else if(i == 5 && n > a[i])
			insert(a, i, n, LEN);
	}
	for(i = 0; i < LEN - 1; i++)
		printf("%d ", a[i]);
	return 0;
}

void insert(int *a, int pos, int element, int len){
	int i = len - 2;
	for(; i >= pos; i--)
		a[i + 1] = a[i];
	a[pos] = element;
}
