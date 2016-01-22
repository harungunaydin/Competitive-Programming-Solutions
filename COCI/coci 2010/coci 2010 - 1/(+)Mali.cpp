#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100
using namespace std;
vector < int > V1,V2;
int A[MAXN+5],B[MAXN+5],TA[MAXN+5],TB[MAXN+5];
void solve()
{
	int N,Amax,Bmin,a,b,i,j,k,res;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		res = 0;
		A[a]++; B[b]++;
		FOR(j,1,MAXN)
			TA[j] = A[j],TB[j] = B[j];
		Amax = MAXN; Bmin = 1;
		while(1)
		{
			while(Amax && !TA[Amax]) Amax--;
			while(Bmin <= MAXN && !TB[Bmin]) Bmin++;
			if(Bmin == MAXN + 1 && !Amax) break;
			res = max ( res , Amax + Bmin );
			k = min ( TA[Amax] , TB[Bmin] );
			TA[Amax]-=k;
			TB[Bmin]-=k;
		}
		printf("%d\n",res);
	}
}
int main()
{
	solve();
	return 0;
}
