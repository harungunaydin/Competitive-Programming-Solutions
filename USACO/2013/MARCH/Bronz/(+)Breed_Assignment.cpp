#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 100
using namespace std;
typedef pair < int , int > pii;
vector < pii > V[MAXN];
int K,N;
int A[MAXN];
bool control(int x)
{
	vector < pii > :: iterator it;
	for(it = V[x].begin(); it != V[x].end(); ++it)
		if((!(it->s) && A[x] == A[it->f]) || (it->s && A[x] != A[it->f]))
			return 0;
	return 1;
}
int rec(int x)
{
	if(x == N + 1) return 1;
	int i,res(0);
	FOR(i,1,3)
	{
		A[x] = i;
		if(control(x))
			res += rec(x+1);
	}
	return res;
}
void solve()
{
	int i,x,y;
	char c;
	scanf("%d %d",&N,&K);
	FOR(i,1,K)
	{
		scanf(" %c %d %d",&c,&x,&y);
		if(x > y) swap(x,y);
		V[y].push_back(make_pair(x,(c == 'S')));
	}
	printf("%d\n" , rec(1) );
}
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	solve();
	return 0;
}
