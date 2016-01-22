#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define DP(x,y) DP[make_pair(x,y)]
#define f first
#define s second
#define MAXN 300000
using namespace std;
typedef pair < int , int > pii;
map < pair < int , int > , bool> DP;
pii P[MAXN+5],P2[MAXN+5];
int K,N;
int S[MAXN+5];
bool cmp(const pii &a , const pii &b)
{
	if(a.s < b.s) return 1;
	if(a.s > b.s) return 0;
	return a.f < b.f;
}
void read()
{
	int a,b,c,i;
	scanf("%d %d",&N,&K);
	FOR(i,1,N)
	{
		scanf("%d %d %d",&P[i].f,&P[i].s,&c);
		P2[i] = P[i];
	}
	sort(P2+1,P2+N+1);
	sort(P+1,P+N+1,cmp);
}
int solve(int x,int k)
{
	int t = DP(x,k);
	if(t) return t;
	if()
}
int main()
{
	read();
	printf("%d\n",solve(1,S[1]));
	system("PAUSE");
	return 0;
}
