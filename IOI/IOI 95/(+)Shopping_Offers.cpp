#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 10000
using namespace std;
typedef pair <int,int> pii;
vector <pii> V[MAXN+5];
int A[MAXN+5],B[MAXN+5],C[MAXN+5],value[MAXN+5];
int DP[MAXN+5][123];
void solve()
{
	int K,S,a,b,c,i,j,s;
	scanf("%d",&S);
	FOR(i,1,S)
	{
		scanf("%d",&s);
		FOR(j,1,s)
		{
			scanf("%d %d",&a,&b);
			V[i].push_back(make_pair(a,b));
		}
		scanf("%d",C+i);
	}
	scanf("%d",&K);
	scanf("%d %d %d",A+1,B+1,&c);
	DP[c][0] = true;
	DP[c][A[1]] = 1;
	FOR(i,1,K-1)
	{
		scanf("%d %d %d",A+i,B+i,&c);
		FOR(i,1,1000)
			if(DP[i][0])
			{
				DP[i+c][0] = true;
				DP[i+c][]
			}
	}
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
