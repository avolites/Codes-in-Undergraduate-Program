#include <stdio.h>

int main(){
	double f, c;
	scanf("%lf", &f);
	c = 5 * (f - 32) / 9;
	printf("Celsius=%.2lf",c);
	return 0;
}
