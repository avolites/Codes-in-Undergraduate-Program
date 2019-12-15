#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	double n = 0;		// assign 0 to n, for if user input -1, the writting process will be terminated
	if((f = fopen("b.txt", "w")) == NULL){	// fail to open
		printf("Error: Cannot open file b.txt in current directory.\n");
		exit(0);
	}
	while(n != -1){		// for the first time, n is 0, go into the loop
		scanf("%lf", &n);
		if(n != -1)		// do not write -1 into the target text file
			fprintf(f, "%lf\n", n);
	}
	fclose(f);
	return 0;
}
