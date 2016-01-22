#include<iostream>
#include<queue>
#include<cstdio>
#include<set>
#define mp make_pair
using namespace std;
int A[1005][1006],n,m,i,j,k,c,cnt,sum,DP[104][55][55];
bool H[10005];
int solve(int x , int a ,int b)
{
	if(x==n+1) return 0;
	if(DP[x][a][b]) return DP[x][a][b];
	int t=9999,tt=9999;
	if(a)
	t=solve(x+1,a-1,b) + A[1][x];
	if(b)
	tt=solve(x+1,a,b-1) + A[2][x];
	return DP[x][a][b] = min( t , tt );
}
int main()
{
	scanf("%d %d",&n,&m);
	n+=2;
	int a,b;
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			A[i][j]=99999999;
	for(i=0;i<=1000;i++)
	A[i][i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		a+=2;
		b+=2;
		if(!a) a=2;
		if(!b) b=2;
		A[a][b]=A[b][a]=c;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
	cout << solve(3,n/2-1,n/2-1) << endl;
	return 0;
}
