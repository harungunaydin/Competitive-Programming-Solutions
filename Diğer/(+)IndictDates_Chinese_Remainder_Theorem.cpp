#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 5
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int C(1),N;
int A[MAXN] , B[MAXN] , R[MAXN] , T[MAXN];
void Ex_gcd(int a,int b,int &x,int &y)
{
	if(!b) { x = 1; y = 0; return; }
	int x1,y1;
	Ex_gcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - (a/b) * y1;
}
void solve()
{
	int i,res(0),x,y;
	N = 3;
	FOR(i,1,N) A[i] = read() - 1;
	B[1] = 15; B[2] = 28; B[3] = 19;

	FOR(i,1,N) C *= B[i];

	FOR(i,1,N) T[i] = C / B[i];

	FOR(i,1,N)
	{
		x = 123;
		Ex_gcd(T[i],B[i],x,y);
		R[i] = ( x + B[i] ) % B[i];
	}

	FOR(i,1,N)
		res += A[i] * R[i] * T[i];

	printf("%d\n" , res % C + 1 );

}
int main()
{
	solve();
	return 0;
}
