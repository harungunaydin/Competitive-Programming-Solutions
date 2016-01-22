#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 1100000
using namespace std;
typedef pair < int , int > pii;
vector < int > V[2*MAXN];
pii P[MAXN] , P2[MAXN];
int N;
int A[MAXN] , LMAX[MAXN] , RMIN[MAXN] , sta[MAXN];
void solve()
{
	int bas,a,b,i,j,k,s(0),s2(0),t;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		V[A[i]-i+MAXN].push_back(i);
	}

	A[N+1] = -1;
	bas = 0;
	FOR(i,1,N+1)
	{
		while(bas && A[sta[bas]] > A[i]) {  RMIN[sta[bas]] = i; bas--; }
		sta[++bas] = i;
	}

	bas = 0;
	A[0] = N+1;
	TFOR(i,N,0)
	{
		while(bas && A[sta[bas]] < A[i]) { LMAX[sta[bas]] = i; bas--; }
		sta[++bas] = i;
	}

	FOR(i,1,N)
	{
		t = A[i] - i;
		a = lower_bound( all(V[t+MAXN]) , i ) - V[t+MAXN].begin() + 1;
		while(a < (int) V[t+MAXN].size())
		{
			b = V[t+MAXN][a];
			if(b >= RMIN[i]) break;
			if( LMAX[b] < i ) { P[++s] = make_pair(i,b); break; }
			a++;
		}
	}

	int mini(N+1);
	TFOR(i,s,1)
		if(P[i].s < mini)
		{
			mini = P[i].s;
			P2[++s2] = P[i];
		}
	printf("%d\n" , s2 );
	TFOR(i,s2,1)
		printf("%d %d\n" , P2[i].f , P2[i].s );
}
int main()
{
	solve();
	return 0;
}
