#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 1000000007
#define MAXN 1002
using namespace std;
vector < int > G[MAXN];
int T[MAXN];
int DP[MAXN][MAXN];
bool B[MAXN];
int C(int n,int r)
{
	int &ret = DP[n][r];
	if(ret != -1) return ret;
	if(n == r || !r || n == 1) return ret = 1;
	return ret = ( C(n-1,r) + C(n-1,r-1) ) % MOD;
}
int rec(int x)
{
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		T[x] += rec(*it);
	return ++T[x];
}
int f(int x)
{
	if(G[x].empty()) return 1;
	long long res(1),s(T[x] - 1);
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
	{
		res = ( res * ( long long ) C(s,T[*it]) ) % MOD;
		res = ( res * ( long long ) f(*it) ) % MOD;
		s -= T[*it];
	}
	return res;
}
void solve()
{
	memset( T , 0 , sizeof T );
	memset( B , 0 , sizeof B );
	int N,a,b,i,root;
	scanf("%d",&N);
	FOR(i,1,N) G[i].clear();
	FOR(i,1,N-1)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		B[b] = true;
	}
	FOR(i,1,N)
		if(!B[i])
		{
			root = i;
			break;
		}

	rec(root);

	printf("%d\n" , f(root) % MOD );
}
int main()
{
	memset( DP , -1 , sizeof DP );
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
