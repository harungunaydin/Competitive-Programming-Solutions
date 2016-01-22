#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INF 2000000000
#define MAXN 100000
using namespace std;
int N,A,B;
int D[MAXN+5],LC[MAXN+5],LT[MAXN+5],RC[MAXN+5],RT[MAXN+5];
int hesapla(int x)
{
	return (x&1) ? LT[x] + RC[x+1] : LT[x-1] + RC[x+2];
}
void solve()
{
	int a,b,i,res(0),sum(0),t1,t2;
	scanf("%d %d %d",&A,&B,&N);
	D[0] = INF;
	FOR(i,1,N-1)
	{
		scanf("%d",D+i);
		sum+=D[i];
	}
	LT[1] = D[1];
	FOR(i,2,N)
		if(i&1)
			LT[i] = LT[i-2] + D[i];
	TFOR(i,N-1,1)
		if(!(i&1))
			RC[i] = RC[i+2] + D[i];
	t2 = RC[2];
	t1 = sum - t2;
	if(t1-t2 >= A && t1-t2 <= B) res--;
	FOR(i,0,N-1)
	{
		t1 = hesapla(i);
		t2 = sum - t1;
		if(!(i&1))
		{
			a = t1 - t2 + D[i+1];
			b = t1 - t2 + D[i] - 1;
		}
		else
		{
			b = t1 - t2 - D[i+1];
			a = t1 - t2 - D[i] + 1;
		}
		res+=max(0 , min(b,B) - max(a,A) + 1);
	}
	if(max(a,A) == 0) res--;
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
