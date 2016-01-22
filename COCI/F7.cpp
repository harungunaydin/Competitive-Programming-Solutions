#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,puan,cnt,_max;
int A[300005];
int main()
{
	register int i,j,jj,t;
	register bool w;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort( A + 1 , A + n + 1);
	puan=1;
	for(i=n;i>=1;i--)
		{
			if(A[i]+n>=_max)
				cnt++;
			_max=max(_max,A[i]+puan);
			puan++;
		}
	printf("%d\n",cnt);
	return 0;
}
