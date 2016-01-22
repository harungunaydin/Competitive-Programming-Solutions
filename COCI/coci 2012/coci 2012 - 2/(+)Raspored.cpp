#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 200005
#define MAXT 200000
using namespace std;
typedef pair < long long , long long > pll;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
pll P[MAXN];
long long A[MAXN] , FW[MAXN];
int C,N;
class fenwick
{
	public:
		long long FW[MAXN];
		void update(int x,long long s)
		{
			x++;
			for(int i = x; i; i -= i&-i) FW[i] += s;
		}
		long long find(int a,int b)
		{
			a++; b++;
			long long res(0);
			int i;
			for(i = a; i < MAXN; i += i&-i) res += FW[i];
			for(i = b + 1; i < MAXN; i += i&-i) res -= FW[i];
			return res;
		}
} F1 , F2 ;
void solve()
{
	long long T(0);
	int a,b,c,i;
	N = read(); C = read();

	FOR(i,1,N)
	{
		P[i].f = read() , P[i].s = read();
		A[i] = P[i].s;
		T += P[i].f;
		F1.update( P[i].s , P[i].s );
		F2.update( P[i].s , 1ll );
	}

	long long s(0),t(0),t1,t2;
	sort(A+1,A+N+1);

	FOR(i,1,N)
		t += s += A[i];

	printf("%lld\n" , T - t );

	while(C--)
	{
		a = read(); b = read(); c = read();

		if(P[a].s <= c)
		{

			t1 = F2.find( 0 , P[a].s );
			t2 = F2.find( 0 , c );

			t += F1.find( P[a].s + 1 , c );

			t -= (N-t1+1) * P[a].s;

			t += (N-t2+1) * c;

		}
		else
		{

			t1 = F2.find( 0 , c - 1 ) + 1;
			t2 = F2.find( 0 , P[a].s );

			t -= F1.find( c , P[a].s ) - P[a].s;

			t -= (N-t2+1) * P[a].s;

			t += (N-t1+1) * c;
		}

		T += b - P[a].f;

		//ESKIYI SIL
		F1.update( P[a].s , -P[a].s );
		F2.update( P[a].s , -1 );

		//YENIYI EKLE
		F1.update( c , c );
		F2.update( c , 1 );

		P[a] = make_pair(b,c);

		printf("%lld\n" , T - t );

	}

}
int main()
{
	solve();
	return 0;
}
