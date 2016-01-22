#include <iostream>
#include <map>
#include <queue>
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); A[x][y]='#'; }
#define BAK(x,y,s)  { x=qx.front(); y=qy.front(); s=qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define HARF(x) (x>='A' && x<='Z')
using namespace std;
typedef pair <int,int> pii;
map < pii,pii > mp;
queue <int> qx,qy,qs;
int M,N,hx,hy,s;
int yon[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };
char A[305][305];
void find_and_add(int x,int y)
{
	int i,j;
	char c=A[x][y];
	FOR(i,1,N)
		FOR(j,1,N)
			if(i!=x && j!=y && A[i][j]==c)
			{
				EKLE(i,j,s+1);
				break;
			}
}
int solve()
{
	int a,b,i,j,x,y;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",&A[i][j]);
			if(A[i][j] == '@')
				EKLE(i,j,0);
			if(A[i][j] == '=')
				hx=i,hy=j;
		}
	while(!qx.empty())
	{
		BAK(x,y,s);
		if(x == hx && y == hy) return s;
		FOR(i,0,3)
		{
			a=x+yon[i][0];
			b=y+yon[i][1];
			if(A[a][b] == '.' || A[a][b] == '=') EKLE(a,b,s+1)
			else if(HARF(A[a][b])) find_and_add(a,b);
		}
	}
	return -1;
}
int main()
{
	printf("%d\n",solve());
	getchar(); getchar();
	return 0;
}
