#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define x first
#define y second
#define MAXN 500
#define DIK(x1,y1,x2,y2,c) ( T[(x2)][(y2)][(c)] - T[(x2)][(y1)][(c)] - T[(x1)][(y2)][(c)] + T[(x1)][(y1)][(c)] )
using namespace std;
typedef pair <int,int> pii;
pii P[MAXN+5];
pii p;
int K,M,N,area,alt,sag;
int hash[MAXN+5];
int T[MAXN+5][MAXN+5][30];
char A[MAXN+5][MAXN+5];
void initialize()
{
	int i,j;
	char c;
	FOR(i,1,M)
		FOR(j,1,N)
			FOR(c,0,26)
				T[i][j][c] = T[i][j-1][c] + T[i-1][j][c] - T[i-1][j-1][c] + (A[i][j] == c);
}
inline int sum(int x1,int y1,int x2,int y2)
{
	int res(0);
	char c;
	FOR(c,0,26)
		res+=DIK(x1,y1,x2,y2,c);
	return res;
}
void read()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",A[i]+j);
			A[i][j]-='a';
		}
	scanf("%d",&K);
	FOR(i,1,K)
	{
		scanf("%d %d",&P[i].y,&P[i].x);
		sag>?=P[i].y;
		alt>?=P[i].x;
	}
	P[i] = P[1];
}
int calculate_area()
{
	int i,res(0);
	FOR(i,1,K)
		if(P[i].x == P[i+1].x)
			if(P[i].y < P[i+1].y)
				res+=sum(0,P[i].y,P[i+1].x,P[i+1].y);
			else
				res-=sum(0,P[i+1].y,P[i].x,P[i].y);
	return abs(res);
}
bool hesapla(int a,int b)
{
	int i,sum(0);
	char c = A[p.x+a][p.y+b];
	FOR(i,1,K+1)
		P[i] = make_pair(P[i].x+a,P[i].y+b);
	FOR(i,1,K)
		if(P[i].x == P[i+1].x)
			if(P[i].y < P[i+1].y)
				sum+=DIK(0,P[i].y,P[i+1].x,P[i+1].y,c);
			else
				sum-=DIK(0,P[i+1].y,P[i].x,P[i].y,c);
	FOR(i,1,K+1)
		P[i] = make_pair(P[i].x-a,P[i].y-b);
	return abs(sum) == area;
}
void solve()
{
	int i,j,res(0);
	FOR(i,1,K)
		if(P[i].y == sag)
			hash[P[i].x] = i;
	for(i=alt; i>=1 && !p.x; i--)
		if(hash[i])
			p = make_pair(i,sag);
	FOR(i,0,M-alt)
		FOR(j,0,N-sag)
			res+=hesapla(i,j);
	printf("%d\n",res);
}
int main()
{
	read();
	initialize();
	area = calculate_area();
	solve();
	return 0;
}
