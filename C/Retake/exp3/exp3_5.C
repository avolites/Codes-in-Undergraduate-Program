#include <stdio.h>

int main(){
	int m, n, tm, t;
	scanf("%d%d", &m, &n);
	printf("Narc No:");
	while(m <= n){
		tm = m;
		t = 0;
		while(tm > 0){
			t += (tm % 10) * (tm % 10) * (tm % 10);
			tm /= 10;
		}
		if(m == t)
			printf("%d ", m);
		m++;
	}
	return 0;
}
