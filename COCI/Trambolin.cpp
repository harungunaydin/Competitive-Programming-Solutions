#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int DP[300005],A[300005];
char S[300005];
bool H[3005][3005];
bool h[300005];
int n,p;
void solve(int bina)
{
	register int t=0,i;
	if(S[bina-1]=='.')
	{
		if(bina-1)
			if(!H[bina][bina-1])
			{
				h[bina-1]=1;
				H[bina][bina-1]=H[bina-1][bina]=1;
				t=1;
				solve(bina-1);
				H[bina][bina-1]=H[bina-1][bina]=0;
				h[bina-1]=0;
			}
		if(bina<=n)
			if(!H[bina][bina+1])
			{
				h[bina+1]=1;
				t=1;
				H[bina][bina+1]=H[bina+1][bina]=1;
				solve(bina+1);
				H[bina][bina+1]=H[bina+1][bina]=0;
				h[bina+1]=0;
			}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(!H[bina][i] && bina!=i)
			{
				t=1;
				h[i]=1;
				H[bina][i]=H[i][bina]=1;
				solve(i);
				H[bina][i]=H[i][bina]=0;
				h[i]=0;
			}
		}
	}
	if(!t)
	{
		for(i=1;i<=n;i++)
			printf("%d ",h[i]);
		printf("\n");
		return;
	}
}
int main()
{
	DP[0]=1;
	register int i;
	scanf("%d %d",&n,&p);
	for(i=1;i<=n;++i)
	scanf("%d",&A[i]);
	scanf("%s",S);
	solve(p);
	return 0;
}
