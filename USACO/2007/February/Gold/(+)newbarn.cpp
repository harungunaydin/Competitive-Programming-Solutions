#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define ABS(x) ( ( (x) > 0 ) ? (x) : -(x) )
#define MAXN 10001
using namespace std;
map < pair < int , int > , bool > mp;
int Min( int a , int b ) { return a < b ? a : b; }
int N;
int X[MAXN],X2[MAXN],Y[MAXN],Y2[MAXN];

int H(int x,int y)
{
	register int i,s(0);
	FOR(i,1,N)
		s += ABS(X[i] - x) + ABS(Y[i] - y);
	return s;
}
bool cont(int x,int y)
{
	register int i;
	FOR(i,1,N)
		if(X[i] == x && Y[i] == y)
			return true;
	return false;
}
void solve()
{
	register int i,j,s,t,x,x2,y,y2;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",X+i,Y+i);
		X2[i] = X[i]; Y2[i] = Y[i];
	}
	sort(X2+1,X2+N+1);
	sort(Y2+1,Y2+N+1);
	if(N&1)
	{
		x = X2[N/2+1];
		y = Y2[N/2+1];
		durak1:
		if(cont(x,y))
		{
			t = Min( Min(H(x,y+1),H(x+1,y)) , Min(H(x-1,y),H(x,y-1)) );
			s = (H(x,y+1) == t) + (H(x+1,y) == t) + (H(x-1,y) == t) + (H(x,y-1) == t);
			printf("%d %d\n",t,s);
		}
		else
			printf("%d 1\n" , H(x,y));
	}
	else
	{
		x = X2[N/2];
		y = Y2[N/2];
		x2 = X2[N/2+1];
		y2 = Y2[N/2+1];
		if(x == x2 && y == y2)
			goto durak1;
		s = 0;
		FOR(i,1,N)
			s += (x <= X[i] && X[i] <= x2 && y <= Y[i] && Y[i] <= y2);
		printf("%d %d\n" , H(x,y) , (x2 - x + 1) * (y2 - y + 1) - s );
	}
}
int main()
{
	solve();
	return 0;
}
