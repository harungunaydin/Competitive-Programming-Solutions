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
string str[MAXN];
int N;
void solve()
{
	int i,k;
	N = read();
	FOR(i,1,N)
		cin >> str[i];

	k = 1;
	while(str[k] != "BLJTV1") { printf("1"); k++; }
	while(k > 1) { swap( str[k],str[k-1] ); printf("4"); k--; }
	while(str[k] != "BLJTV2") { printf("1"); k++; }
	while(k > 2) { printf("4"); k--; }

}
int main()
{
	solve();
	return 0;
}
