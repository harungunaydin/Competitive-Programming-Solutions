#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
int read()
{
	int res(0),sign(1);
	char c;
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') { res = c - '0'; break; }
	}
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') res = res*10 + c - '0';
		else break;
	}
	return res * sign;
}
int M,N,Q;
long long T[MAXN];
void update(int a,int b)
{
	T[a]++; T[b+1]--;
}
long long query(int a,int b)
{
	if(a) return T[b] - T[a-1];
	return T[b];
}
void solve()
{
	int a1,a2,b1,b2,c1,c2;
	int i;
	N = read();
	M = 24*60*60 - 1;
	FOR(i,1,N)
	{
		a1 = read(); b1 = read(); c1 = read();
		a1 = a1 * 3600 + b1 * 60 + c1;
		
		a2 = read(); b2 = read(); c2 = read();
		a2 = a2 * 3600 + b2 * 60 + c2;

		if(a1 > a2)
		{
			update(a1,M);
			update(0,a2);
		}
		else update(a1,a2);
	}

	FOR(i,1,M) T[i] += T[i-1];
	FOR(i,1,M) T[i] += T[i-1];

	Q = read();
	while(Q--)
	{
		a1 = read(); b1 = read(); c1 = read();
		a1 = a1 * 3600 + b1 * 60 + c1;

		a2 = read(); b2 = read(); c2 = read();
		a2 = a2 * 3600 + b2 * 60 + c2;
		
		if(a1 > a2) printf("%.10lf\n" , ( (double) query(a1,M) + (double) query(0,a2) ) / ( M - a1 + 1 + a2 + 1 ) );
		else printf("%.10lf\n" , ( (double)query(a1,a2) ) / (a2-a1+1) );
	}
}
int main()
{
	solve();
	return 0;
}
