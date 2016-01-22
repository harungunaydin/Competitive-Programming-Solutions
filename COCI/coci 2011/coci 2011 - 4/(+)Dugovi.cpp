#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 200005
using namespace std;
typedef pair < int , int > pii;
vector < int > V;
vector < int > G[MAXN];
int N,vis;
int A[MAXN] , Borc[MAXN] , C[MAXN] , Dongu[MAXN] , Para[MAXN] , visited2[MAXN];
bool visited[MAXN];
void dfs(int x)
{
	if(visited[x]) return;
	visited[x] = true;
	V.push_back(x);
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		dfs(*it);
}
int coz()
{
	vis++;
	queue < int > Q;
	vector < int > :: iterator it;
	for(it = V.begin(); it != V.end(); ++it)
		if(!C[*it])
			Q.push(*it);

	int res(0),x;

	vis++;
	while(!Q.empty())//OK GIRMEYENLERDEN BASLA , DONGULER HARIC HALLET
	{
		x = Q.front(); Q.pop();

		visited2[x] = vis;

		if(Borc[x] >= Para[x])
			res += Borc[x] - Para[x];
		
		Para[ A[x] ] += Borc[x];

		if( --C[ A[x] ] == 0)
			Q.push( A[x] );
	}
	int k , mini(2100000000);

	for(it = V.begin(); it != V.end(); ++it)
		if( visited2[*it] != vis && Borc[*it] - Para[*it] < mini)
		{
			mini = Borc[*it] - Para[*it];
			x = *it;
		}

	vis++;

	while(1)
	{
		if(visited2[x] == vis) break;
		
		visited2[x] = vis;

		if( Borc[x] >= Para[x])
			res += Borc[x] - Para[x];

		Para[ A[x] ] += Borc[x];

		x = A[x];
	}

	return res;

}
void solve()
{
	int i,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",A+i,Borc+i);
		C[ A[i] ]++;
		G[i].push_back( A[i] );
		G[ A[i] ].push_back(i);
	}

	FOR(i,1,N)
		if(!visited[i])
		{
			V.clear();
			dfs(i);
			res += coz();
		}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
