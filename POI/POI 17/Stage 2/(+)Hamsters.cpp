#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 20000000000000ll
#define BASE 1009ll
#define MAXN 205
using namespace std;
vector < long long > H[MAXN];
string str[MAXN];
int M,N;
long long us[100005];
long long APSP[MAXN][MAXN] , RES[MAXN][MAXN] , TMP[MAXN][MAXN];
long long get_hash(int x,int a,int b)
{
	if(a) return H[x][b] - H[x][a-1] * us[b-a+1];
	return H[x][b];
}
int f(int a,int b)
{
	int i , k = str[a].size() - 1 , t = min( str[a].size() , str[b].size() ) - 1;

	if(a == b) t--;

	for(i = t; i > 0; i--)
		if(get_hash(a,k-i+1,k) == get_hash(b,0,i-1))
			return str[b].size() - i;
	return str[b].size() - i;
}
void hallet()
{
	int i,j,k;
	bool flag = true;
	while(M)
	{
		if(M&1)
		{
			if(flag)
			{
				FOR(i,0,N)
					FOR(j,0,N)
						RES[i][j] = APSP[i][j];
				flag = false;
			}
			else
			{
				fill( TMP[0] , TMP[202]+202 , INF );

				FOR(k,1,N)
					FOR(i,0,N)
						FOR(j,1,N)
							TMP[i][j] = min( TMP[i][j] , RES[i][k] + APSP[k][j] );
	
				FOR(i,0,N)
					FOR(j,0,N)
						RES[i][j] = TMP[i][j];
			}
		}

		fill( TMP[0] , TMP[202]+202 , INF );

		FOR(k,1,N)
			FOR(i,0,N)
				FOR(j,1,N)
					TMP[i][j] = min( TMP[i][j] , APSP[i][k] + APSP[k][j] );

		FOR(i,0,N)
			FOR(j,0,N)
				APSP[i][j] = TMP[i][j];

		M >>= 1;
	}
}
void solve()
{
	int i,j;
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
	{
		cin >> str[i];
		H[i].resize( str[i].size() , 0 );
		H[i][0] = str[i][0];
		for(j = 1; j < (int) str[i].size(); j++)
			H[i][j] = H[i][j-1] * BASE + str[i][j];
	}
	us[0] = 1;
	FOR(i,1,100000)
		us[i] = us[i-1] * BASE;

	fill( TMP[0] , TMP[202]+202 , INF );

	FOR(i,1,N)
		FOR(j,1,N)
			APSP[i][j] = f(i,j);

	FOR(i,1,N)
		APSP[0][i] = (int) str[i].size();

	hallet();

	printf("%lld\n" , *min_element(RES[0]+1,RES[0]+N+1) );

}
int main()
{
	solve();
	return 0;
}
