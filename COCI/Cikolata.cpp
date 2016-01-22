#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,A[1005],B[1005],DP[1005][1005];
int solve(int x,int y)
{
	if(DP[x][y]) return DP[x][y];
	if(x>n && y>m) return 0;
	register int a=999999999,b=999999999;
	if(x<=n)
		a=solve(x+1,y)+A[x]*y;
	if(y<=m)
		b=solve(x,y+1)+B[y]*x;
	return DP[x][y]=min(b,a);
}
int main()
{
	register int i,j;
	scanf("%d %d",&n,&m);
	n--;
	m--;
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&B[i]);
	sort( A + 1 , A + n + 1,greater<int>());
	sort( B + 1 , B + m + 1,greater<int>());
	printf("%d\n",solve(1,1));

	return 0;
}
