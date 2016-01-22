#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
class zar
{
	public:
		int ust,sag,on;
		zar() { ust = sag = on = 0; }
		void set(int a,int b,int c) { ust = a; sag = b; on = c; }
};
long long M,N;
void solve()
{
	M = read(); N = read();
	long long res(0);
	int i,j;
	zar p;
	p.set(1,3,2);
	FOR(i,1,M)
	{
		if(i&1)
		{
			res += ( N / 4 ) * 14ll;
			FOR(j,(N/4)*4+1,N)
			{
				res += p.ust;
				if(j == N)
				{
					p.set( 7 - p.on , p.sag , p.ust );
					break;
				}
				p.set( 7 - p.sag , p.ust , p.on );
			}
		}
		else
		{

			res += (N / 4) * 14ll;

			TFOR(j,N%4,1)
			{
				res += p.ust;
				if(j == 1)
				{
					p.set( 7 - p.on , p.sag , p.ust );
					break;
				}
				p.set( p.sag , 7 - p.ust , p.on );
			}

		}
	}

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
