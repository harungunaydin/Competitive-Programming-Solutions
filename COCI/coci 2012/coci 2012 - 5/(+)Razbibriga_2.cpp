#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 350
using namespace std;
int A[MAXN+5][MAXN+5];
void solve()
{
		string str;
		long long res(0),t;
		int N,i,j,k,l;
		bool a,b,c,d;
		scanf("%d",&N);
		FOR(i,1,N)
		{
			cin >> str;
			A[str[0]][str[str.size()-1]]++;
		}
		FOR(i,'A','Z')
			FOR(j,'A','Z')
				FOR(k,'A','Z')
					FOR(l,'A','Z')
					{
						a = b = c = d = false;
						t = 1;
						if(A[i][j]) { a = true; t*=A[i][j]; A[i][j]--; }
						if(A[i][k]) { b = true; t*=A[i][k]; A[i][k]--; }
						if(A[k][l]) { c = true; t*=A[k][l]; A[k][l]--; }
						if(A[j][l]) { d = true; t*=A[j][l]; A[j][l]--; }
						if(a && b && c && d)
							res+=t;
						A[i][j]+=a;
						A[i][k]+=b;
						A[k][l]+=c;
						A[j][l]+=d;
					}
		printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
