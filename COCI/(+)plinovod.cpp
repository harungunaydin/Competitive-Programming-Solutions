#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1
using namespace std;
int M,N;
char A[10005][505];
int flow(int x,int y)
{
	if(x < 1 || x > M) return 0;
	if(y == N + 1) 			return 1;
	if(A[x][y] == 'x')  return 0;
	A[x][y] = 'x';
	if(flow(x-1 , y+1))  return 1;
	if(flow(x ,   y+1))    return 1;
	if(flow(x+1 , y+1))  return 1;
	return 0;
}
void solve()
{
	int i,j,res(0);
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		scanf(" %s",A[i]);
	FOR(i,1,M)
		res+=flow(i,1);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
