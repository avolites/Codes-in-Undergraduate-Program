#include <stdio.h>

void sort(int a[], int n){
	int min, i, j, t;
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		if(min != i){
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	} 
}

int  main(){
    int  a[10],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n);        
    for(int  i=0;i<n;i++)
        printf("%d  ",a[i]);
    
} 
