#include <stdio.h>

void printHeaderFooter(int);
void printLine(int, int);
void printChar(char, int);

int main(){
	int n, i;
	scanf("%d", &n);
	if(n == 1)
		puts(" @");
	else if(n > 1){
		printHeaderFooter(n);
		for(i = 1; i < n; i++)
			printLine(n, i);
		for(i = n - 2; i > 0; i--)
			printLine(n, i);
		printHeaderFooter(n);
	}
	return 0;
}

void printHeaderFooter(int n){
	int i;
//	putchar('*');
	for(i = 0; i < n; i++){
		putchar(' ');
	}
	for(i = 0; i < n; i++){
		putchar('@');
	}
	puts("");
}

void printChar(char c, int repeat){
	for(; repeat > 0; repeat--){
		putchar(c);
	}
}

void printLine(int n, int i){
//	putchar('*');
	printChar(' ', n - i);
	putchar('@');
	printChar(' ', i - 1);
	printChar(' ', n);
	printChar(' ', i - 1);
	putchar('@');
	puts("");
}
