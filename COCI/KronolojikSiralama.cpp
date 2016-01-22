#include<iostream>
#include<cstdio>
using namespace std;
int A[10005],n,i,j,DP[10050],mx,ind,yaz[10050],k;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++,DP[i-1]=1)
		scanf("%d",&A[i]);
	for(i=1;i<=n;++i)
	{
		int _max=-999;
		for(j=i-1;j>=1;j--)
		{
			if(A[i]>A[j])
				_max=max(_max,DP[j]);
		}
		if(_max!=-999)
		DP[i]+=_max;
	}
	for(i=1;i<=n;i++)
	{
		if(DP[i]>mx)
		{
			mx=DP[i];
			ind=i;
		}
	}
	j=A[ind];
	cout << mx-- << endl;
	for(i=ind-1;i>=1;--i)
	{
		if(DP[i]==mx && A[ind] > A[i])
		{
			yaz[++k]=A[i];
			ind = i;
			mx--;
			if(!mx) break;
		}
	}
	for(i=k;i>=1;i--)
		printf("%d ",yaz[i]);
	printf("%d\n",j);
	return 0;
}
