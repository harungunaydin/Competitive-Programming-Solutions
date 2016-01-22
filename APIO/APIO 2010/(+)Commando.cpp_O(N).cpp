#include <cstdio>
#include <deque>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 1000005
using namespace std;
typedef pair < long long , long long > pll;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
deque < pll > dq;
long long T[MAXN];
int K,N;
double inter_x( pll l1 , pll l2 ) { return (double) (l1.s - l2.s) / (l2.f - l1.f); };
void add(pll l)
{
	while( dq.size() >= 2 && inter_x(l,dq.back()) > inter_x(dq.back(),dq[dq.size()-2]) ) dq.pop_back();
	dq.push_back( l );
}
void find(int x)
{
	while( dq.size() >= 2 && x < inter_x( dq[0],dq[1] ) ) dq.pop_front();
}
void solve()
{
	N = read();
	long long a = read() , b = read() , c = read() , t , x;
	int i,k;
	FOR(i,1,N)
		T[i] = T[i-1] + read();

	t = a * T[N] * T[N];

	TFOR(i,N,1)
	{
		add( make_pair( T[i] , t ) );

		k = T[i-1];
		x = b - 2*a*k;
		find(x);

		t = dq[0].f * x + dq[0].s + 2*a*k*k - b*k + c;

	}

	printf("%lld\n" , t );

}
int main()
{
	solve();
	return 0;
}
