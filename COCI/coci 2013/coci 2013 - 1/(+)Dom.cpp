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
#define MAXN 
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
void solve()
{
	string str;
	cin >> str;
	for(int i = 0; i < (int) str.size(); i++)
		if(str[i] != 'C' && str[i] != 'A' && str[i] != 'M')
			if(str[i] != 'B' && str[i] != 'R' && str[i] != 'I')
				if(str[i] != 'D' && str[i] != 'G' && str[i] != 'E')
					printf("%c" , str[i] );
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
