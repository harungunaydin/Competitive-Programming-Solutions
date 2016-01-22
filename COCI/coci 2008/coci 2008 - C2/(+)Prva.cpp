#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 20
using namespace std;
char A[MAXN+5][MAXN+5];
void solve()
{
	string res,str;
	int M,N,i,j,k;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
	{
		str.clear();
		FOR(j,1,N)
		{
			scanf(" %c",A[i]+j);
			if(A[i][j] == '#' || j == N)
			{
				if(j == N && A[i][j] != '#') str+=A[i][j];
				if(res.empty() || (str.size() > 1 && str < res))
					res = str;
				str.clear();
			}
			else
				str+=A[i][j];
		}
	}
	FOR(i,1,N)
	{
		str.clear();
		FOR(j,1,M)
			if(A[j][i] == '#' || j == M)
			{
				if(j == M && A[j][i] != '#') str+=A[j][i];
				if(res.empty() || (str.size() > 1 && str < res))
					res = str;
				str.clear();
			}
			else
				str+=A[j][i];
	}
	cout << res << endl;
}
int main()
{
	solve();
	return 0;
}
