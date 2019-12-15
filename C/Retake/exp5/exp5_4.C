#include <stdio.h>
#include <string.h>

int gcd(int, int);
int strloc(char*, char);

int main(){
	char s[16];
	int dotPos;		//position of decimal point
	int i;			//temporary variable for loop
	int integer = 0, fraction = 0;	//the integer and fraction part of usre's input
	int denominator = 1;
	int gcdNum;		//GCD for integer and fraction
	int len;
	fgets(s, 16, stdin);
	len = strlen(s) - 1;
	dotPos = strloc(s, '.');
	if(dotPos != -1){
		for(i = 0; i < dotPos; i++){
			integer *= 10;
			integer += s[i] - '0';
		}
		for(i = dotPos + 1; i < len; i++){
			fraction *= 10;
			fraction += s[i] - '0';
			denominator *= 10;
		}
		gcdNum = gcd(denominator, fraction);
		fraction /= gcdNum;
		denominator /= gcdNum;
		printf("%d %d %d", integer, fraction, denominator);
	}
	return 0;
}

int gcd(int a, int b){
	int c;
	while(b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int strloc(char *s, char a){
	int i = 0;
	while(s[i] != '\0'){
		if(a == s[i])
			return i;
		i++;
	}
	return -1;
}
