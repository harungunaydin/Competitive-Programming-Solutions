#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 15
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
pii P[MAXN];
int N,s;
int A[MAXN] , C[MAXN];
int B[MAXN][MAXN];
bool H[MAXN];
pii bul(int x)
{
	int a(0),b(0),i,j;
	FOR(i,1,N)
		if(C[i] == B[x][i])
			a += C[i];

	FOR(i,1,N)
		FOR(j,1,N)
			if(i != j && C[i] == B[x][j])
			{
				b += C[i];
				break;
			}

	return make_pair(a,b);

}
void Try()
{
	pii p;
	int i;
	FOR(i,1,N)
	{
		p = bul(i);
		if(p.f != P[i].f || p.s != P[i].s) return;
	}

	FOR(i,1,N)
		printf("%d " , C[i] );

	exit(0);

}
void rec(int x)
{
	if(x == N + 1) { Try(); return; }

	int i;
	FOR(i,1,9)
		if(!H[i])
		{
			H[i] = true;
			C[x] = i;
			rec(x+1);
			H[i] = false;
		}

}
void solve()
{
	int i,j;
	N = read();
	FOR(i,1,N)
	{
		P[i].f = read(); P[i].s = read();
		FOR(j,1,N)
			scanf("%d" , B[i] + j );
	}

	rec(1);

	printf("s = %d\n" , s );

}
int main()
{
	solve();
	return 0;
}
