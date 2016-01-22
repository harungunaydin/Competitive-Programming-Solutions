#include <algorithm>
#include <cstdio>
#include <vector>
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
	while(1){
		c = getchar();
		if('0' <= c && c <= '9') { res = c - '0'; break; }
		else if(c == '-') { sign = -1; break; }
	}
	while(1){
		c = getchar();
		if( c > '9' || c < '0' ) return res * sign;
		if('0' <= c && c <= '9') res = res * 10 + c - '0';
	}
}
vector < int > G[MAXN] , V[MAXN];
int E,N,dis;
int M[MAXN] , S[MAXN] , T[MAXN];
int dfs(int x)
{
	S[x] = M[x] = ++dis;
	int i;
	V[x].push_back(0);
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(!S[*it])
		{
			T[x] += dfs(*it);

			if(M[*it] < M[x]) M[x] = M[*it];

			if(M[*it] < S[x]) V[x][0] += T[*it];
			else V[x].push_back( T[*it] );

		}
		else if(S[*it] < M[x])
			M[x] = S[*it];


	V[x][0] += ( N - (++T[x]) );

	return T[x];

}
void solve()
{
	int a,b,i;
	N = read(); E = read();
	FOR(i,1,E)
	{
		a = read(); b = read();
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1);

	long long res(0),t;
	vector < int > :: iterator it;
	FOR(i,1,N)
	{
		if(V[i].size() == 1) { printf("%d\n" , 2*N - 2 ); continue; }

		t = res = 0;
		for(it = V[i].begin(); it != V[i].end(); ++it)
		{
			res += t * (long long)(*it);
			t += (long long)*it;
		}

		printf("%lld\n" , 2ll * ( res + (N-1) ) );
	}

}
int main()
{
	solve();
	return 0;
}
