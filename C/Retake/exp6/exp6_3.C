#include <stdio.h>

int main(){
	int n, m, a[10], b[10];
	int i, j;
	int flag1 = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", a + i);
	scanf("%d", &m);
	for(i = 0; i < m; i++)
		scanf("%d", b + i);
	for(i = 0; i < n; i++){
		flag1 = 0;
		for(j = 0; j < m; j++){
			if(a[i] == b[j]){
				flag1 = 1;
				break;
			}
		}
		if(!flag1)
			printf("%d ", a[i]);
	}
	for(i = 0; i < m; i++){
		flag1 = 0;
		for(j = 0; j < n; j++){
			if(b[i] == a[j]){
				flag1 = 1;
				break;
			}
		}
		if(!flag1)
			printf("%d ", b[i]);
	}
	return 0;
}
