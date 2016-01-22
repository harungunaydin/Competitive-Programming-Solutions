#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 500
using namespace std;
int T,N;
int A[MAXN+5],DP2[10005],RES[MAXN+5];
bool DP[10005],hash[MAXN+5];
void solve()
{
	int i,j,k(0),n,r(0),s(0),sum(0);
	scanf("%d %d",&T,&N);
	DP[0] = true;
	FOR(i,0,T) DP2[i] = 1;
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		TFOR(j,T,A[i])
			if(DP[j-A[i]] && !DP[j])
			{
				DP[j] = true;
				DP2[j] = i;
			}
	}
	i = T;
	while(!DP[i] && i>=0) i--;
	n = i;
	while(i)
	{
		hash[DP2[i]] = true;
		i-=A[DP2[i]];
	}
	s = 0;
	FOR(i,1,N)
		if(hash[i])
		{
			RES[i] = s;
			s+=A[i];
		}
	s = 0;
	FOR(i,1,N)
		if(!hash[i])
		{
			RES[i] = s;
			s+=A[i];
		}
	FOR(i,1,N)
		printf("%d ",RES[i]);
	s = 0;
}
int main()
{
	solve();
	return 0;
}
