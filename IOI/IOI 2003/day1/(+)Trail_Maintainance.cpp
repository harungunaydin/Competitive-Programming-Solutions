#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 6005
using namespace std;
class edge
{
	public:
		int a,b,c;
		edge() { a = b = c = 0; }
		void set(int x,int y,int z) { a = x; b = y; c = z; }
}Edges[MAXN];
int M,N,vis;
int ata[205];
int A[205][205];
int atabul(int x)
{
	if(ata[x] == x) return x;
	return ata[x] = atabul(ata[x]);
}
void EKLE(int a,int b,int c)
{
	int i,k;
	FOR(i,1,M)
		if(Edges[i-1].c <= c && c <= Edges[i].c)
			break;
	k = i;
	M++;

	TFOR(i,M,k+1)
		Edges[i] = Edges[i-1];

	Edges[k].set(a,b,c);

}
int MST_Kruskal(int a,int b,int c)
{
	EKLE(a,b,c);

	int i,res(0);

	FOR(i,1,N) ata[i] = i;

	FOR(i,1,M)
		if(atabul( Edges[i].a ) != atabul( Edges[i].b ) )
		{
			ata[ atabul(Edges[i].a) ] = atabul( Edges[i].b );
			res += Edges[i].c;
		}

	int t = atabul(1);
	FOR(i,2,N)
		if(atabul(i) != t)
			return -1;

	return res;
}
void solve()
{
	int W,a,b,c,i,pre,t;
	scanf("%d %d",&N,&W);
	FOR(i,1,W)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(!A[a][b] || !A[a][b] < c)
			A[a][b] = A[b][a] = c;
		printf("%d\n" , MST_Kruskal(a,b,c) );
	}
}
int main()
{
	solve();
	return 0;
}
