#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	char c;		// for reading every character in text file
	int letter = 0, digit = 0, other = 0;	// statistics
	if((f = fopen("a.txt", "r")) == NULL){	// fail to open file a.txt 
		printf("Error: Cannot open file a.txt in current directory.\n");
		exit(0);
	}
	puts("File contents:");
	while((c = fgetc(f)) != EOF){	// EOF is a ending flag for a normal text file
		putchar(c);
		if(c >= '0' && c <= '9')
			digit++;
		else if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			letter++;
		else
			other++;
	}
	printf("\n\nStatistics:\nLetter: %d\nDigit:  %d\nOther:  %d\n", letter, digit, other);
	fclose(f);
	return 0;
}
