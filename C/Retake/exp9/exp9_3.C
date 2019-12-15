#include<stdio.h>

void dectobin(int n){
	if(n != 0){
		dectobin(n / 2);
		printf("%d", n % 2);
	}
}

int main(){
    int x;
    scanf("%d",&x);
    dectobin(x);
}
