#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 25
#define esit(x,y,c) (A[x][y] == c)
#define cont(x,y,c) ((!visited[x][y] || (esit(x,y,'+') && visited[x][y] < 2)) && esit(x,y,c))
using namespace std;
int visited[MAXN+5][MAXN+5],yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN+5][MAXN+5];
void solve()
{
	int M,N,i,j,k,s(0),x,xx,y,yy;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",A[i]+j);
			if(A[i][j] == 'M') x = i,y = j;
		}
	if(esit(x+1,y,'|')) { x++; k = 0; }
	else if(esit(x+1,y,'+')) { x++; k = 0; }
	else if(esit(x+1,y,'2')) { x++; k = 1; }
	else if(esit(x+1,y,'3')) { x++; k = 3; }
	else if(esit(x,y+1,'-')) { y++; k = 1; }
	else if(esit(x,y+1,'+')) { y++; k = 1; }
	else if(esit(x,y+1,'3')) { y++; k = 2; }
	else if(esit(x,y+1,'4')) { y++; k = 0; }
	else if(esit(x-1,y,'|')) { x--; k = 2; }
	else if(esit(x-1,y,'+')) { x--; k = 2; }
	else if(esit(x-1,y,'1')) { x--; k = 1; }
	else if(esit(x-1,y,'4')) { x--; k = 3; }
	else if(esit(x,y-1,'-')) { y--; k = 3; }
	else if(esit(x,y-1,'+')) { y--; k = 3; }
	else if(esit(x,y-1,'1')) { y--; k = 0; }
	else if(esit(x,y-1,'2')) { y--; k = 2; }
	while(1)
	{
		xx = x + yon[k][0];
		yy = y + yon[k][1];
		visited[x][y]++;
		if(esit(xx,yy,'.')) break;
		if(esit(xx,yy,'1')) k = (k == 3) ? 0 : 1;
		else if(esit(xx,yy,'2')) k = (k == 3) ? 2 : 1;
		else if(esit(xx,yy,'3')) k = (k == 1) ? 2 : 3;
		else if(esit(xx,yy,'4')) k = (k == 1) ? 0 : 3;
		x = xx; y = yy;
	}
	char c;
	if(cont(xx+1,yy,'|') || cont(xx+1,yy,'+') || cont(xx+1,yy,'2') || cont(xx+1,yy,'3')) { s++; c = (k == 0) ? '|' : (k == 1) ? '4' : '1'; }
	if(cont(xx,yy+1,'-') || cont(xx,yy+1,'+') || cont(xx,yy+1,'3') || cont(xx,yy+1,'4')) { s++; c = (k == 1) ? '-' : (k == 0) ? '2' : '1'; }
	if(cont(xx-1,yy,'|') || cont(xx-1,yy,'+') || cont(xx-1,yy,'1') || cont(xx-1,yy,'4')) { s++; c = (k == 2) ? '|' : (k == 1) ? '3' : '2'; }
	if(cont(xx,yy-1,'-') || cont(xx,yy-1,'+') || cont(xx,yy-1,'1') || cont(xx,yy-1,'2')) { s++; c = (k == 3) ? '-' : (k == 0) ? '3' : '4'; }
	if(s > 1) c = '+';
	printf("%d %d %c\n",xx,yy,c);
}
int main()
{
	solve();
	return 0;
}
