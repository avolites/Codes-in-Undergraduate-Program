#include <stdio.h>

int prime(int);

int  main(){
    int  m,n,ct=0,sum=0,i;
    scanf("%d%d",&m,&n);
    if(m<2)  m=2;
    for(i=m;i<=n;i++)
        if(prime(i)){
            ct++;
            sum=sum+i;
        }
    printf("count=%d,sum=%d\n",ct,sum);
    return  0;
}

int prime(int m){
	int i = 2;
	if(m < 2)
		return 0;
	if(m == 2)
		return 1;
	for(;i < m; i++)
		if(m % i == 0)
			return 0;
	return 1;
}
