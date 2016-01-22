#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 500005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
vector < int > V[MAXN];
int M,N,dis;
int A[MAXN] , F[MAXN] , S[MAXN];
int FW[MAXN];
void update(int a,int b,int x)
{
	int i;
	for(i = a; i < MAXN; i += i&-i) FW[i] += x;
	for(i = b + 1; i < MAXN; i += i&-i) FW[i] -= x;
}
int find(int i)
{
	int res(0);
	for(; i; i -= i&-i) res += FW[i];
	return res;
}
void init_dfs(int x)
{
	S[x] = ++dis;
	update(dis,dis,A[x]);
	vector < int > :: iterator it;
	for(it = V[x].begin(); it != V[x].end(); ++it)
		init_dfs(*it);
	F[x] = dis;
}
void solve()
{
	int a,b,i;
	char c;
	N = read(); M = read();

	A[1] = read();

	FOR(i,2,N)
	{
		A[i] = read();
		V[read()].push_back(i);
	}

	init_dfs(1);

	FOR(i,1,M)
	{
		scanf(" %c" , &c );
		a = read();
		if(c == 'p')
		{
			b = read();
			update(S[a]+1,F[a],b);
		}
		else
			printf("%d\n" , find(S[a]) );
	}
}
int main()
{
	solve();
	return 0;
}
