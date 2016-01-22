#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define finish first
#define start second
#define MAXN 500000
using namespace std;
vector < int > V[MAXN+5];
pair <int,int> A[MAXN+5];
int M,N,t(1);
int F[MAXN+5],X[MAXN+5];
void dfs(int x)
{
	A[x].start = t++;
	vector <int> :: iterator it;
	for(it = V[x].begin(); it!=V[x].end(); ++it)
		dfs(*it);
	A[x].finish = t;
}
void add(int i,int x)
{
	for(; i<=MAXN+5; i+=(i&-i))
		F[i]+=x;
}
int hesapla(int i)
{
	int res(0);
	for(; i ; i-=(i&-i))
		res+=F[i];
	return res;
}
void solve()
{
	int a,i,x;
	char c;
	scanf("%d %d",&N,&M);
	scanf("%d",X+1);
	FOR(i,2,N)
	{
		scanf("%d %d",X+i,&a);
		V[a].push_back(i);
	}
	dfs(1);
	FOR(i,1,M)
	{
		scanf(" %c %d",&c,&a);
		if(c == 'u') printf("%d\n",hesapla(A[a].start) + X[a]);
		else
		{
			scanf("%d",&x);
			add(A[a].start+1,x);
			add(A[a].finish,-x);
		}
	}
}
int main()
{
	solve();
	return 0;
}
