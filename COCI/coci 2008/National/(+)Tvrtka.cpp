#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
vector < int > V[MAXN+5];
int A[MAXN+5];
bool cmp(const int &a , const int &b) { return A[a] > A[b]; }
void solve()
{
	int N,a,b,i,j;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	FOR(i,1,N-1)
	{
		scanf("%d %d",&a,&b);
		V[a].push_back(b);
	}
	FOR(i,1,N)
	{
		sort(all(V[i]),cmp);
		for(j=0; j + 1 < V[i].size(); j++)
			printf("%d %d\n",V[i][j],V[i][j+1]);
		if(!V[i].empty())
				printf("%d %d\n",i,V[i][0]);
	}
}
int main()
{
	solve();
	return 0;
}
