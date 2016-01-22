#include<iostream>
#include<cstring>
#include<cstdio>
#define control(x,y) (x>=1 && y>=1 && x<=n && y<=n)
#define f first
#define s second
#define mp make_pair
using namespace std;
char A[20][20],S[260];
int n,x=1,y=1;
pair < int , int > yol[105];
int main()
{
	register int i,j,a,xx,yy,sag,sol,alt,ust;
	scanf("%d %s",&n,S);
	a=strlen(S);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			A[i][j]='.';
	yol['U']=mp(-1,0),yol['D']=mp(1,0),yol['L']=mp(0,-1),yol['R']=mp(0,1);
	for(i=0;i<a;i++)
	{
		xx=x+yol[ S[i] ].f,yy=y+yol[ S[i] ].s;
		if(control(xx,yy))
		{
			A[x][y]='+';
			A[xx][yy]='+';
			x=xx;
			y=yy;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(A[i][j]=='.') continue;
			alt=ust=sag=sol=0;
			x=i,y=j;

			xx=x+yol['D'].f,yy=y+yol['D'].s;
			if(control(xx,yy) && A[xx][yy]!='.') alt=1;

			xx=x+yol['U'].f,yy=y+yol['U'].s;
			if(control(xx,yy) && A[xx][yy]!='.') ust=1;

			xx=x+yol['R'].f,yy=y+yol['R'].s;
			if(control(xx,yy) && A[xx][yy]!='.') sag=1;

			xx=x+yol['L'].f,yy=y+yol['L'].s;
			if(control(xx,yy) && A[xx][yy]!='.') sol=1;

			if((sol && sag) && (ust && alt)) continue;

			if(sol && sag) A[i][j]='-';
			if(ust && alt) A[i][j]='|';
		}
	for(i=1;i<=n;i++,printf("\n"))
		for(j=1;j<=n;j++)
			printf("%c",A[i][j]);
	return 0;
}
