#include <stdio.h>

int main(){
	char c;
	int positive = 1;	//1: pos, -1:neg
	int firstDigit = 0;
	int sum = 0;
	while((c = getchar()) != '#'){
		if(c == '-' && firstDigit == 0){
			positive = -1;
			firstDigit = 1;
		}
		else if(c >= '0' && c <= '9'){
			sum *= 16;
			sum += c - '0';
			firstDigit = 1;
		}
		else if(c >= 'a' && c <= 'f'){
			sum *= 16;
			sum += (c - 'a') + 10;
			firstDigit = 1;
		}
		else if(c >= 'A' && c <= 'F'){
			sum *= 16;
			sum += (c - 'A') + 10;
			firstDigit = 1;
		}
	}
	sum *= positive;
	printf("%d", sum);
	return 0;
} 
