#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100
#define MIN(a,b) ((a > b) ? b : a)
#define MAX(a,b) ((a > b) ? a : b)
#define INF 100000000
using namespace std;
int N;
int A[MAXN+5],cozum[MAXN+5];
int MAX[MAXN+5][MAXN+5],MIN[MAXN+5][MAXN+5];
char B[MAXN+5];
int Max_MCP(int x,int y);
int Min_MCP(int x,int y)
{
	int *p = MIN[x] + y;
	if( *p != INF ) return *p;
	if(x == y) return A[x];
	int i,mini=INF;
	FOR(i,x,y-1)
		if(B[i+1] == 't')
			mini = MIN(mini,Min_MCP(x,i) + Min_MCP(i+1,y));
		else
		{
			mini = MIN(mini,Min_MCP(x,i) * Max_MCP(i+1,y));
			mini = MIN(mini,Max_MCP(x,i) * Min_MCP(i+1,y));
			mini = MIN(mini,Min_MCP(x,i) * Min_MCP(i+1,y));
		}
	return *p = mini;
}
int Max_MCP(int x,int y)
{
	int *p = MAX[x] + y;
	if( *p != -INF ) 	return *p;
	if(x == y) 	return A[x];
	int a,b,i,maxi=-INF;
	FOR(i,x,y-1)
		if(B[i+1] == 't')
			maxi = MAX(maxi,Max_MCP(x,i) + Max_MCP(i+1,y));
		else
		{
			maxi = MAX(maxi,Min_MCP(x,i)*Min_MCP(i+1,y));
			maxi = MAX(maxi,Max_MCP(x,i)*Max_MCP(i+1,y));
		}
	return *p = maxi;
}
void solve()
{
	int b,cozum_sayisi=0,i,res=-INF,t;
	char a;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf(" %c %d",B+i,A+i);
		A[i+N] = A[i];
		B[i+N] = B[i];
	}
	FOR(i,1,N)
	{
		t = Max_MCP(i,i+N-1);
		if(t > res)
		{
			cozum_sayisi = 0;
			res = t;
		}
		if(t == res)
			cozum[cozum_sayisi++] = i;
	}
	printf("%d\n",res);
	sort(cozum,cozum+cozum_sayisi);
	FOR2(i,cozum_sayisi)
		printf("%d ",cozum[i]);
	printf("\n");
}

void fill(){
	int i,j;
	for( i=0 ; i<103 ; i++ ) 
		for( j=0 ; j<103 ; j++ ) 
			MAX[i][j] = -INF , MIN[i][j] = INF;
}

int main()
{
	fill();
	solve();
	return 0;
}
