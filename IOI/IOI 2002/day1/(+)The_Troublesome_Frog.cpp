#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define MAXN 5005
using namespace std;
typedef pair < int , int > pii;
pii P[MAXN];
int C,N,R;
bool hash[MAXN][MAXN];
int hallet(int i,int a,int b)
{
	int s(0),x,y;
	x = P[i].x; y = P[i].y;
	while(1)
	{
		x += a; y += b;
		s++;
		if(x < 1 || x > R || y < 1 || y > C) return s;
		if(!hash[x][y]) return 0;
	}
	return s;
}
void solve()
{
	int i,j,res(0),x,x2,y,y2;
	scanf("%d %d",&R,&C);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&P[i].x,&P[i].y);
		hash[ P[i].x ][ P[i].y ] = true;
	}

	sort(P+1,P+N+1);

	FOR(i,1,N)
		FOR(j,i+1,N)
		{
			x = P[j].x - P[i].x;
			y = P[j].y - P[i].y;
			x2 = P[i].x - x;
			y2 = P[i].y - y;
			if(x2 < 1 || x2 > R || y2 < 1 || y2 > C)
				res = max( res , hallet(i,x,y) );
		}
	if(res < 3) res = 0;
	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
