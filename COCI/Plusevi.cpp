#include<iostream>
#include<cstdio>
using namespace std;
char c;
int top[3005][3005],sum[3005][3005],all[3005][3005],cnt;
char A[3005][3005];
int main()
{
	register int i,j,k,n,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",A[i]);
		for(j=1;j<=n;j++)
			all[i][j]=all[i-1][j]+all[i][j-1]-all[i-1][j-1]+(A[i][j-1]-'0');
	}
	t=n/2;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			{
				if(A[i][j-1]=='1')
				{
					int t=max(i,j);
					for(k=1;t+k<=n;k++)
					{
						if(i-k-1<0 || j-k-1<0 || all[i+k][j+k]-all[i+k][j-k-1]-all[i-k-1][j+k]+all[i-k-1][j-k-1]>4*k+1) break;
						if(all[i+k][j+k]-all[i+k][j-k-1]-all[i-k-1][j+k]+all[i-k-1][j-k-1]==4*k+1 &&
						   all[i+k][j]-all[i+k][j-1]-all[i-k-1][j]+all[i-k-1][j-1]==2*k+1 &&
						   all[i][j+k]-all[i-1][j+k]-all[i][j-k-1]+all[i-1][j-k-1]==2*k+1)
						cnt++;
					}
				}
			}
	printf("%d\n",cnt);
	return 0;
}
