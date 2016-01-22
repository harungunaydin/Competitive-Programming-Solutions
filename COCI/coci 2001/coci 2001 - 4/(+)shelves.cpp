#include <iostream>
using namespace std;
int C,M,N;
int DP[1000][1000];
int A[1000];
void read()
{
	int i=0,x,y;
	cin >> N >> M >> C;
	for(; i<C; i++)
	{
		cin >> y >> x;
		A[y]=max(A[y],x);
	}
}
int MCP(int x,int y)
{
	if(DP[x][y]) return DP[x][y];
	if(x>y) return DP[x][y]=0;
	if(x==y) return DP[x][y]=A[x];
	if(x+1==y) return DP[x][y]=max(A[x],A[y]);
	if(x+2==y) return DP[x][y]=max(A[x],max(A[x+1],A[y]));
	int i=x+1,mini=INT_MAX;
	for(; i<y; i++)
		mini=min(mini,MCP(x,i-2)+MCP(i+2,y)+max(A[i-1],max(A[i],A[i+1])));
	return DP[x][y]=mini;
}
int main()
{
	read();
	cout << MCP(1,N) << endl;
	return 0;
}
