#include<stdio.h>
#include<stdlib.h>

void splitFloat(float x, int *intpart, float *fracpart){
	*intpart = (int)x;
	*fracpart = x - *intpart;
}

int  main(){
    float  x,fp;
    int  ip;
    scanf("%f",&x);
    splitFloat(x,&ip,&fp);
    printf("The  intpart  is  %d\n",ip);
    printf("The  fracpart  is  %f\n",fp);
} 
