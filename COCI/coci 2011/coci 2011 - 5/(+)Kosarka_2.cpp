#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
int A[3],T[3];
void solve()
{
	int N,a,b,c,d,i,pre(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d : %d",&a,&b,&c);
		d = b*60 + c;
		if(A[1] > A[2]) T[1]+=d-pre;
		else if(A[1] < A[2]) T[2]+=d-pre;
		pre = d;
		A[a]++;
	}
	if(A[1] > A[2]) T[1]+=2880-pre;
	else if(A[1] < A[2]) T[2]+=2880-pre;
	a = T[1]/60; b = T[1]%60;
	printf("%d%d:%d%d\n",a/10,a%10,b/10,b%10);
	a = T[2]/60; b = T[2]%60;
	printf("%d%d:%d%d\n",a/10,a%10,b/10,b%10);
}
int main()
{
	solve();
	return 0;
}
