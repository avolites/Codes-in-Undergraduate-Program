#include <stdio.h>
#include <math.h>

int main(){
	double a, b, c, perimeter, area, s;
	printf("Enter 3 sides of the triangle:");
	scanf("%lf%lf%lf", &a, &b, &c);
	if(a + b > c && a + c > b && b + c >a){
		perimeter = a + b + c;
		s = perimeter / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("area=%.2lf;perimeter=%.2lf", area, perimeter);
	}
	else
		printf("These sides do not correspond to avalid triangle");
	return 0;
}
