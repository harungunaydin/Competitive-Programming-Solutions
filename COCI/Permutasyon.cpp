#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,K,cnt;
int G[20][20],A[20];
int gcd(int a,int b)
{
	return (!b) ? a : gcd(b,a%b);
}
int main()
{
	register int i,j,k,aa,bb;
	register bool w;
	scanf("%d %d %d",&n,&m,&K);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A + 1,A + n + 1);
	do
	{
		w=0;
		for(i=1;i<n;i++)
		{
			if(gcd(A[i],A[i+1])<K) w=1;
		}
		if(w) continue;
		m--;
		if(!m)
		{
			for(i=1;i<=n;i++)
			{
				printf("%d ",A[i]);
			}
			printf("\n");
			return 0;
		}
	}while(next_permutation(A + 1 , A + n + 1));
	printf("-1\n");
	return 0;
}
