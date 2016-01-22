#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;
ii A[10005];
int n;
int DP[305][305];
bool H[305][305];
int mcp(int bas , int son)
{
	if(DP[bas][son] != -1) return DP[bas][son];
	if(bas+1>=son) return 0;
	register int i,t=0;
	for(i=bas+1;i<son;++i)
	{
		t=max(t,mcp(bas,i)+mcp(i,son)+H[bas][son]);
	}
	return DP[bas][son]=t;
} 
int main()
{

	memset( DP , -1 , sizeof DP );
	register int i,j,a,b,bs=999999,sn=-999999;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		bs=min(bs,a-b);
		sn=max(sn,a+b);
		H[a-b+100][a+b+100]=1;
	}
	printf("%d\n",n-mcp(bs+100,sn+100));
	return 0;
}
