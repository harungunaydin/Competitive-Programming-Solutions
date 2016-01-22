#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
vector < pii > V[900001];
int M,N;
int T[MAXN];
char A[MAXN] , B[MAXN];
bool H1[MAXN] , H2[MAXN];
inline void solve()
{
	register int i,j,t;
	scanf("%s",A+1);
	scanf("%s",B+1);
	M = strlen(A+1);
	N = strlen(B+1);
	FOR(i,1,M) T[i] = T[i-1] + A[i] - '0';
	H1[0] = true;
	FOR(i,1,N)
		if(A[i] == B[i])
			H1[i] = true;
		else
			break;
	H2[N+1] = true;

	register int a = M;
	
	for(i = N; i >= 1; i--,a--)
		if(A[a] == B[i])
			H2[i] = true;
		else
			break;

	FOR(i,1,N)
	{
		t = 0;
		FOR(j,i,N)
		{
			t = t * 10 + B[j] - '0';
			if(t > 900000) break;
			if(i == j || A[i] != '0')
				V[t].push_back( make_pair(i,j) );
		}
	}
	vector < pii > :: iterator it;
	FOR(i,1,M)
		FOR(j,i,M)
		{
			t = T[j] - T[i-1];
			for(it = V[t].begin(); it != V[t].end(); ++it)
				if(N - it->s == M - j && it->f == i)
					if(H1[it->f-1] && H2[it->s+1] )
					{
						printf("%d %d\n" , i , j );
						return;
					}
		}
}
int main()
{
	freopen("fib.gir","r",stdin);
	freopen("fib.cik","w",stdout);
	solve();
	return 0;
}
