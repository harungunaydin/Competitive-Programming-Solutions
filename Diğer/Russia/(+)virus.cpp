#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 100005
using namespace std;
vector < int > G[MAXN],G2[MAXN];
long long res(0);
long long BIT[MAXN];
int N,dis;
int F[MAXN],S[MAXN];
void rec(int x)
{
	S[x] = ++dis;
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		rec(*it);
	F[x] = dis;
}
void update(int a,int b,int k)
{
	int i;
	for(i = a; i < MAXN; i += i&-i) BIT[i] += k;
	for(i = b + 1; i < MAXN; i += i&-i) BIT[i] -= k;
}
long long find(int i)
{
	long long sum(0);
	for(; i ; i -= i&-i) sum += BIT[i];
	return sum;
}
void rec2(int x)
{
	res += find(S[x]);
	update(S[x],F[x] , 1);
	vector < int > :: iterator it;
	for(it = G2[x].begin(); it != G2[x].end(); ++it)
		rec2(*it);
	update(S[x],F[x] ,-1);
}
void solve()
{
	int a,i,root1,root2;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		if(!a) root1 = i;
		G[a].push_back(i);
	}
	FOR(i,1,N)
	{
		scanf("%d",&a);
		if(!a) root2 = i;
		G2[a].push_back(i);
	}

	rec(root1);

	rec2(root2);

	printf("%lld\n" , res );

}
int main()
{
	freopen("fayans.gir","r",stdin);
	freopen("fayans.cik","w",stdout);
	solve();
	return 0;
}
