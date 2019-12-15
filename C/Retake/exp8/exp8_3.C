#include <stdio.h>

typedef struct{
	char name[100];
	float price;
} Book;

int main(){
	Book book[10], *max, *min;
	int n, i;
	scanf("%d", &n);
	scanf("%s", book[0].name);
	scanf("%f", &book[0].price);
	max = book;
	min = book;
	for(i = 1; i < n; i++){
		scanf("%s", book[i].name);
		scanf("%f", &book[i].price);
		if(book[i].price > max->price)
			max = book + i;
		if(book[i].price < min->price)
			min = book + i;
	}
	printf("%.2f,%s\n", min->price, min->name);
	printf("%.2f,%s", max->price, max->name);
	return 0;
} 
