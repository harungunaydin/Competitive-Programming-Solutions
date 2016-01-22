#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int M,N;
int A[MAXN] , RES[10] ;
void solve()
{
	string tmp;
	int i,j,k;
	char c;
	M = read(); N = read();
	FOR2(i,M)
	{
		cin >> tmp;
		FOR2(k,4)
		{
			scanf(" %c" , &c);
			FOR2(j,N)
			{
				tmp = "";
				scanf(" %c" , &c ); tmp += c;
				scanf(" %c" , &c ); tmp += c;
				scanf(" %c" , &c ); tmp += c;
				scanf(" %c" , &c ); tmp += c;
				scanf(" %c" , &c );
				if(tmp == "****") A[j]++;
			}
		}
		FOR2(j,N) RES[ A[j] ]++;
		FOR2(j,N) A[j] = 0;
	}

	FOR2(i,5)
		printf("%d " , RES[i] );

}
int main()
{
	solve();
	return 0;
}
