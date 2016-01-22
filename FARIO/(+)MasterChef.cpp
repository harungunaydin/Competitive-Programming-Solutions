#include <iostream>
#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 200001
using namespace std;
typedef pair < int , int > pii;
double T[MAXN];
void solve()
{
	double res(0),t(0);
	int N,bas,son,i,j;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%lf",T+i);
		T[i] += T[i-1];
	}
	bas = 1; son = N;
	FOR(i,1,N)
	{
		t += T[son] - T[bas-1];
		res += t / i;
		bas++; son--;
	}
	res *= 2;
	res /= N;
	res /= (N+1);
	printf("%d\n" , (int) res );
}
int main()
{
	solve();
	return 0;
}
