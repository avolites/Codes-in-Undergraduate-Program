#include<stdio.h>

double fact(int i){
	if (i > 1)
		return fact(i - 1) * i;
	else
		return 1.;
}

double fact(int i){
	double res = 1.;
	if(i > 1){
		while(i > 1){
			res *= i;
			i--;
		}
		return res;
	}
	return 1.;
}

int  main(){
    int  i,n;
    double  sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        sum=sum+fact(i);
    printf("%.0lf",sum);        
}
