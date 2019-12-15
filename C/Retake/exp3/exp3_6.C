#include <stdio.h>

int main(){
	int n, i;
	char c = 'A';
	scanf("%d", &n);
	if(n > 0 && n < 7){
		while(n > 0){
			for(i = 0; i < n; i++){
				putchar(c);
				putchar(' ');
				c++;
			}
			puts("");
			n--;
		}
	}
	return 0;
}
