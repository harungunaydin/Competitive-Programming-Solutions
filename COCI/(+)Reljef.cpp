#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define EKLE(x,y) { qx.push(x); qy.push(y); visited[x][y] = vis; }
#define BAK(x,y)  { x = qx.front(); y = qy.front(); qx.pop(); qy.pop(); }
#define MAXN 100
using namespace std;
typedef pair < int , int > pii;
vector < pii > V;
int K,M,N,vis;
int visited[MAXN+5][MAXN+5],yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN+5][MAXN+5];
bool BFS(int x,int y)
{
	queue < int > qx,qy;
	int i,xx,yy;
	bool flag = false;
	EKLE(x,y);
	while(!qx.empty())
	{
		BAK(x,y);
		V.push_back(make_pair(x,y));
		if(x == M - 1) flag = true;
		FOR2(i,4)
		{
			xx = x + yon[i][0]; yy = y + yon[i][1];
			if(A[xx][yy] == 'x' && visited[xx][yy] < vis)
				EKLE(xx,yy);
		}
	}
	return flag;
}
void hallet()
{
	sort(all(V));
	reverse(all(V));
	vector < pii > :: iterator it;
	for(it = V.begin(); it != V.end(); ++it)
		A[it->f][it->s] = '.';
	while(1)
	{
		for(it = V.begin(); it != V.end(); ++it)
			if(it->f == M-1 || A[it->f+1][it->s] == 'x')
				break;
		if(it != V.end()) break;
		for(it = V.begin(); it != V.end(); ++it)
			it->f++;
	}
	for(it = V.begin(); it != V.end(); ++it)
		A[it->f][it->s] = 'x';
}
void solve(int a,bool k)
{
	int i,j;
	FOR2(i,N)
		if(A[M-a][k ? i : N-i-1] == 'x')
			break;
	if(i == N) return;
	i = k ? i : N-i-1;
	A[M-a][i] = '.';
	vis++;
	FOR2(i,M)
		FOR2(j,N)
			if(visited[i][j] < vis && A[i][j] == 'x')
			{
				V.clear();
				int t = BFS(i,j);
				if(!t)
				{
					hallet();
					return;
				}
			}
}
int main()
{
	int a,i,j;
	scanf("%d %d",&M,&N);
	FOR2(i,M)
		scanf("%s",A[i]);
	scanf("%d",&K);
	FOR(i,1,K)
	{
		scanf("%d",&a);
		solve(a,i&1);
	}
	FOR2(i,M)
		FOR2(j,N+1)
			printf("%c",(j != N) ? A[i][j] : '\n');
	return 0;
}
