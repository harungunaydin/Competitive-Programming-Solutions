#include <iostream>
#include <fstream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 500000
using namespace std;
vector < int > V;
int N;
int A[MAXN+5],B[MAXN+5];
bool is_sorted()
{
	int i;
	FOR(i,1,N-1)
		if(B[i] > B[i+1])
			return 0;
	return 1;
}
void solve()
{
	int X,i,gap,ok;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	V.push_back(1);
	FOR(X,2,N)
	{
		gap = X;
		FOR(i,1,N)
			B[i] = A[i];
		do
		{
			ok = 1;
			FOR(i,1,N-gap)
				if(B[i] > B[i+gap])
				{
					swap(B[i],B[i+gap]);
					ok = 0;
				}
		}while(!ok);
		if(is_sorted())
			V.push_back(X);
	}
	printf("%d\n",V.size());
	FOR2(i,V.size()) printf("%d%c",V[i],(i != V.size() - 1) ? ' ' : '\n');
}
int main()
{
	solve();
	return 0;
}
