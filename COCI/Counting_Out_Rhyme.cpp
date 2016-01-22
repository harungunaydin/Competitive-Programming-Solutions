#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 20
using namespace std;
int N,h;
int A[MAXN+5],hash[MAXN+5];
bool kontrol(int M)
{
	int i,s(0),t(0);
	bool f = false;
	h++;
	FOR(i,1,N)
	{
		s+=(hash[i] < h);
		if(s == M || (hash[i] < h && f))
		{
			hash[i] = h;
			s = 0;
			if(A[++t] != i)
				return 0;
			if(t == N-1) f = true;
			if(t == N) break;
		}
		if(i == N) i = 0;
	}
	return 1;
}
void solve()
{
	int a,i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		A[a] = i;
	}
	i = 0;
	FOR(i,1,1000)
		if(kontrol(i))
		{
			printf("%d\n",i);
			return;
		}
	printf("NIE\n");
}
int main()
{
	solve();
	return 0;
}
