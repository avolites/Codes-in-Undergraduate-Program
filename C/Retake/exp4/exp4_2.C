#include<stdio.h>
#include<math.h>

float dist(float x1, float y1, float x2, float y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int  main(){
        float  xs,ys,xe,ye,d;
        scanf("%f%f",&xs,&ys);
        scanf("%f%f",&xe,&ye);
        d=dist(xs,ys,xe,ye);
        printf("Distance=%.2f",d);
        return  0;
}
