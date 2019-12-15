#include <stdio.h>

int main(){
	int choice;
	int i;
	int flag = 0;
	puts("[1]apple");
	puts("[2]pear");
	puts("[3]orange");
	puts("[4]grape");
	puts("[0]exit");
	for(i = 0; i < 5; i++){
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("price=%.1f\n", 3.00);
				break;
			case 2:
				printf("price=%.1f\n", 2.50);
				break;
			case 3:
				printf("price=%.1f\n", 4.10);
				break;
			case 4:
				printf("price=%.1f\n", 10.20);
				break;
			case 0:
				flag = 1;
				break;
			default:
				printf("price=0.0\n");
				break;
		}
		if(flag)
			break;
	}
	return 0;
}
