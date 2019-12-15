#include<stdio.h>

void f(char *p){
	int len = 0;
	int i, j;
	char t;
	while(p[len] != '\0')
		len++;
	i = 0;
	j = len - 1;
	for(; i < j; i++, j--){
		t = p[i];
		p[i] = p[j];
		p[j] = t;
	}
}

int main(){
    char  st[20];
    scanf("%s",st);
    f(st);
    printf("%s",st);        
}
