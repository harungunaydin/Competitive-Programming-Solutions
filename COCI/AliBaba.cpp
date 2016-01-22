#include<iostream>
#include<cstdio>
#include<algorithm>
#define f first
#define s second
using namespace std;
int A[1005][1005],n,m,k,kk,ata[100005],mx;
int H[1005][1005];
bool h[100005];
pair < int , int > B[100005];
pair < int ,pair < int , int > > K[10005];
char S[1005];
int solve( int x , int y )
{
	int a=A[x][y],_max=0;
	A[x][y]=0;
	if(A[x+1][y]) _max=max(_max,solve(x+1,y));
	if(A[x][y-1]) _max=max(_max,solve(x,y-1));
	if(A[x-1][y]) _max=max(_max,solve(x-1,y));
	if(A[x][y+1]) _max=max(_max,solve(x,y+1));
	A[x][y]=a;
	return _max+a;
}
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",S);
		for(j=1;j<=m;j++)
			A[i][j]=S[j-1]-'0';
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(A[i][j])
				mx=max(mx,solve(i,j));
	cout << mx << endl;
	return 0;
}
