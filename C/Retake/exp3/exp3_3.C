#include <stdio.h>

int main(){
	int n, min, t;
	scanf("%d", &n);
	if(n == 1){
		scanf("%d", &t);
		printf("min=%d", t);
	}
	else if(n > 1){
		scanf("%d", &min);
		while(n > 1){
			scanf("%d", &t);
			min = (t < min) ? t : min;
			n--;
		}
		printf("min=%d", min);
	}
	return 0;
}
