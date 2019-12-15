#include <stdio.h>

typedef struct {
	int h;
	int m;
	int s;
} Time;

int main(){
	Time t;
	int s, tm, th;
	scanf("%d:%d:%d", &t.h, &t.m, &t.s);
	scanf("%d", &s);
	tm = (t.s + s) / 60;
	t.s = (t.s + s) % 60;
	th = (t.m + tm) / 60;
	t.m = (t.m + tm) % 60;
	t.h = (t.h + th) % 24;
	printf("%d:%d:%d", t.h, t.m, t.s);
}
