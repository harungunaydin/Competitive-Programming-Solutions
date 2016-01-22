#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INF 2000000000
#define MAXN 10000
using namespace std;
vector <int> RES;
vector <int> V[3];
int A[MAXN+5];
void solve()
{
	int N,a,b,c,i,j,k,mini(INF),pre;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		V[A[i]%3].push_back(A[i]);
	}
	k = (V[0].size() > N/2) ? 0 : (V[1].size() < V[2].size()) ? 2 : 1;
	RES.push_back(V[k][0]);
	V[k].erase(V[k].begin());
	pre = k;
	FOR(i,2,N)
	{
		if(!pre)
			k = (V[1].size() <= V[2].size()) ? 2 : 1;
		else if(pre == 1)
			k = (V[0].size() <= V[1].size()) ? 1 : 0;
		else
			k = (V[0].size() <= V[2].size()) ? 2 : 0;
		if(V[k].empty()) { cout << "impossible" << endl; return; }
		RES.push_back(V[k][0]);
		V[k].erase(V[k].begin());
		pre = k;
	}
	vector <int> :: iterator it = RES.begin();
	printf("%d",*(it++));
	for(; it != RES.end(); ++it)
		printf(" %d",*it);
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
