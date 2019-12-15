#include<stdio.h>
#include<string.h>

int main(){
	char c, s[81];
	int len;
	int i;
	int flag = 0;
	c = getchar();
	while(getchar() != '\n')
		continue;
	fgets(s, 81, stdin);
	len = strlen(s);
	if(s[len - 1] == '\n'){
		s[len - 1] = '\0';
		len = strlen(s);	
	}
	for(i = 0; i < len; i++)
		if(s[i] == c){
			printf("%d", i + 1);
			flag = 1;
			break;
		}
	if(!flag)
		printf("Not Found");
	return 0;
} 
