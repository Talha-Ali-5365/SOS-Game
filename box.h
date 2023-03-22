#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
int random(int a, int b)
{
	int random_no;
	srand(getpid() + time(NULL));
	random_no = (rand() %(b-a+1))+a;
	return random_no;
}
int intlen(int a)
{
	int j=0;
	while(a>0)
	{
		a=a/10;
		j++;
	}
	return j;
}
void screeen(int x, int y)
{
	COORD pos= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int str(char* row)
{
	int len,i,j,k=0;
	len = strlen(row);
	for(i=0;i<len;i++)
	{
		j=(row[i]-48)%10;
		k=k*10+j;
	}
	return k;
}
int strng(char* strng)
{
	int i;
	i = (int)(strng[0]);
	return i;
}
void fill_int(int col, int row, char ch)
{
	if(col>=97)
	{
		col = 2*(col-70)+1;
	}
	else
	{
		col = 2*(col-64)+1;	
	}
	row = row*2;
	screeen(col,row);
	printf("%c",ch);
	screeen(1,28);
}
void fill(char col, char* row, char ch)
{
	int rrow;
	rrow=str(row);
	if(col>=97)
	{
		col = 2*(col-70)+1;
	}
	else
	{
		col = 2*(col-64)+1;	
	}
	rrow = rrow*2;
	screeen(col,rrow);
	printf("%c",ch);
	screeen(1,28);
}
