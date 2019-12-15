#include<stdio.h>
#include<math.h>

double funcos(double e, double x){
	double element, sum = 0, abs;
	long fac = 1;
	int i = 0, j;
	while(1){
		fac = 1;
		if(i * 2 > 1){
			j = i * 2;
			while(j > 1){
				fac *= j;
				j--;
			}
		}
		element = (pow(x, i * 2) / fac) * pow(-1, i);
		sum += element;
		abs = (element > 0) ? element : 0 - element;
		if(abs < e)
			return sum;
		i++;
	}
}

int  main(){
    double  e,x,rz;
    scanf("%lf%lf",&e,&x);
    rz=funcos(e,x);
    printf("sum=%lf",rz);
    return  0;
}
