#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int M,N;
int X[MAXN] , Y[MAXN];
char A[3*MAXN];
int find_X(int x)
{
	return upper_bound( X+1,X+N+1 , x ) - X - 1;
}
int find_Y(int y)
{
	return upper_bound( Y+1,Y+N+1 , y ) - Y - 1;
}
void solve()
{
	long long res(0),t1,t2;
	int i;
	N = read(); M = read();
	FOR(i,1,N)
	{
		X[i] = read() , Y[i] = read();
		res += abs( X[i] ) + abs( Y[i] );
	}

	sort( X+1,X+N+1 );
	sort( Y+1,Y+N+1 );

	pii cur(0,0);

	scanf("%s" , A+1 );

	FOR(i,1,M)
	{
		if(A[i] == 'S')
		{
			t1 = find_Y(cur.s);
			t2 = N - t1;
			res += t1 - t2;
			cur.s++;
		}
		else if(A[i] == 'J')
		{
			t1 = find_Y(cur.s-1);
			t2 = N - t1;
			res += t2 - t1;
			cur.s--;
		}
		else if(A[i] == 'I')
		{
			t1 = find_X(cur.f);
			t2 = N - t1;
			res += t1 - t2;
			cur.f++;
		}
		else
		{
			t1 = find_X(cur.f-1);
			t2 = N - t1;
			res += t2 - t1;
			cur.f--;
		}

		printf("%lld\n" , res );

	}

}
int main()
{
	solve();
	return 0;
}
