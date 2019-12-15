#include <stdio.h>
#include <string.h>

void printString(char*, int, int);

int main(){
	char s[1000];
	int i, j, length;
	fgets(s, 1000, stdin);
	length = strlen(s);
	for(i = 1; i <= length; i++)	//i means length of sub-string
		for(j = 0; j < length - i; j++)
			printString(s, j, i);
	return 0;
}

void printString(char *s, int initPos, int len){
	int i = initPos;
	for(; i < initPos + len; i++)
		putchar(s[i]);
	puts("");
}
