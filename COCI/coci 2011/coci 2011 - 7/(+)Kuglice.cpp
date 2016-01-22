#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 300005
using namespace std;
typedef pair < int , int > pii;
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
pii q[MAXN];
int N,Q,vis;
int A[MAXN] , RES[MAXN] , ata[MAXN];
int atabul(int x,int s)
{
	if(s > N) return ata[x] = -1;
	if(ata[x] == x || ata[x] == -1) return ata[x];
	return ata[x] = atabul(ata[x],s+1);
}
void solve()
{
	int i;
	N = read();
	FOR(i,1,N)
	{
		scanf("%d" , A+i );
		if(!A[i]) A[i] = i;
		ata[i] = A[i];
	}

	scanf("%d",&Q);
	FOR(i,1,Q)
	{
		q[i].f = read() , q[i].s = read();
		if(q[i].f == 2) ata[ q[i].s ] = q[i].s;
	}

	TFOR(i,Q,1)
	{
		vis++;
		if(q[i].f == 1)
			RES[i] = atabul( q[i].s , 0 );
		else
		{
			if( atabul( A[ q[i].s ] , 0 ) == q[i].s )
			{
				int x = A[ q[i].s ];
				while(x != q[i].s && ata[x] != -1)
				{
					ata[x] = -1;
					x = A[x];
				}
				ata[ q[i].s ] = -1;
			}
			else ata[ q[i].s ] = atabul( A[ q[i].s ] , 0 );
		}
	}

	FOR(i,1,Q)
		if(q[i].f == 1)
		{
			if(RES[i] == -1) printf("CIKLUS\n");
			else printf("%d\n" , RES[i] );
		}

}
int main()
{
	solve();
	return 0;
}
