#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
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
int N,R,S,res(20);
int A[15] , B[15] , C[15];
bool H[15] , H2[15];
void control()
{
	int i,s(0);

	memset( H2 , 0 , sizeof H2 );

	FOR(i,1,S)
		H2[ A[i] ] = true;

	FOR(i,1,R)
		if(C[i] == 1)
			H2[ B[i] ] = false;
		else if(C[i] == 2)
			H2[ B[i]-1 ] = false;
		else if(C[i] == 3)
			H2[ B[i]+1 ] = false;

	FOR(i,1,N)
		s += H2[i];

	res = min( res , s );

}
void rec(int x)
{
	if(x == R + 1) { control(); return; }

	if(H[ B[x] ]) { C[x] = 1; rec(x+1); return; }

	C[x] = 2;

	rec(x+1);

	C[x] = 3;

}
void solve()
{
	int i;
	N = read(); S = read(); R = read();
	FOR(i,1,S)
	{
		A[i] = read();
		H[ A[i] ] = true;
	}

	FOR(i,1,R)
		B[i] = read();

	rec(1);

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
