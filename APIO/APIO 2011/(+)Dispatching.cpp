#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 100005
#define MAXT 262145
using namespace std;
typedef pair < int , int > pii;
vector < int > ST[MAXT] , TREE[MAXN] , V[MAXN];
vector < long long > ST_T[MAXT];
pii P[MAXN];
long long M;
int K,N,dis;
long long A[MAXN] , C[MAXN] , Real[MAXN];
int F[MAXN] , L[MAXN] , S[MAXN];
void init_dfs(int x)
{
	S[x] = ++dis;
	vector < int > :: iterator it;
	for(it = TREE[x].begin(); it != TREE[x].end(); ++it)
		init_dfs(*it);
	F[x] = dis;
}
void hallet(int pos)
{
	if(ST[pos].empty()) return;
	ST_T[pos].resize( ST[pos].size() );
	ST_T[pos][0] = Real[ ST[pos][0] ];
	for(int i = 1; i < (int) ST[pos].size(); i++)
		ST_T[pos][i] = ST_T[pos][i-1] + Real[ ST[pos][i] ];
}
void init(int pos,int s,int e)
{
	if(s == e)
	{
		ST[pos] = V[s];
		hallet(pos);
		return;
	}
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	
	init(sol,s,m);
	init(sag,m+1,e);

	ST[pos].resize( ST[sol].size() + ST[sag].size() );

	merge( all(ST[sol]) , all(ST[sag]) , ST[pos].begin() );
	
	hallet(pos);

}
long long Hesapla(int pos,int a,int b)
{
	if(a > b) return 0;
	if(!a) return ST_T[pos][b];
	return ST_T[pos][b] - ST_T[pos][a-1];
}
long long find(int pos,int s,int e,int a,int b,long long k)
{
	if(ST[pos].empty()) return 0;
	if(s == e)
	{
		int a2 = lower_bound( all(ST[pos]) , a ) - ST[pos].begin();
		int b2 = upper_bound( all(ST[pos]) , b ) - ST[pos].begin() - 1;
		return max( 0ll , min( (long long)b2-a2+1 , k / ST_T[pos][0] ) );
	}
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	if(ST[sol].empty()) return find(sag,m+1,e,a,b,k);
	int a2 = lower_bound( all(ST[sol]) , a ) - ST[sol].begin();
	int b2 = upper_bound( all(ST[sol]) , b ) - ST[sol].begin() - 1;
	long long t = Hesapla(sol,a2,b2);
	if(t >= k) return find(sol,s,m,a,b,k);
	return b2 - a2 + 1 + find(sag,m+1,e,a,b,k-t);
}
void indirge()
{
	int i,j,s(0);
	FOR(i,1,N)
	{
		P[i] = make_pair( A[i] , i );
		Real[i] = A[i];
	}

	sort(P+1,P+N+1);

	FOR(i,1,N)
	{
		s++;
		j = i;
		while(i <= N && P[i].f == P[j].f) A[ P[i++].s ] = s;
		i--;
	}

	K = s;

}
void solve()
{
	int a,i,root;
	scanf("%d %lld",&N,&M);
	FOR(i,1,N)
	{
		scanf("%d %lld %d",&a,C+i,L+i);
		if(!a) root = i;
		else TREE[a].push_back(i);
	}

	init_dfs(root);

	FOR(i,1,N) // DIZIYI URET
		A[ S[i] ] = C[i];

	vector < int > T;

	FOR(i,1,N)
		T.push_back( A[i] );

	sort( all(T) );

	indirge(); // ELEMANLARI INDIRGE
	
	FOR(i,1,N) // ELEMANLARIN GECTIKLERI YERLERI VECTOR'E AT
		V[ A[i] ].push_back(i);

	init(1,1,K);
	long long res(0);
	FOR(i,1,N)
		res = max( res , (long long) L[i] * find(1,1,K,S[i],F[i],M) );

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
