#include<iostream>
#include<cstdio>
using namespace std;
char A[15][15];
bool X[15],Y[15],w;
int n;
int yazdir()
{
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(A[i][j]=='1' && X[i] && !Y[j])
			return 0;
			if(A[i][j]=='x')
			cnt++;
		}
	return cnt;
}
void solve(int x, int y)
{
	if(w) return ;
	if(y==n) { x++; y=0; }
	if(x==n) { int t=yazdir(); if(t){ cout << t << endl; for(int i=0;i<n;i++) printf("%s\n",A[i]); w=1;} return ; }
	if(A[x][y]=='1' && !X[x] && !Y[y])
	{
		A[x][y]='x';
		X[x]=Y[y]=1;
		solve(x,y+1);
		X[x]=Y[y]=0;
		A[x][y]='1';
	}
	solve(x,y+1);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%s",A[i]);
	solve(0,0);
	return 0;
}
