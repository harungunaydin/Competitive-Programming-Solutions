#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[15];
int solve()
{
	int a,b,i,s=0;
	FOR(i,1,10)
		scanf("%d",&A[i]);
	FOR(i,1,10)
	{
		if(A[i]+s>=100) break;
		s+=A[i];
	}
	a=abs(100-s);
	b=abs(s+A[i]-100);
	if(a==b) return max(A[i]+s,s);
	if(a<b) return s;
	return s+A[i];
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
