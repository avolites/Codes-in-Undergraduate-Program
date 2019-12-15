#include <stdio.h>

int main(){
	char s[100];
	int i ;		//temporary variable for loop
	int letter = 0, blank = 0, digit = 0, other = 0;
	fgets(s, 16, stdin);
	for(i = 0; i < 15; i++){
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			letter++;
		else if(s[i] >= '0' && s[i] <= '9')
			digit++;
		else if(s[i] == ' ')
			blank++;
		else
			other++;
	}
	printf("letter=%d blank=%d digit=%d other=%d", letter, blank, digit, other);
	return 0;
}
