#include <stdio.h>
#include <string.h>

int main(){
	char sx[1000], smax[100];
	int len, max;
	int i;
	scanf("%s", sx);
	len = strlen(sx);
	max = len;
	strcpy(smax, sx);
	for(i = 1; i < 5; i++){
		scanf("%s", sx);
		len = strlen(sx);
		if(len > max){
			max = len;
			strcpy(smax, sx);
		}
	}
	printf("%s", smax);
}
