#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 500
using namespace std;
typedef pair < double , string > pds;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
map < string , int > mp;
pds P[500];
bool cmp( const pds &a , const pds &b )
{
	if( a.f > b.f ) return true;
	if( a.f < b.f ) return false;
	return true;
}
void solve()
{
	string str;
	int K(0),N,X,a,i,j;
	X = read();
	N = read();

	FOR(i,1,N)
	{
		cin >> str >> a;
		if(20*a >= X)
		{
			mp[str] = 0;
			FOR(j,1,14)
				P[++K] = make_pair( (double)a/j , str );
		}
	}

	sort( P+1,P+K+1 , cmp );

	FOR(i,1,14)
		mp[ P[i].s ]--;


	map < string , int > :: iterator it;

	for(it = mp.begin(); it != mp.end(); ++it)
		cout << it->f << " " << -it->s << endl;



}
int main()
{
	solve();
	return 0;
}
