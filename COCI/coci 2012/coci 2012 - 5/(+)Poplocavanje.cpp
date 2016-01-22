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
#define BASE 1009
#define MAXK 5005
#define MAXN 300005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int M,N;
int H[MAXN] , T[MAXN] , us[MAXN];
char A[MAXN] , B[MAXK];
void solve()
{
	int i,h,t;
	N = read();
	scanf("%s" , A+1 );
	us[0] = 1;
	FOR(i,1,N)
	{
		H[i] = H[i-1] * BASE + A[i];
		us[i] = us[i-1] * BASE;
	}
	M = read();
	while(M--)
	{
		scanf("%s" , B );

		h = 0;

		for(i = 0; B[i]; i++)
			h = h * BASE + B[i];

		t = i;

		FOR(i,1,N-t+1)
			if( H[i+t-1] - H[i-1] * us[t] == h)
			{
				T[i]++;
				T[i+t]--;
			}
	}

	int res(0);

	FOR(i,1,N)
		if(T[i] += T[i-1])
			res++;

	printf("%d\n" , N - res );

}
int main()
{
	solve();
	return 0;
}
