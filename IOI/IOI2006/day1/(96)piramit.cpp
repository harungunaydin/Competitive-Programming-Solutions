#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define H(x1,y1,x2,y2) ( T[x2][y2] - T[x1-1][y2] - T[x2][y1-1] + T[x1-1][y1-1] )
#define MAXN 1002
using namespace std;
typedef pair < int , short > pis;
typedef pair < int , int > pii;
typedef pair < pii , int > pii3;
inline int Min( int a , int b ) { return a < b ? a : b; }
set < pii3 > st;
pis ST[MAXN][2050];
int A,B,C,D,M,N , BAS,SON;
int K[MAXN][MAXN] , T[MAXN][MAXN];
pii init(int pos,int s,int e,int x)
{
	if(s == e) return ST[x][pos] = make_pair( H(x,s,x+C-1,s+D-1) , s );
	int m = ( s + e ) >> 1;
	pii p1 = init(pos<<1,s,m,x);
	pii p2 = init((pos<<1)+1,m+1,e,x);
	return ST[x][pos] = (p1.f < p2.f) ? p1 : p2;
}
pii find(int pos,int s,int e,int a,int b,int x)
{
	if(a > e || b < s) return make_pair(20000000,0);
	if(a <= s && e <= b) return ST[x][pos];
	int m = ( s + e ) >> 1;
	pii p1 = find(pos<<1,s,m,a,b,x);
	pii p2 = find((pos<<1)+1,m+1,e,a,b,x);
	return (p1.f < p2.f) ? p1 : p2;
}
void read_and_init()
{
	int i,j;
	scanf("%d %d %d %d %d %d",&N,&M,&B,&A,&D,&C);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf("%d",K[i]+j);
			T[i][j] = T[i][j-1] + T[i-1][j] - T[i-1][j-1] + K[i][j];
		}
	BAS = 2; SON = N - C;
	FOR(i,2,M-C)
		init(1,BAS,SON,i);
}
void solve()
{
	read_and_init();
	int i,j,k, x1,x2,y1,y2, xx1,xx2,yy1,yy2, t , res(0);
	int resx1,resx2,resy1,resy2;
	FOR(j,1,N-B+1)
		FOR(i,1,M-A+1)
		{
			x1 = i; y1 = j;
			x2 = i + A - 1; y2 = j + B - 1;

			xx1 = x1 + 1; yy1 = y1 + 1;
			xx2 = x2 - C; yy2 = y2 - D;

			if(i == 1)
			{
				st.clear();
				FOR(k,xx1,xx2)
					st.insert( make_pair( find(1,BAS,SON,yy1,yy2,k) , k ) );
			}

			pii3 p = *st.begin();
			t = H(x1,y1,x2,y2) - p.f.f;

			if(t > res)
			{
				resx1 = x1; resy1 = y1;
				resx2 = p.s; resy2 = p.f.s;
				res = t;
			}
			st.erase( st.find( make_pair( find(1,BAS,SON,yy1,yy2,xx1) , xx1 ) ) );
			st.insert( make_pair( find(1,BAS,SON,yy1,yy2,xx2+1) , xx2 + 1) );

			xx1++; xx2++;

		}
	printf("%d %d\n" , resy1 , resx1 );
	printf("%d %d\n\n\n" , resy2 , resx2 );
}
int main()
{
	solve();
	return 0;
}
