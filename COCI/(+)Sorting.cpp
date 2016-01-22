#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 500000
using namespace std;
vector < int > V;
int N;
int A[MAXN+5],B[MAXN+5];
void solve()
{
	int i,j,k(0),t;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		if(A[i] != i)
		{
			t = (i > A[i]) ? i - A[i] : A[i] - i;
			k++;
			for(j=1; j*j <= t; j++)
				if(!(t%j))
				{
					B[j]++;
					if(j*j != t)
						B[t/j]++;
				}
		}
	}
	FOR(i,1,N)
		if(B[i] == k)
			V.push_back(i);
	printf("%d\n", (int) V.size() );
	FOR2(i,V.size())
		printf("%d%c",V[i],(i != V.size() - 1) ? ' ' : '\n');
}
int main()
{
	solve();
	return 0;
}
