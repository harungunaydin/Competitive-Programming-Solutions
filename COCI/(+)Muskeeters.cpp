#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 200
using namespace std;
int DP[MAXN+5][MAXN+5][MAXN+5];
int N;
int A[MAXN+5][MAXN+5],B[MAXN+5][MAXN+5];
bool hash[MAXN+5][MAXN+5][MAXN+5];
void solve()
{
	int bas,a,b,i,j,k,l,son,t;
	char c;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf(" %c", &c );
			A[i][j] = A[i][j+N] = A[i+N][j] = A[i+N][j+N] = c - '0';
		}
	int m = N;
	N<<=1;
	FOR(i,1,N) DP[i][i][++B[i][i]] = i;
	FOR(k,1,m)
		FOR(i,1,N-k)
		{
			bas = i; son = i + k;
			FOR(j,bas,son-1)
				FOR(a,1,B[bas][j])
					FOR(b,1,B[j+1][son])
					{
						t = DP[bas][j][a];
						l = DP[j+1][son][b];
						if(A[t][l] && !hash[bas][son][t]) { hash[bas][son][t] = true; DP[bas][son][++B[bas][son]] = t; }
						if(A[l][t] && !hash[bas][son][l]) { hash[bas][son][l] = true; DP[bas][son][++B[bas][son]] = l; }
					}
		}
	set < int > st;
	FOR(i,1,m)
		FOR(j,1,B[i][i+m-1])
		{
			t = DP[i][i+m-1][j];
			st.insert(t > m ? t - m : t);
		}
	set < int > :: iterator it;
	printf("%d\n", (int) st.size() );
	for(it = st.begin(); it != st.end(); ++it)
		printf("%d\n",*it);
}
int main()
{
	solve();
	return 0;
}
