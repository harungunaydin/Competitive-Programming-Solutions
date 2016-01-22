#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); visited[x][y]=true; }
#define BAK(x,y,s) { x=qx.front(); y=qy.front(); s=qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define KONTROL(x,y) (x>0 && y>0 && A[x][y] && !visited[x][y])
using namespace std;
queue <int> qx,qy,qs;
vector <int> V;
vector <int> :: iterator it;
int H,K,L;
int A[10005][10005],yon[6][2]={ {1,0},{1,1},{0,1},{-1,0},{-1,-1},{0,-1} };
bool visited[10005][10005];
void read()
{
	int a,b=2,i,j,s=0;
	scanf("%d %d %d",&K,&H,&L);
	a=2*K-1;
	FOR(i,1,K)
		TFOR(j,K+i-1,1)
		{
			A[j][i]=++s;
			if(s==H) EKLE(j,i,0);
		}
	FOR(i,K+1,a)
	{
		TFOR(j,a,b)
		{
			A[j][i]=++s;
			if(s==H) EKLE(j,i,0);
		}
		b++;
	}
}
void solve()
{
	int i,s,x,y;
	while(!qx.empty())
	{
		BAK(x,y,s);
		if(s==L) { V.push_back(A[x][y]); continue;}
		for(int i=0; i<6; i++)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1],s+1);
	}
	sort(V.begin(),V.end());
	printf("%d\n",V.size());
	for(it=V.begin(); it!=V.end(); ++it)
		printf("%d\n",*it);
}
int main()
{
	read();
	solve();
	return 0;
}
