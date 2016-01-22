#include <iostream>
#include <queue>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 2000000000
#define MAXN 50
#define EKLE(x,y) { qx.push(x); qy.push(y); visited[x][y] = vis; }
#define BAK(x,y)  { x = qx.front(); y = qy.front(); qx.pop(); qy.pop(); }
#define KONTROL(x,y) (A[x][y] && visited[x][y] < vis && Min <= B[x][y] && B[x][y] <= Max)
using namespace std;
queue <int> qx,qy;
set <int> st;
int MINI,N,Px,Py,S,vis;
int B[MAXN+5][MAXN+5],visited[MAXN+5][MAXN+5];
int yon[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
char A[MAXN+5][MAXN+5];
bool kontrol(int Min,int Max)
{
	if(B[Px][Py] < Min || Max < B[Px][Py]) return 0;
	int k,s(0),x,y;
	vis++;
	EKLE(Px,Py);
	while(!qx.empty())
	{
		BAK(x,y);
		s+=(A[x][y] == 'K');
		FOR2(k,8)
			if(KONTROL(x+yon[k][0],y+yon[k][1]))
				EKLE(x+yon[k][0],y+yon[k][1]);
	}
	return s == S;
}
int BS(int bas,int son)
{
	int orta = (bas + son)/2;
	if(bas == son) return kontrol(MINI,bas) ? bas : INF;
	if(bas + 1 == son) return kontrol(MINI,bas) ? bas : (kontrol(MINI,son)) ? son : INF;
	return kontrol(MINI,orta) ? min(orta,BS(bas,orta-1)) : BS(orta+1,son);
}
void solve()
{
	int i,j,maxi(0),res(INF);
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf(" %c",A[i]+j);
			if(A[i][j] == 'P') Px = i,Py = j;
			S+=(A[i][j] == 'K');
		}
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf("%d",B[i]+j);
			maxi >?= B[i][j];
			st.insert(B[i][j]);
		}
	set <int> :: iterator it;
	for(it = st.begin(); it!=st.end(); ++it)
	{
		MINI = *it;
		res = min(res,BS(*it,maxi)-MINI);
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
