#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define H(x1,y1,x2,y2,c) ( T[x2][y2][c] - T[x1-1][y2][c] - T[x2][y1-1][c] + T[x1-1][y1-1][c] )
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define MAXN 505
using namespace std;
typedef pair < int , int > pii;
pii P[MAXN];
int M,N,V;
int T[MAXN][MAXN][27];
char A[MAXN][MAXN];
void solve()
{
	int area(0),c,i,j,k,res(0),s,x,xmax(0),y,ymax(0);
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c" , A[i]+j );
			FOR(k,0,25)
				T[i][j][k] = T[i][j-1][k] + T[i-1][j][k] - T[i-1][j-1][k] + ( A[i][j] == k + 'a' );
		}
	
	scanf("%d",&V);
	FOR(i,1,V)
	{
		scanf("%d %d",&P[i].s,&P[i].f);
		xmax = MAX( xmax , P[i].f );
		ymax = MAX( ymax , P[i].s );
	}

	P[V+1] = P[1];

	FOR(i,1,V) // ICINDEN BIR NOKTA BUL
		if(P[i].f == P[i+1].f && P[i].s < P[i+1].s)
		{
			x = P[i].f + 1; y = P[i].s + 1;
			break;
		}
	FOR(i,1,V)
		if(P[i].f == P[i+1].f)
			area += (P[i].s - P[i+1].s) * P[i].f;

	if(area < 0) area = 0;
	
	FOR(i,0,M-xmax) // SATIRDA KAYDIR
		FOR(j,0,N-ymax) // SUTUNDA KAYDIR
		{
			c = A[x+i][y+j] - 'a';
			s = 0;
			FOR(k,1,V)
				if(P[k].f == P[k+1].f)
				{
					if(P[k].s < P[k+1].s)
						s += H(1 , (P[k].s+1) +j , (P[k].f) +i , (P[k+1].s) +j , c);
					else
						s -= H(1 , (P[k+1].s+1) +j , (P[k].f) +i , (P[k].s) +j , c);
				}
			if(abs(s) == area) res++; // POLIGONUN ICINDEN SECTIGIMIZ HUCRE ILE POLIGONUN ICINDEKI TUM HUCRELER AYNI MI ?
		}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
