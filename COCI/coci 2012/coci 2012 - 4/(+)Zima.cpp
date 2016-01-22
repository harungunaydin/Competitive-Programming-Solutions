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
pii P[MAXN];
int K,N;
int A[MAXN] , B[MAXN] , T[MAXN];
inline bool cmp( const pii &a , const pii &b )
{
	return a.s - a.f > b.s - b.f;
}
void hallet(int a,int b)
{
	int i , t = (b - a + 1) * 2;
	TFOR(i,a-1,a-t)
		B[i] = true;
}
int H(int a,int b)
{
	a = max(a,1);
	return T[b] - T[a-1];
}
void solve()
{
	int i,j;
	N = read();
	FOR(i,1,N)
		A[i] = read();

	FOR(i,1,N)
		if(A[i] < 0)
		{
			j = i;
			while(i <= N && A[i] < 0) i++;
			i--;
			P[++K] = make_pair(j,i);
		}

	sort( P+1,P+K+1 , cmp );

	FOR(i,1,K)
		hallet(P[i].f,P[i].s);

	FOR(i,1,N) T[i] = T[i-1] + !B[i];

	int k,maxi(0),max_index,t = P[1].s - P[1].f + 1;

	FOR(i,1,K)
		if(P[i].s - P[i].f + 1 == t)
		{
			k = H(P[i].f-3*t,P[i].f-1);
			if(k >= maxi)
			{
				maxi = k;
				max_index = i;
			}
		}

	int a = P[max_index].f;

	FOR(i,a-3*t,a-1) B[i] = 1;

	int res(0);

	FOR(i,1,N)
		res += B[i];

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
