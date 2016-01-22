#include <algorithm>
#include <cstdio>
#include <vector>
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
int N;
vector < int > KIE,KIK,UIE,UIK;
int hallet(vector < int > V1 , vector < int > V2)
{
	sort( all(V1) );
	sort( all(V2) );

	int a(0),b(0),res(0);
	while( a < (int) V1.size() && b < (int) V2.size() )
		if(V1[a] > V2[b]) { a++; b++; res++; }
		else a++;

	return res;
}
void solve()
{
	int a,i;
	N = read();
	FOR(i,1,N)
	{
		a = read();
		if(a > 0) UIE.pb(a);
		else KIE.pb(-a);
	}
	FOR(i,1,N)
	{
		a = read();
		if(a > 0) UIK.pb(a);
		else KIK.pb(-a);
	}

	printf("%d\n" , hallet(KIE,UIK) + hallet(KIK,UIE) );

}
int main()
{
	solve();
	return 0;
}
