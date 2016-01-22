#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 524288
using namespace std;
int H,N;
int ST[4*MAXN+5];
void update(int pos,int s,int e,int a,int b)
{
	if(a <= s && e <= b) { ST[pos]++; return; }
	if(b < s || e < a) return;
	int m = (s+e)/2;
	update(pos*2,s,m,a,b);
	update(pos*2+1,m+1,e,a,b);
}
int find(int a)
{
	int pos = MAXN + a - 1,res(0);
	while(pos)
	{
		res+=ST[pos];
		pos >>= 1;
	}
	return res;
}
void solve()
{
	int a,i,mini(2000000000),res,t;
	scanf("%d %d",&N,&H);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		if(i&1) update( 1 , 1 , MAXN , 1 , a);
		else 		update( 1 , 1 , MAXN , H-a+1 , H );
	}
	FOR(i,1,H)
	{
		t = find(i);
		if(t < mini)
		{
			mini = t;
			res = 0;
		}
		res += (t == mini);
	}
	printf("%d %d\n",mini,res);
}
int main()
{
	solve();
	return 0;
}
