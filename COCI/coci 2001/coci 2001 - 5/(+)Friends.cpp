#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int C,F,N,mini=2000000000,n,R,s,top;
int A[1000][1000],comb[20][10],maximum[20][10];
bool hash[100000];
void read()
{
	int c,i,x,y;
	scanf("%d %d %d %d",&F,&R,&N,&C);
	n=N/2;
	FOR(i,1,C)
	{
		scanf("%d %d %d",&x,&y,&c);
		A[x][y]+=c;
		A[y][x]+=c;
		top+=c;
	}
	top*=R;
	R-=F;
}

void dene()
{
	int i,t=top;
	FOR(i,1,N)
		t-=A[comb[1][i]][comb[2][i]]*R;
	if(t<mini)
	{
		mini=t;
		FOR(i,1,n)
			maximum[1][i]=comb[1][i],maximum[2][i]=comb[2][i];
	}
}
void izracunaj2(int x,int y)
{
	comb[2][x]=y;
	if(x==n)
	{
		dene();
		return;
	}
	int i;
	FOR(i,comb[1][x]+1,N)
		if(!hash[i])
		{
			hash[i]=true;
			izracunaj2(x+1,i);
			hash[i]=false;
		}
}
void izracunaj(int x,int y)
{
	comb[1][x]=y;
	int i;
	if(x==n)
	{
		izracunaj2(1,comb[1][1]+1);
		return;
	}
	FOR(i,y+1,N-1)
		if(!hash[i])
		{
			hash[i]=true;
			izracunaj(x+1,i);
			hash[i]=false;
		}
}
int main()
{
	int i;
	read();
	hash[1]=1;
	izracunaj(1,1);
	printf("%d\n",mini);
	FOR(i,1,n)
		printf("%d %d\n",maximum[1][i],maximum[2][i]);
	return 0;
}
