#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define x first
#define y second
#define MAXN 20005
using namespace std;
typedef pair < int , int > pii;
class point
{
	public:
		int x,y,ind;
		point() {  }
		void read(int i) { scanf("%d %d",&x,&y); ind = i; }
}P[MAXN];
inline bool cmp( const point &a , const point &b )
{
	return a.x < b.x;
}
int N,T;
int alt[MAXN] , sol_alt[MAXN];
void solve()
{
	int N,i,j,res1(123123123),res2,res3,syc,t;
	scanf("%d %d",&N,&T);
	FOR(i,1,N)
		P[i].read(i);
	sort(P+1,P+N+1,cmp);

	FOR(i,1,N)
	{
		alt[i] = i;
		FOR(j,1,i-1)
			if(P[i].y < P[j].y)
			{
				alt[j]++;
				alt[i]--;
			}
		syc = 0;
		sol_alt[i] = alt[i];
		FOR(j,1,i-1)
		{
			t = sol_alt[i] - alt[j] - syc + sol_alt[j] + 1;
			if(t >= T && t < res1)
			{
				res1 = t;
				res2 = P[j].ind;
				res3 = P[i].ind;
			}

			if(P[j].y < P[i].y) syc++;

		}

		if(syc == T) break;
	}

	printf("%d %d\n" , res2 , res3 );
}
int main()
{
	solve();
	return 0;
}
