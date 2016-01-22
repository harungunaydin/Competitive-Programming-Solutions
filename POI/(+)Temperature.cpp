#include <algorithm>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 1000005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
deque < int > dq;
pii P[MAXN];
void solve()
{
	int N,a,b,i,res(1);
	int bas(0),son(0);
	N = read();
	FOR(i,1,N)
		P[i].f = read() , P[i].s = read();

	while(bas <= son && son <= N)
	{
		if( bas == son || P[ dq.back() ].f <= P[son+1].s )
		{
			son++;
			if(!bas) bas++;
			while( !dq.empty() && P[ dq.front() ].f < P[son].f ) dq.pop_front();
			dq.push_front( son );
		}
		else if( dq.back() == bas++ ) dq.pop_back();

		if( bas > son || son > N) break;

		res = max( res , son - bas + 1 );

	}
	if(res == 20) res--;
	printf("%d\n" , res );

}
int main()
{
	freopen("temperature.gir","r",stdin);
	freopen("temperature.cik","w",stdout);
	solve();
	return 0;
}
