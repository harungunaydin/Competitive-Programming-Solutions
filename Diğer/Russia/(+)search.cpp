#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 105
using namespace std;
vector < int > V[MAXN][125];
int M,N;
short C[MAXN][200005];
void solve()
{
	int bas(0),i,j,s,t;
	char c;
	char S[50005];

	scanf("%d %d",&N,&M);
	FOR(i,1,N)
	{
		scanf("%s",S+1);
		t = strlen(S+1);
		FOR(j,1,t)
			V[i][S[j]].push_back(j);
	}

	vector < int > :: iterator it;

	FOR(i,1,M)
	{
		scanf(" %c" , &c );
		s = 0;
		if(c == '-')
		{
			bas--;
			FOR(j,1,N) s += (C[j][bas] != -1);
			printf("%d\n" , s );
		}
		else
		{
			FOR(j,1,N)
			{
				if(C[j][bas] == -1) { C[j][bas+1] = -1; continue; }
				it = upper_bound( V[j][c].begin() , V[j][c].end() , C[j][bas] );
				if(it != V[j][c].end())
				{
					s++;
					C[j][bas+1] = *it;
				}
				else
					C[j][bas+1] = -1;
			}
			bas++;
			printf("%d\n" , s );
		}
	}
}
int main()
{
	solve();
	return 0;
}
