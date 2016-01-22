#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 50
using namespace std;
typedef pair < int , char > pic;
int read()
{
	int res(0),sign(1);
	char c;
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') { res = c - '0'; break; }
		else if(c == '-') { sign = -1; break; }
	}
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') res = res*10 + c - '0';
		else break;
	}
	return res * sign;
}
pic P[105];
string solve()
{
	string res;
	int M,N,i;
	N = read(); M = read();
	FOR(i,1,M)
		scanf("%d %c" , &P[i].f , &P[i].s );

	res.resize(N,0);
	int k(0);

	TFOR(i,M,1)
	{
		if(res[k] && res[k] != P[i].s) return "!";
		res[k] = P[i].s;
		k = ( k + P[i].f ) % N;
	}

	FOR2(i,N)
		if(!res[i])
			res[i] = '?';

	return res;

}
int main()
{
	cout << solve() << endl;
	return 0;
}
