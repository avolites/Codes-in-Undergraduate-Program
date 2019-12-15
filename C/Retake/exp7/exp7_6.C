#include<stdio.h>

void strmcpy(char *s, char *t, int m){
	int i = 0;
	while(t[i + m - 1] != '\0'){
		s[i] = t[i + m - 1];
		i++;
	}
	s[i] = '\0';
} 

int  main(){
      char  st[20],tt[20],ch;
      int  i=0,m;
      scanf("%c",&ch);
    while(ch!='\n'){
        tt[i++]=ch;
        scanf("%c",&ch);
    }
    tt[i]='\0';
    scanf("%d",&m);
    strmcpy(st,tt,m);
    printf("%s\n",st);
}
