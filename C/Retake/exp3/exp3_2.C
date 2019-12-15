#include <stdio.h>

int main(){
	char c;
	while(1){
		scanf("%c", &c);
		if(c == '#')
			break;
		if(c >= '0' && c <= '9')
			printf("%c", c);
	}
	return 0;
}
