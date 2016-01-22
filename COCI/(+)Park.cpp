#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
using namespace std;
int N;
long long t;
char A[MAXN+5],B[MAXN+5];
bool visited[MAXN+5];
void dfs(int x)
{
	int k = (!x) ? N-1 : x-1;
	int n = (x+1)%N;
	t+=(B[x] == '1');
	visited[x] = true;
	if(A[n] == '1' && !visited[n]) dfs(n);
	if(A[x] == '1' && !visited[k]) dfs(k);
}
long long solve()
{
	long long res(0);
	int i;
	char c;
	scanf("%d",&N);
	scanf("%s",A);
	scanf("%s",B);
	FOR2(i,N)
		if(A[i] == '0')
			break;
	if(i == N)
	{
		FOR2(i,N)
			t+=(B[i] == '1');
		return t*(t-1) + 1;
	}
	FOR2(i,N)
		if(!visited[i])
		{
			t = 0;
			dfs(i);
			res+=(t*(t-1))/2;
		}
	return res;
}
int main()
{
	printf("%lld\n",solve());
	return 0;
}
