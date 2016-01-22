#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 50
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
char A[MAXN] , B[MAXN];
void solve()
{
	int a,b,i,j;
	scanf("%s %s" , A + 1 , B + 1 );
	int M = strlen(A+1);
	int N = strlen(B+1);
	FOR(a,1,M)
		FOR(b,1,N)
			if(A[a] == B[b])
			{
				FOR(i,1,N)
				{
					FOR(j,1,M)
						if(i == b)
							printf("%c" , A[j]);
						else if(j == a)
							printf("%c" , B[i] );
						else
							printf(".");
					printf("\n");
				}
					return;
			}
}
int main()
{
	solve();
	return 0;
}
