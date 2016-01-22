#include<iostream>
#include<cstdio>
using namespace std;
int n,A[1000005],H[1000005],m,cnt;
int main()
{
	int i,j;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		H[A[i]]++;
	}
	cin >> m;
	for(i=1;i<=n;i++)
		if(m-A[i]>=0 && H[m-A[i]])
			cnt++;
	cout << cnt / 2 << endl;
	return 0;
}
