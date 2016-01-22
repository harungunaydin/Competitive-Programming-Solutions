#include <iostream>
#include <queue>
#define EKLE(x,y,a) { qx.push(x); qy.push(y); qa.push(a); }
#define BAK(x,y,a) { x=qx.front(); y=qy.front(); a=qa.front(); qx.pop(); qy.pop(); qa.pop(); }
using namespace std;
queue <int> qx,qy,qa;
char A[1000][1000];
int M,N,K;
int yon[1000];
bool hash[60][60][1000];
void read()
{
	string str;
	cin >> M >> N;
	for(int i=1; i<=M; i++)	
		for(int j=1; j<=N; j++)
		{
			cin >> A[i][j];
			if(A[i][j]=='*') { A[i][j]='.'; EKLE(i,j,0); }
		}
	cin >> K;
	for(int i=0; i<K; i++)
	{
		cin >> str;
		yon[i]=(str=="NORTH")? 1 : (str=="EAST")? 2 : 4-(str=="SOUTH");
	}
}
void solve()
{
	int a,i,s,x,y;
	while(!qx.empty())
	{
		BAK(x,y,a);
		hash[x][y][a]=false;
		if(a==K) { A[x][y]='*'; continue; }
		if(yon[a]==1)
			for(i=x-1; i; i--)
			{
				if(A[i][y]=='X')
					break;
				if(!hash[i][y][a+1])
				{
					EKLE(i,y,a+1);
					hash[i][y][a+1]=true;
				}
			}
		if(yon[a]==2)
			for(i=y+1; i<=N; i++)
			{
				if(A[x][i]=='X')
					break;
				if(!hash[x][i][a+1])
				{
					EKLE(x,i,a+1);
					hash[x][i][a+1]=true;
				}
			}
		if(yon[a]==3)
			for(i=x+1; i<=M; i++)
			{
				if(A[i][y]=='X')
					break;
				if(!hash[i][y][a+1])
				{
					EKLE(i,y,a+1);
					hash[i][y][a+1]=true;
				}
			}
		if(yon[a]==4)
			for(i=y-1; i; i--)
			{
				if(A[x][i]=='X')
					break;
				if(!hash[x][i][a+1])
				{
					EKLE(x,i,a+1);
					hash[x][i][a+1]=true;
				}
			}
	}
	for(int i=1; i<=M; i++,cout << endl)
		for(int j=1; j<=N; j++)
			cout << A[i][j];
}
int main()
{
	read();
	solve();
	return 0;
}
