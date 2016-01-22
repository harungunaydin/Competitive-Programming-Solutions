#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INF 2000000000
#define MAXN 100000
using namespace std;
long long M,N;
long long A[MAXN+5];
long long hesapla(long long x)
{
	long long a,i,res(0);
	FOR(i,x+1,N)
		res+=A[i]*A[i];
	A[x]-=M/x;
	a = M%x;
	return res + a*(A[x]-1)*(A[x]-1) + (x-a)*A[x]*A[x] ;
}
long long solve()
{
	long long i,k;
	scanf("%lld %lld",&M,&N);
	FOR(i,1,N)
		scanf("%lld",A+i);
	sort(A+1,A+N+1,greater<int>());
	FOR(i,1,N)
		if(A[i] > A[i+1])
		{
			k = A[i] - A[i+1];
			if(M >= i*k) M-=i*k;
			else return hesapla(i);
		}
	return -1;
}
int main()
{
	printf("%lld\n",solve());
	return 0;
}
