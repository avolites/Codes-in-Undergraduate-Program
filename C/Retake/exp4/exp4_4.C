#include <stdio.h>

int countdigit(int number, int digit){
	int sum = 0;
	while(number > 0){
		if(number % 10 == digit)
			sum++;
		number /= 10;
	}
	return sum;
}

int  main(){
    int  n,d,y;
    scanf("%d%d",&n,&d);
    y=countdigit(n,d);
    printf("Number  of  digit  %d:%d",d,y);
    return  0;
}
