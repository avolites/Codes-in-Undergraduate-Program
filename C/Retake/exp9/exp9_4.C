#include<stdio.h>

void posi(int n){
	if(n != 0){
		posi(n / 10);
		printf("%d ", n % 10);
	}
}

void nega(int n){
	if(n != 0){
		printf("%d ", n % 10);
		nega(n / 10);
	}
}

int main(){
    int x;
    scanf("%d",&x);
    posi(x);
    printf("\n");
    nega(x);
}
