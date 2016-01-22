#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define M_Distance(x,y) ( abs( x - cur.f ) + abs( y - cur.s ) )
#define INF 2000000000
#define MAXN 100
using namespace std;
typedef pair < int , int > pii;
pii cur;
pii ROBOT[MAXN*MAXN+5],T[MAXN*MAXN+5];
int M,N,R,vis;
pii K[MAXN*MAXN+5];
int A[MAXN+5][MAXN+5],V[MAXN+5][MAXN+5];
int yon[10][2] = { {0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1} };
bool V2[MAXN*MAXN+5];
void print()
{
	int i,j;
	for(i=1; i<=M; i++,printf("\n"))
		FOR(j,1,N)
			if(A[i][j])
				printf("R");
			else if(cur.f == i && cur.s == j)
				printf("I");
			else
				printf(".");
}
int solve()
{
	string str;
	int i,j,k,k2,mini,t;
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",&c);
			if(c == 'R') { ROBOT[++R] = make_pair(i,j); A[i][j] = R; }
			if(c == 'I') cur = make_pair(i,j);
		}
	cin >> str;
	FOR2(i,str.size())
	{
		vis++;
		cur = make_pair(cur.f + yon[str[i]-'0'][0] , cur.s + yon[str[i]-'0'][1] );
		if(A[cur.f][cur.s]) return i+1;
		FOR(j,1,R)
			if(!V2[j])
			{
				mini = INF;
				FOR(k,1,9)
				{
					t = M_Distance( ROBOT[j].f + yon[k][0] , ROBOT[j].s + yon[k][1] );
					if(t < mini)
					{
						mini = t;
						k2 = k;
					}
				}
				int xx = ROBOT[j].f + yon[k2][0];
				int yy = ROBOT[j].s + yon[k2][1];
				if(V[xx][yy] == vis)
					V[xx][yy] = -vis;
				if(V[xx][yy] != vis && V[xx][yy] != -vis)
					V[xx][yy] = vis;
				ROBOT[j] = make_pair( xx , yy );
				if(xx == cur.f && yy == cur.s) return i+1;
			}
		FOR(j,1,R)
			if(!V2[j] && V[ROBOT[j].f][ROBOT[j].s] == -vis)
				V2[j] = true;
	}
	int s(0);
	FOR(i,1,R)
		if(!V2[i])
			K[++s] = ROBOT[i];
	sort(K+1,K+s+1);
	s = 1;
	for(i=1; i<=M; i++,printf("\n"))
		FOR(j,1,N)
		{
			if(K[s].f == i && K[s].s == j)
			{
				printf("R");
				s++;
			}
			else if(cur.f == i && cur.s == j)
				printf("I");
			else
				printf(".");
		}
	exit(0);
}
int main()
{
	printf("kraj %d\n",solve());
	return 0;
}
