#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
long long A[105000],B[105000];
bool cmp(const long long &a,const long long &b)
{
	return a>b;
}
void solve()
{
	long long M,N,a,i,k,s=0;
	scanf(" %lld %lld",&M,&N);
	FOR(i,1,N) scanf(" %lld",&A[i]);
	sort(A+1,A+N+1,cmp);
	FOR(i,2,N)
	{
		k=M-(i-1)*(A[i-1]-A[i]);
		if(k>0) M=k;
		else break;
	}
	k=i;
	a=k-1;
	FOR(i,1,a) B[i]=A[a];
	FOR(i,1,M%a) B[i]-=M/a+1;
	FOR(i,M%a+1,M) B[i]-=M/a;
	FOR(i,k,N) s+=A[i]*A[i];
	FOR(i,1,a) s+=B[i]*B[i];
	printf("%lld\n",s);
}
int main()
{
	solve();
	return 0;
}


