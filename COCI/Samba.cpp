#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[1000005],n,k,a,cnt;
int main()
{
	int i,j;
	cin >> n >> k;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	sort(A,A+n);
	for(i=0;i<=n;i++)
	{
		if(A[i]!=a)
		{
			if(cnt%k)
			{
				cout << a << endl;
				return 0;
			}
			a=A[i];
			cnt=0;
		}
		cnt++;
	}
	return 0;
}
