#include <stdio.h>

typedef struct {
	int numerator;
	int denominator;
} Rational;

int compareRational(Rational a, Rational b){
	return a.numerator * b.denominator - b.numerator * a.denominator;
}

int main(){
	Rational a, b;
	int diff;
	scanf("%d/%d", &a.numerator, &a.denominator);
	scanf("%d/%d", &b.numerator, &b.denominator);
	diff = compareRational(a, b);
	if(diff < 0)
		printf("%d/%d<%d/%d", a.numerator, a.denominator, b.numerator, b.denominator);
	else if(diff == 0)
		printf("%d/%d=%d/%d", a.numerator, a.denominator, b.numerator, b.denominator);
	else
		printf("%d/%d>%d/%d", a.numerator, a.denominator, b.numerator, b.denominator);
	return 0;
} 
