#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define BASE 10009
#define MAXN 500005
using namespace std;
typedef pair < int , int > pii;
vector < int > V[MAXN];
pii q[4*MAXN];
int B[MAXN] , H[MAXN] , us[MAXN];
int N;
char A[MAXN];
int read() { int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if( c > '9' || c < '0' ) return res * sign; if('0' <= c && c <= '9') res = res * 10 + c - '0'; }
}
void solve()
{
	int Q,a,a2,b,b2,c,d,i,j,k,res,s(0),t;
	
	N = read();
	scanf("%s" , A+1 );

	us[0] = 1;
	FOR(i,1,N)
	{
		H[i] = H[i-1] * BASE + A[i];
		us[i] = us[i-1] * BASE;
		if(A[i] == A[i-1]) B[i] = B[i-1] + 1;
		else B[i] = 1;
	}

	FOR(i,2,N)
		for(j = 2*i; j <= N; j += i)
			V[j].push_back(i);

	vector < int > :: iterator it;

	Q = read();

	FOR(i,1,Q)
		q[i].f = read() ,  q[i].s = read();

	FOR(i,1,Q)
	{
		a = q[i].f; b = q[i].s;

		t = b - a + 1;

		res = t;

		if(B[b] >= t) { printf("1\n"); continue; }

		for(it = V[t].begin(); it != V[t].end(); ++it)
		{
			k = *it;
			a2 = a + k;
			b2 = b - k + 1;

			d = us[k];

			c = H[a2-1] - H[a-1] * d;

			for(j = a2; j <= b2; j += k)
				if( H[j+k-1] - H[j-1] * d != c )
					break;

			if(j > b2) { res = k; break; }

			}

		printf("%d\n" , res );

	}

}
int main()
{
	solve();
	return 0;
}
