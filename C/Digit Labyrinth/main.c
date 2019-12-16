//***********************
//*number labyrinth game*
//*made by Gaoxiang Liu *
//*        v1.0         *
//***********************
#include<stdio.h>
#include"windows.h"
#include<time.h>
#include<conio.h>
#include<stdlib.h>
void down();
void up();
void right();
void left();
int x=2,y=1,o=0,rx[7]={3,2,8,9,10,18,11},ry[7]={2,5,8,8,8,11,11},jjj=0;
/*x and y is cursor's coordinate,x represents horizon axle and y represents vertical axle.And it represents player's character.
o represents 7 numbers (0 to 6).In main function,there is an int b[7],and o can be used b[o].
rx[] and ry[] is numbers'(1 to 7) coordinate,they represent horizon and vertical axle,the initial values are for experiment,in fact,they are not useful in this program.
jjj is used for judging if you have finished eating all numbers,in other words it can judge wheter you win.*/
int a[17][24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,-1,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
0,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,-1,0,0,0,0,0,-1,-1,-1,0,0,
0,-1,0,0,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,
0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,0,
0,-1,0,0,-1,0,-1,0,0,0,0,-1,0,-1,-1,-1,0,0,0,0,0,0,0,0,
0,-1,-1,-1,-1,-1,-1,0,0,0,0,-1,0,0,0,-1,0,0,0,0,0,0,0,0,
0,-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,0,
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,0,0,-1,0,0,0,0,
0,0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,-1,0,0,-1,0,0,0,0,
0,0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,
0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,-1,0,0,
0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,0,
0,0,-1,-1,-1,-1,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,
0,-1,-1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//map
int main()
{
	HANDLE hOut3 = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut3,&cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut3,&cci);//hide cursor
	int gc,i,j,b[7]={1,2,3,4,5,6,7},k=0,l=0,ju,jj;
	/*b[] is used for save 7 numbers it will easily to print.
	i and j are variables that control the circulation.
	jj is used for judging which key you have pressed and system will do something you want.
	l is for saving coordinate of 7 numbers
	ju is a variable that can judge if system produce the coordinate of the numbers is correct.*/
	time_t t;
	for(i=0;i<17;i++)
	{
		for(j=0;j<24;j++)
		{
			if(a[i][j]==-1)printf("  ");
			else printf("©–");
		}//print map.In order not to let system produce error codes ,I use this character to represent wall.
		
		putchar('\n');
	}
	printf("Tips:\n");
	printf("You can use curson key to move the character.\n");
	printf("You have to \"eat\" every numbers from 1 to 7,or you will not move.\n");
	printf("Also you can only move in the passageway and you can't through wall.\n");
    printf("ESC:quit  R:restart  F2:new game\n");
	//the above prints are tips
	printf("state:");//This is for printing state.
aaa://If the player press F2 ,it will goto here(aaa) to start a new game.
	HANDLE hOut2;
	COORD pos2= {6,22}; 
	hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut2, pos2);//To mvoe the cursor to 6,22,this location is after"state".
	printf("Initialing...                                   ");//This is a state,the system is initialing a new game.
	
	HANDLE hOut1;
	COORD pos1= {x,y}; 
	hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut1, pos1);
	printf(" ");//This codes is for start a new game,it will clear the formal player's character,in fact it is no use for the first gmae.
	x=2;
	y=1;//In fact,x and y has already been valved.This can replace player's character location.
	//When player start a new game, this codes will work.
	//If this is the fist time for player have run this game,this codes have no efftct.
	HANDLE hOut;
	COORD pos= {x,y}; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	printf("%c",1);//print player's character
	l=0;//clare.Because after a circulation it's vale is 7.Also it is used for the second time to play.
	jjj=0;//clear data,it will count how many numbers you have "eaten".
	do
	{
		ju=0;//When ju is 0,it means the random vale that system producted is wrong.When ju is 1,it means it correct.
		srand((unsigned)time(&t));
		rx[l]=rand()%49;
		//srand((unsigned)time(&t));
		ry[l]=rand()%18;
		if((a[ry[l]][(rx[l]+1)/2+(rx[l]+1)%2-1]==-1)&&(rx[l]!=2)&&(ry[l])!=1)//The coordinate can only be produced in the passway.
			ju=1;
		else 
			continue;
		if(l>0)
		{
			if((rx[l-1]==rx[l])&&(ry[l-1]==ry[l]))
				continue;
		}
		if(ju==1)
			l++;
	}
	while(l!=7);//produce 7 numbers.
	/*The avobe codes are used for producing random numbers,the numbers(1 to 7) will fill in the "passway".
	But this codes is very slow,you have to wait about 20 seconds before system produce 7 numbers.*/
bbb://If player press R or r,the game will restart(goto bbb),it means replay this game,not a new game.
	jjj=0;//clear,this is used for the second time play
	HANDLE hOut6;
	COORD pos6= {6,22}; 
	hOut6 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut6, pos6);
	printf("Initialing...                                   ");
	
	for(l=0;l<7;l++)
		
	{
		HANDLE hOut;
		COORD pos= {rx[l],ry[l]}; 
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, pos);
		printf("%d",b[l]);	//print 7 numbers in the "passway"
	}
	
	for(i=0;i<7;i++)
	{
		int u,v;
		v=ry[i];
		u=(rx[i]+1)/2+(rx[i]+1)%2-1;
		a[v][u]=1;//If there is a number a[][]'s vale is 1,this will judge whether you can eat the number.
	}
	o=0;//This is used for the second time to play.It can clear o.
	HANDLE hOut4;
	COORD pos4= {6,22}; 
	hOut4 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut4, pos4);
	printf("Initial completed,please play game.");//print this state.
	do
	{
		jj=1;
		gc=getch();
		
		switch (gc)
		{
		case 80:down();break;
		case 72:up();break;
		case 75:left();break;
		case 77:right();break;
		case 82://R
		case 114:jj=0;break;//r
		case 60:jj=2;break;//F2
		case 27:jj=3;//ESC
		}
		if(jjj==7)//When jjj's vale is 7,it means you have eaten all numbers,in other words,you win.
		{
			HANDLE hOut5;
			COORD pos5= {6,22}; 
			hOut5 = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut5, pos5);
			printf("Congratulations!You win.                   ");	//print win state.
		}
		if(jj==0||jj==3||jj==2)
			break;//When player press R or r ,F2,ESC,it will stop
	}
	while(1);//This circulation allows player control the game
	
	if(jj==2) 
	{
		for(l=0;l<7;l++)
			
		{
			HANDLE hOut;
			COORD pos= {rx[l],ry[l]}; 
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut, pos);
			printf(" ");	
		}//clear remaining numbers
		for(i=0;i<7;i++)
		{
			int u,v;
			v=ry[i];
			u=(rx[i]+1)/2+(rx[i]+1)%2-1;
			a[v][u]=-1;
		}//replace map a[][] from  1 to -1(passway)
		goto aaa;
		
	}
	if(jj==0) 
	{
		HANDLE hOut1;
		COORD pos1= {x,y}; 
		hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut1, pos1);
		printf(" ");
		x=2;
		y=1;
		HANDLE hOut;
		COORD pos= {x,y}; 
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, pos);
		printf("%c",1);//replact player's character
		goto bbb;
	}
}
/**********************************************/
void down()
{
	
	if((rx[o]==x)&&ry[o]==y+1)//If this is a number.
		
	{
		HANDLE hOut1;
		COORD pos1= {x,y}; 
		hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut1, pos1);
		printf(" ");
		HANDLE hOut;
		COORD pos= {x,y+=1}; 
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, pos);
		printf("%c",1);
		int du,dv;
		dv=y;
		du=(x+1)/2+(x+1)%2-1;
		a[dv][du]=-1;
		o++;
		jjj++;
	}
	
	else if(a[y+1][(x+1)/2+(x+1)%2-1]==-1)//If this is passway.
	{
		HANDLE hOut1;
		COORD pos1= {x,y}; 
		hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut1, pos1);
		printf(" ");
		HANDLE hOut;
		COORD pos= {x,y+=1}; 
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, pos);
		printf("%c",1);
	}
}
/**************************************************/
void left() 
{
	if(x-1>=0)
	{
		if((rx[o]==x-1)&&(ry[o]==y))
		{
			HANDLE hOut1;
			COORD pos1= {x,y}; 
			hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut1, pos1);
			printf(" ");
			HANDLE hOut;
			COORD pos= {x-=1,y};
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut, pos);
			printf("%c",1);
			int du,dv;
			dv=y;
			du=(x+1)/2+(x+1)%2-1;
			a[dv][du]=-1;
			o++;
			jjj++;
		}
		if((rx[o]==x-2)&&(ry[o]==y))
		{
			if(x%2==0)
			{
				HANDLE hOut1;
				COORD pos1= {x,y}; 
				hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut1, pos1);
				printf(" ");
				HANDLE hOut;
				COORD pos= {x-=1,y};
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut, pos);
				printf("%c",1);
				int ru,rv;
				rv=y;
				ru=(x+1)/2+(x+1)%2-1;
				a[rv][ru]=-1;
				o++;
				jjj++;
			}
			else 
			{
				HANDLE hOut1;
				COORD pos1= {x,y}; 
				hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut1, pos1);
				printf(" ");
				HANDLE hOut;
				COORD pos= {x-=1,y};
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut, pos);
				printf("%c",1);
				int ru,rv;
				rv=y;
				ru=(x+1)/2+(x+1)%2-2;
				a[rv][ru]=-1;
				o++;
				jjj++;
			}
		}
		if(a[y][x/2+x%2-1]==-1)
		{
			HANDLE hOut1;
			COORD pos1= {x,y}; 
			hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut1, pos1);
			printf(" ");
			HANDLE hOut;
			COORD pos= {x-=1,y}; 
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut, pos);
			printf("%c",1);
		}
	}
}
/************************************************/
void right()
{
	
	if((rx[o]==x+1)&&(ry[o]==y))
	{
		HANDLE hOut1;
		COORD pos1= {x,y}; 
		hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut1, pos1);
		printf(" ");
		HANDLE hOut;
		COORD pos= {x+=1,y}; 
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, pos);
		printf("%c",1);
		int ru,rv;
		rv=y;
		ru=(x+1)/2+(x+1)%2-1;
		a[rv][ru]=-1;
		o++;
		jjj++;
	}
	if((rx[o]==x+2)&&(ry[o]==y))
	{
		if(x%2==1)
		{
			HANDLE hOut1;
			COORD pos1= {x,y}; 
			hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut1, pos1);
			printf(" ");
			HANDLE hOut;
			COORD pos= {x+=1,y}; 
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut, pos);
			printf("%c",1);
			int ru,rv;
			rv=y;
			ru=(x+1)/2+(x+1)%2-1;
			a[rv][ru]=-1;
			o++;
			jjj++;
		}
		else
		{
			HANDLE hOut1;
			COORD pos1= {x,y}; 
			hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut1, pos1);
			printf(" ");
			HANDLE hOut;
			COORD pos= {x+=1,y}; 
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut, pos);
			printf("%c",1);
			int ru,rv;
			rv=y;
			ru=(x+1)/2+(x+1)%2;
			a[rv][ru]=-1;
			o++;
			jjj++;
		}
	}
	if(a[y][(x+2)/2+(x+2)%2-1]==-1)
	{
		HANDLE hOut1;
		COORD pos1= {x,y}; 
		hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut1, pos1);
		printf(" ");
		HANDLE hOut;
		COORD pos= {x+=1,y}; 
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, pos);
		printf("%c",1);
	}
	
}
/*********************************************/
void up()
{
	if(y-1>=0)
	{
		if(rx[o]==x&&ry[o]==y-1)
		{
			HANDLE hOut1;
			COORD pos1= {x,y}; 
			hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut1, pos1);
			printf(" ");
			HANDLE hOut;
			COORD pos= {x,y-=1}; 
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut, pos);
			printf("%c",1);
			int ru,rv;
			rv=y;
			ru=(x+1)/2+(x+1)%2-1;
			a[rv][ru]=-1;
			o++;
			jjj++;
		}
		
		else	if(a[y-1][(x+1)/2+(x+1)%2-1]==-1)
		{
			HANDLE hOut1;
			COORD pos1= {x,y}; 
			hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut1, pos1);
			printf(" ");
			HANDLE hOut;
			COORD pos= {x,y-=1}; 
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hOut, pos);
			printf("%c",1);
		}
	}
}
/*The above 4 function is used for detecting player's movation*/
