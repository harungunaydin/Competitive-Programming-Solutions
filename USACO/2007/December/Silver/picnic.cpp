//SORU 535
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "picnic.in"
#define OUTPUT "picnic.out"
#define MAXN 1000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
vector <int> G[MAXN+5];
int K,M,N,vis;
int A[MAXN+5],visited[MAXN+5];
bool B[MAXN+5][MAXN+5];
void control(int a)
{
	queue <int> Q;
	vector <int> :: iterator it;
	int x; Q.push(a); vis++;
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();
		B[a][x] = true;
		for(it = G[x].begin(); it!=G[x].end(); ++it)
			if(visited[*it] < vis)
			{
				Q.push(*it);
				visited[*it] = vis;
			}
	}
}
void solve()
{
	int a,b,i,j,res=0;
	in >> K >> N >> M;
	FOR(i,1,K)
		in >> A[i];
	FOR(i,1,M)
	{
		in >> a >> b;
		G[a].push_back(b);
	}
	FOR(i,1,N)
		control(i);
	FOR(i,1,N)
	{
		FOR(j,1,K)
			if(!B[A[j]][i])
				break;
		res+=(j==K+1);
	}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
