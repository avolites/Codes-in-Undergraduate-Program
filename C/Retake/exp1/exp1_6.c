#include <stdio.h>

int main(){
	int kwh;
	double pay = 0;
	scanf("%d", &kwh);
	if(kwh <= 50 && kwh >= 0)
		pay = kwh * .53;
	else if(kwh > 50)
		pay = (kwh - 50) * (.53 + .05) + 50 * .53;
	printf("kWh=%d,pay=%.2lf", kwh, pay);
	return 0;
}
