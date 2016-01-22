#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[100005],K[100005];
int n,k,sum;
int main()
{
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	for(i=1,j=n;i<=j;++i,j--)
		if(i==j)
			K[++k]=A[i];
		else
			K[++k]=A[i],K[++k]=A[j];

	for(i=1;i<=k;i++)
	{
		sum+=K[i];
		if(K[i]<K[i+1])
			sum+=K[i+1]-K[i];
	}
	printf("%d\n",sum);
	return 0;
}
