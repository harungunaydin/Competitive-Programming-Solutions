#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 1500
using namespace std;
typedef pair < short , short > pss;
typedef pair < int , pss > piss;
typedef pair < int , int > pii;
piss A[MAXN*MAXN+5];
pss B[MAXN*MAXN+5];
int Bx,By,N,nkare;
bool cmp( const pii &a , const pii &b ) { return a.f > b.f; }
class skakavac
{
	public:
		pii M[4];
		skakavac() { M[0] = M[1] = M[2] = M[3] = make_pair(0,2000); }
		inline void update(int x,int s)
		{
			if(s < M[3].f) return;
			M[3] = make_pair(s,x);
			sort(M,M+4,cmp);
		}
		inline int al(int x)
		{
			int i;
			FOR2(i,4)
				if( (int) abs ( M[i].s - x ) > 1)
					return M[i].f;
		}
}GSAT[MAXN+5],GSUT[MAXN+5],SAT[MAXN+5],SUT[MAXN+5];
void solve()
{
	int a,b,i,j,k,s,x,y;
	scanf("%d",&N);
	scanf("%d %d",&Bx,&By);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf("%d",&A[++nkare].f);
			A[nkare].s = make_pair( i , j );
		}
	sort(A+1,A+nkare+1);
	TFOR(i,nkare,1)
	{
		k = i;
		s = 0;
		while(A[i].f == A[k].f && i > 0)
		{
			x = A[i].s.f; y = A[i].s.s;
			a = SAT[x-1].al(y);
			a = max( a , SAT[x+1].al(y) );
			a = max( a , SUT[y-1].al(x) );
			a = max( a , SUT[y+1].al(x) );
			GSAT[x].update( y , a + 1);
			GSUT[y].update( x , a + 1);
			B[++s] = make_pair( x , y );
			if(x == Bx && y == By) { printf("%d\n",a + 1 ); return; }
			i--;
		}
		i++;
		FOR(j,1,s) { SAT[B[j].f] = GSAT[B[j].f]; SUT[B[j].s] = GSUT[B[j].s]; }
	}
}
int main()
{
	solve();
	return 0;
}
