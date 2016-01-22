#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 500000
using namespace std;
long long A,B,C,M,N;
long long sag()
{
	long long t = B;
	B = A;
	return A = 7-t;
}
long long sol()
{
	long long t=B;
	B = 7-A;
	return A = t;
}
long long alt()
{
	long long t=C;
	C = A;
	return A = 7-t;
}
void solve()
{
	long long i,j,k,res(0),t;
	A = 1; B = 3; C = 2;
	scanf("%lld %lld",&M,&N);
	N--;
	FOR(i,1,M)
	{
		t = (i&1) ? sag() + sag() + sag() + sag() : sol() + sol() + sol() + sol();
		res+=(N/4)*t;
		k = N%4;
		FOR(j,1,k)
			res+=(i&1) ? sag() : sol();
		if(i < M) res+=alt();
	}
	printf("%lld\n",res+1);
}
int main()
{
	solve();
	return 0;
}
