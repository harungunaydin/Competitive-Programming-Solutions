#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cstdlib>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define EKLE(x,y,s) pq.push(make_pair(s,make_pair(-(x),-(y))))
#define BAK(x,y,s)  { x = - pq.top().s.f; y = - pq.top().s.s; s = pq.top().f; pq.pop(); }
#define F(a,b) ( a != b && a != -1 && b != -1 )
#define G(a,b) ( a == b && a != -1 && b != -1 )
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
map < int , int > mp;
priority_queue < pair < int , pii > > pq;
int Max( int a , int b ) { return a > b ? a : b; }
int Min( int a , int b ) { return a < b ? a : b; }

int M,N;
int A[MAXN][MAXN] , DP[MAXN][MAXN];

void ayar_cek(int x1,int y1,int x2,int y2)
{
	x1 = Max(x1,1);
	y1 = Max(y1,1);
	x2 = Min(x2,M);
	y2 = Min(y2,N);

	int i,j;
	
	FOR(i,x1,x2)
		FOR(j,y1,y2)
		{
			if(F(A[i][j],A[i-1][j]) && F(A[i][j],A[i][j-1]) && G(A[i][j],A[i-1][j-1]))
			{
				DP[i][j] = 1 + Min( DP[i-1][j-1] , Min( DP[i-1][j] , DP[i][j-1] ) );
				EKLE(i,j,DP[i][j]);
			}
			else DP[i][j] = 1;
		}
}
void girdiyi_al()
{
	int a,i,j,s;
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N/4)
		{
			scanf(" %c",&c);
			a = ( c >= 'A' ) ? c - 'A' + 10 : c - '0';
			s = 4;
			while(a)
			{
				A[i][4*(j-1)+(s--)] = a&1;
				a >>= 1;
			}
		}
}
void solve()
{
	int i,j,s,t(0),x,y;
	
	girdiyi_al();
	
	FOR(i,1,M) DP[i][1] = 1;
	FOR(i,1,N) DP[1][i] = 1;

	ayar_cek(2,2,M,N);

	mp.clear();

	while(!pq.empty())
	{
		BAK(x,y,s);
		if(DP[x][y] != s) continue;
		mp[s]++;
		t += s * s;
		FOR(i,x-s+1,x)
			FOR(j,y-s+1,y)
				A[i][j] = -1;

		ayar_cek(x-s+1,y-s+1,x+s,y+s);
	}
	map < int , int > :: reverse_iterator it;
	if(t != M * N)
		mp[1] = M * N - t;
	printf("%d\n" , (int) mp.size());
	for(it = mp.rbegin(); it != mp.rend(); ++it)
		printf("%d %d\n" , it->f , it->s );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		memset( A , 0 , sizeof A );
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
