#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 131072
using namespace std;
int ST[MAXN*2];
int sum(int pos)
{
	return pos ? ST[pos] + sum(pos>>1) : 0;
}
void update(int pos,int s,int e,int a,int b)
{
	if(pos > MAXN*2) return;
	if(a <= s && e <= b) { ST[pos]++; return; }
	if(b < s || e < a) return;
	int orta = (s+e)/2;
	update(pos*2,s,orta,a,b);
	update(pos*2+1,orta+1,e,a,b);
}
void solve()
{
	int N,a,b,i,x,y;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		x = sum(MAXN+a-1); y = sum(MAXN+b-1);
		printf("%d\n",x+y);
		ST[MAXN+a-1]-= x;
		ST[MAXN+b-1]-= y;
		update(1,1,MAXN,a+1,b-1);
	}
}
int main()
{
	solve();
	return 0;
}
