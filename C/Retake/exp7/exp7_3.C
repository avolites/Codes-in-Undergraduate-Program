#include<stdio.h>

void printArray(int  a[],int  n){
    for(int  i=0;i<n;i++)
            printf("%2d  ",a[i]);
    printf("\n");
}
void setArray(int  a[],int  n){
    for(int  i=0;i<n;i++)
            scanf("%d",&a[i]);
}

int search(int *list, int n, int x){
	int i = 0;
	for(; i < n; i++){
		if(list[i] == x)
			return i;
	}
	return -1;
}

int main(){
    int  a[10],n,r,x;
    scanf("%d",&n);
    setArray(a,n);
    scanf("%d",&x);
    r=search(a,n,x);
    if(r>=0)
        printf("%d\n",r);
	else
        printf("Not  found\n");        
}
