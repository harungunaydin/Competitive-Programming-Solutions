#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 
using namespace std;
typedef pair < int , int > pii;
long long K,N;
long long hesapla(long long a)
{
	long long i,s(0);
	FOR(i,1,N)
		s += min( a / i , N);
	return s;
}
long long BS(long long bas,long long son)
{
	if(bas == son) return bas;
	long long orta = ( bas + son ) / 2;
	long long t = hesapla(orta-1);
	long long t2= hesapla(orta);
	if(t < K && K <= t2) return orta;
	if(t == K) return BS(bas,son-1);
	return (t > K) ? BS(bas,orta-1) : BS(orta+1,son);
}
int main()
{
	scanf("%lld %lld",&N,&K);
	printf("%lld\n" , BS(1,N*N) );
	return 0;
}
