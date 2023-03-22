#include"box.h"

void screen(int x, int y);
void draw()
{
	int a=0,b=2,i,j,x=3,y=0,k=65,m=1,c,d;
	for(i=1;i<=28;i++)
	{
		for(j=1;j<=81;j++)
		{
			if(i>2 && j==1)
			{
				if(i%2==1)
				{
					printf("%d",m++);
				}
			}
			else if(i%2==0 && j>2)
			{
				printf("%c",196);
			}
			else if((i>1 && i<21) && (j==3 || j==81))
			{
				printf("%c",179);
			}
			else if(i==1 && (j>3 && j<=42))
			{
				screen(x,y);
				x=x+2;
				if(k==91)
				{
					k=97;
				}
				printf("%c",k++);
			}
			else if(j==1 || j==3)
			{
				printf(" ");
			}
			else if(i>20 && i%2==1)
			{
				if(j%2==0)
				{
					printf("%c",179);
				}
				else
				{
					printf(" ");
				}
			}
			else if(j%2==1 && (i!=1 && i<21))
			{
				printf("%c",179);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	screeen(99,8);
	{
		printf("SCORE");
	}
	screeen(87,9);
	printf("%c",218);
	for(c=1;c<27;c++)
	{
		printf("%c",196);
	}
	printf("%c",191);
	for(c=10;c<17;c++)
	{
		screeen(87,c);
		printf("%c",179);
		for(d=1;d<27;d++)
		{
			if(d==14 && (c>10 && c<16))
			{
				printf("%c",179);
			}
			else
			{
				printf(" ");
			}
		}
		printf("%c",179);
	}
	screeen(87,17);
	printf("%c",192);
	for(c=1;c<27;c++)
	{
		printf("%c",196);
	}
	printf("%c",217);
	screeen(90,11);
	printf("Computer");
	screeen(106,11);
	printf("You");
	screeen(94,13);
	printf("0");
	screeen(107,13);
	printf("0");
}
void screen(int x, int y)
{
	COORD pos= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
void input()
{
	char data[5],col[5],row[5];
	char ch;
	int waste,scorea,scoreb;
	int colrow[27][81]={0};
	int chdata[27][81]={0};
	int rowind=0,colind=0,coll,rooww,rowdat,rowdat2,rc,cc,ac,ab,chint;
	int x=1,y=28,i,j,ran,a,b,c,d,r,roww,arow,acol;
	while(1)
	{
column:
		screen(x,y);
		printf("\r                                                                   ");
		printf("\rEnter column: ");
		gets(col);
		coll = strng(col);
row:
		screen(x,y);
		printf("\r                            ");
		printf("\rEnter row: ");
		gets(row);
		rooww = str(row);
charc:
		screen(x,y);
		printf("\rEnter character: ");
		gets(data);
		for(rc=0;rc<14;rc++)
		{
			for(cc=0;cc<81;cc=cc+2)
			{
				if((colrow[rc][cc]==rooww) && colrow[rc][cc+1]==coll)
				{
					goto column;
				}
			}
		}
		if(coll<91)
		{
			chint = 2*(coll-63)-1;
		}
		else
		{
			chint = 2*(coll-69)-1;
		}
		rowdat=rooww*2;
		chdata[rowdat][chint]=(int)(data[0]);
		waste=0;
		if((data[0]=='S' || data[0]=='s') || (data[0]=='O' || data[0]=='o'))
		{
			fill(col[0],row,data[0]);	
		}
		else
		{
			goto charc;
		}
		waste=0;
		if(colind==81)
		{
			colind = 0;
			rowind++;
		}
		else
		{
			colrow[rowind][colind]=rooww;
			colind++;
			colrow[rowind][colind]=coll;
			colind++;
		}
AI:
		for(ac=2;ac<27;ac=ac+2)
		{
			for(ab=3;ab<80;ab=ab+2)
			{
				if(chdata[ac][ab]==79 || chdata[ac][ab]==111)
				{
					if(((chdata[ac-2][ab]==83/*S*/ || chdata[ac-2][ab]==115/*s*/) && (ac-2>1)) && ((chdata[ac+2][ab]!=83/*S*/ && chdata[ac+2][ab]!=115/*s*/) && (chdata[ac+2][ab]!=79/*O*/ && chdata[ac+2][ab]!=111/*o*/)))
					{
						if(ab<55)
						{
							acol=((ab-1)/2)+64;
						}
						else
						{
							acol=((ab-1)/2)+70;
						}
						arow=(ac+2)/2;
						Sleep(100);
						screen(ab,ac+2);
						chdata[ac+2][ab]=83/*S*/;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab,ac-2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if(((chdata[ac+2][ab]==83/*S*/ || chdata[ac+2][ab]==115/*s*/) && (ac+2<27)) && ((chdata[ac-2][ab]!=83/*S*/ && chdata[ac-2][ab]!=115/*s*/) && (chdata[ac-2][ab]!=79/*O*/ && chdata[ac-2][ab]!=111/*o*/)))
					{
						if(ab<55)
						{
							acol=((ab-1)/2)+64;
						}
						else
						{
							acol=((ab-1)/2)+70;
						}
						arow=(ac-2)/2;
						Sleep(100);
						screen(ab,ac-2);
						chdata[ac-2][ab]=83/*S*/;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab,ac+2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if((chdata[ac][ab+2]==83/*S*/ || chdata[ac][ab+2]==115/*s*/) && ((chdata[ac][ab-2]!=83/*S*/ && chdata[ac][ab-2]!=115/*s*/) && (chdata[ac][ab-2]!=79/*O*/ && chdata[ac][ab-2]!=111/*o*/)))
					{
						if(ab<55)
						{
							acol=(((ab-2)-1)/2)+64;
						}
						else
						{
							acol=(((ab-2)-1)/2)+70;
						}
						arow=ac/2;
						Sleep(100);
						screen(ab-2,ac);
						chdata[ac][ab-2]=83/*S*/;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab+2,ac);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if((chdata[ac][ab-2]==83 || chdata[ac][ab-2]==115) && ((chdata[ac][ab+2]!=83 && chdata[ac][ab+2]!=115) && (chdata[ac][ab+2]!=79 && chdata[ac][ab+2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab+2)-1)/2)+64;
						}
						else
						{
							acol=(((ab+2)-1)/2)+70;
						}
						arow=ac/2;
						Sleep(100);
						screen(ab+2,ac);
						chdata[ac][ab+2]=83;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab-2,ac);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if(((chdata[ac-2][ab+2]==83 || chdata[ac-2][ab+2]==115) && (ac+2<27)) && ((chdata[ac+2][ab-2]!=83 && chdata[ac+2][ab-2]!=115) && (chdata[ac+2][ab-2]!=79 && chdata[ac+2][ab-2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab-2)-1)/2)+64;
						}
						else
						{
							acol=(((ab-2)-1)/2)+70;
						}
						arow=(ac+2)/2;
						Sleep(100);
						screen(ab-2,ac+2);
						chdata[ac+2][ab-2]=83;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab+2,ac-2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if(((chdata[ac+2][ab-2]==83 || chdata[ac+2][ab-2]==115) && (ac-2>1)) && ((chdata[ac-2][ab+2]!=83 && chdata[ac-2][ab+2]!=115) && (chdata[ac-2][ab+2]!=79 && chdata[ac-2][ab+2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab+2)-1)/2)+64;
						}
						else
						{
							acol=(((ab+2)-1)/2)+70;
						}
						arow=(ac-2)/2;
						Sleep(100);
						screen(ab+2,ac-2);
						chdata[ac-2][ab+2]=83;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab-2,ac+2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if(((chdata[ac-2][ab-2]==83 || chdata[ac-2][ab-2]==115) && (ac+2<27)) && ((chdata[ac+2][ab+2]!=83 && chdata[ac+2][ab+2]!=115) && (chdata[ac+2][ab+2]!=79 && chdata[ac+2][ab+2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab+2)-1)/2)+64;
						}
						else
						{
							acol=(((ab+2)-1)/2)+70;
						}
						arow=(ac+2)/2;
						Sleep(100);
						screen(ab+2,ac+2);
						chdata[ac+2][ab+2]=83;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab-2,ac-2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if(((chdata[ac+2][ab+2]==83 || chdata[ac+2][ab+2]==115) && (ac-2>1)) && ((chdata[ac-2][ab-2]!=83 && chdata[ac-2][ab-2]!=115) && (chdata[ac-2][ab-2]!=79 && chdata[ac-2][ab-2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab-2)-1)/2)+64;
						}
						else
						{
							acol=(((ab-2)-1)/2)+70;
						}
						arow=(ac-2)/2;
						Sleep(100);
						screen(ab-2,ac-2);
						chdata[ac-2][ab-2]=83;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("S");
						screen(ab,ac);
						printf("O");
						screen(ab+2,ac+2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
					}
					if(((chdata[ac-2][ab-2]==83 || chdata[ac-2][ab-2]==115) && (chdata[ac-2][ab+2]==83 || chdata[ac-2][ab+2]==115)) && ((chdata[ac-2][ab]!=83 && chdata[ac-2][ab]!=115) && (chdata[ac-2][ab]!=79 && chdata[ac-2][ab]!=111)))
					{
						if(ab<55)
						{
							acol=((ab-1)/2)+64;
						}
						else
						{
							acol=((ab-1)/2)+70;
						}
						arow=(ac-2)/2;
						Sleep(100);
						screen(ab,ac-2);
						chdata[ac-2][ab]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab-2,ac-2);
						printf("S");
						screen(ab+2,ac-2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
					if(((chdata[ac+2][ab-2]==83 || chdata[ac+2][ab-2]==115) && (chdata[ac+2][ab+2]==83 || chdata[ac+2][ab+2]==115)) && ((chdata[ac+2][ab]!=83 && chdata[ac+2][ab]!=115) && (chdata[ac+2][ab]!=79 && chdata[ac+2][ab]!=111)))
					{
						if(ab<55)
						{
							acol=((ab-1)/2)+64;
						}
						else
						{
							acol=((ab-1)/2)+70;
						}
						arow=(ac+2)/2;
						Sleep(100);
						screen(ab,ac+2);
						chdata[ac+2][ab]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab-2,ac+2);
						printf("S");
						screen(ab+2,ac+2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
					if(((chdata[ac-2][ab+2]==83 || chdata[ac-2][ab+2]==115) && (chdata[ac+2][ab+2]==83 || chdata[ac+2][ab+2]==115)) && ((chdata[ac][ab+2]!=83 && chdata[ac][ab+2]!=115) && (chdata[ac][ab+2]!=79 && chdata[ac][ab+2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab+2)-1)/2)+64;
						}
						else
						{
							acol=(((ab+2)-1)/2)+70;
						}
						arow=ac/2;
						Sleep(100);
						screen(ab+2,ac);
						chdata[ac][ab+2]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab+2,ac-2);
						printf("S");
						screen(ab+2,ac+2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
					if(((chdata[ac-2][ab-2]==83 || chdata[ac-2][ab-2]==115) && (chdata[ac+2][ab-2]==83 || chdata[ac+2][ab-2]==115)) && ((chdata[ac][ab-2]!=83 && chdata[ac][ab-2]!=115) && (chdata[ac][ab-2]!=79 && chdata[ac][ab-2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab-2)-1)/2)+64;
						}
						else
						{
							acol=(((ab-2)-1)/2)+70;
						}
						arow=ac/2;
						Sleep(100);
						screen(ab-2,ac);
						chdata[ac][ab-2]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab-2,ac-2);
						printf("S");
						screen(ab-2,ac+2);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
				}
				if(chdata[ac][ab]==83 || chdata[ac][ab]==115)
				{
					if((chdata[ac][ab+4]==83 || chdata[ac][ab+4]==115) && ((chdata[ac][ab+2]!=83 && chdata[ac][ab+2]!=115) && (chdata[ac][ab+2]!=79 && chdata[ac][ab+2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab+2)-1)/2)+64;
						}
						else
						{
							acol=(((ab+2)-1)/2)+70;
						}
						arow=ac/2;
						Sleep(100);
						screen(ab+2,ac);
						chdata[ac][ab+2]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab,ac);
						printf("S");
						screen(ab+4,ac);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
					if(((chdata[ac-4][ab]==83 || chdata[ac-4][ab]==115) && (ac-4>1)) && ((chdata[ac-2][ab]!=83 && chdata[ac-2][ab]!=115) && (chdata[ac-2][ab]!=79 && chdata[ac-2][ab]!=111)))
					{
						if(ab<55)
						{
							acol=((ab-1)/2)+64;
						}
						else
						{
							acol=((ab-1)/2)+70;
						}
						arow=(ac-2)/2;
						Sleep(100);
						screen(ab,ac-2);
						chdata[ac-2][ab]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab,ac);
						printf("S");
						screen(ab,ac-4);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
					if(((chdata[ac-4][ab+4]==83 || chdata[ac-4][ab+4]==115) && (ac-4>1)) && ((chdata[ac-2][ab+2]!=83 && chdata[ac-2][ab+2]!=115) && (chdata[ac-2][ab+2]!=79 && chdata[ac-2][ab+2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab+2)-1)/2)+64;
						}
						else
						{
							acol=(((ab+2)-1)/2)+70;
						}
						arow=(ac-2)/2;
						Sleep(100);
						screen(ab+2,ac-2);
						chdata[ac-2][ab+2]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab,ac);
						printf("S");
						screen(ab+4,ac-4);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
					if(((chdata[ac-4][ab-4]==83 || chdata[ac-4][ab-4]==115) && (ac-4>1)) && ((chdata[ac-2][ab-2]!=83 && chdata[ac-2][ab-2]!=115) && (chdata[ac-2][ab-2]!=79 && chdata[ac-2][ab-2]!=111)))
					{
						if(ab<55)
						{
							acol=(((ab-2)-1)/2)+64;
						}
						else
						{
							acol=(((ab-2)-1)/2)+70;
						}
						arow=(ac-2)/2;
						Sleep(100);
						screen(ab-2,ac-2);
						chdata[ac-2][ab-2]=79;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						printf("O");
						screen(ab,ac);
						printf("S");
						screen(ab-4,ac-4);
						printf("S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						if(colind==81)
						{	
							colind = 0;
							rowind++;
						}
						else
						{
							colrow[rowind][colind]=arow;
							colind++;
							colrow[rowind][colind]=acol;
							colind++;
						}
						goto AI;
					}
				}
			}
		}
comp:
	    b= random(65,90);
		Sleep(1000);
		c=random(97,109); 
		Sleep(1000);
		roww=random(1,13);
		Sleep(1000);
		d=random(0,10);
		if(d<5)
		{
			r=b;
		}
		if(d>5)
		{
			r=c;
		}
		Sleep(1000);
		a=random(9,20);
		if(a<15)
		{
			ch='S';
		}
		if(a>15)
		{
			ch='O';
		}
		waste=0;
		if(r<91)
		{
			chint = 2*(r-63)-1;
		}
		else
		{
			chint = 2*(r-69)-1;
		}
		rowdat2=roww*2;
		/*
		for(ac=2;ac<27;ac=ac+2)
		{
			for(ab=3;ab<80;ab=ab+2)
			{
				if(ch=='O')
				{
					if(((chdata[rowdat-2][chint]==83 || chdata[rowdat-2][chint]==115) || (chdata[rowdat-2][chint]==79 || chdata[rowdat-2][chint]==111)) && ((chdata[rowdat+2][chint]!=83 || chdata[rowdat+2][chint]!=115) && (chdata[rowdat+2][chint]!=79 || chdata[rowdat+2][chint]!=111)))
					{
						
					}
				}
				else
				{
					
				}
			}
		}
		*/
compstart:
		chdata[rowdat2][chint]=(int)(ch);
		for(rc=0;rc<14;rc++)
		{
			for(cc=0;cc<81;cc=cc+2)
			{
				if((colrow[rc][cc]==roww) && colrow[rc][cc+1]==r)
				{
					goto comp;
				}
			}
		}
		if(colind==81)
		{
			colind = 0;
			rowind++;
		}
		else
		{
			colrow[rowind][colind]=roww;
			colind++;
			colrow[rowind][colind]=r;
			colind++;
		}
		fill_int(r,roww,ch);
	}
}
void main()
{
	int i;
	draw();
	input();
}
