#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 10000005
using namespace std;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int N;
int prime[700000];
bool ASAL[MAXN];
void asallari_Bul()
{
	int i,j;
	for(i = 2; i <= 10000000; i++)
		if(!ASAL[i])
			for(j = i+i; j <= 10000000; j += i)
				ASAL[j] = true;
	FOR(i,2,10000000)
		if(!ASAL[i])
			prime[++N] = i;
}
void solve()
{
	asallari_Bul();

	int a,i;

	while( scanf("%d" , &a ) != -1 )
	{
		if(a < 8) { printf("Impossible.\n"); continue; }
		else if(a&1) { printf("2 3 "); a -= 5; }
		else { printf("2 2 "); a -= 4; }

		FOR(i,1,N)
			if(!ASAL[ a - prime[i] ])
			{
				printf("%d %d\n" , prime[i] , a - prime[i] );
				break;
			}

	}
}
int main()
{
	solve();
	return 0;
}
