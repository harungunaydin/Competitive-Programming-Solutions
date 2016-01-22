#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int n,i,bas,son,mal;
int A[500005];

int main()
{
	register int t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A +1 , A + n + 1);
	bas=1,son=n;
	while(bas!=son)
	{
		t=son-bas-1;
		if(A[bas]<=t)
		{
			mal+=A[bas];
			son-=A[bas];
			bas++;
		}
		else
		{
			mal+=son-bas;
			break;
		}
	}
	printf("%d\n",mal);
	return 0;
}
