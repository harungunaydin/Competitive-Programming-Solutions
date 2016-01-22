#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
int n,k,A[105],v[105][105],DP[105][105];
unsigned long long int cnt;
int solve(int ind,int bound)
{
	register int i=1,t=0;
	if(DP[ind][bound]) return DP[ind][bound];
	if(ind==k+1) { return 1;}
	while(v[ind][i])
	{
		if(v[ind][i]>bound)
		t+=solve(ind+1,v[ind][i]);
		i++;
	}
	return DP[ind][bound]=t;
}
int main()
{
	register int i,j,a,l,_max;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
	scanf("%d",&A[i]);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a);
		for(j=1,l=0;j<=n;j++)
			if(A[j]+a==10)
				v[i][++l]=j;
	}
	for(i=k;i >=1 ;i--)
	solve(i,0);
	printf("%d\n",DP[1][0]);
	return 0;
}
