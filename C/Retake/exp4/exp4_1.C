#include<stdio.h>

int even(int n) {
	if(n % 2 == 0)
		return 1;
	return 0;
}

int main(){
    int  sum=0,x;
    scanf("%d",&x);
    while(x>0){
        if(even(x)==0)
            sum=sum+x;
        scanf("%d",&x);
    }
    printf("sum=%d\n",sum);
    return  0;
}
