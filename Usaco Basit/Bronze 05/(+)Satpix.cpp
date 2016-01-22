//SORU 477
//PROGRAM C++
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
FILE *in,*out;
int M,N;
int B[1000005];
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int A[1005][1005];
void read()
{
	int i,j;
	in=fopen("satpix.in","r");
	out=fopen("satpix.out","w");
	fscanf(in,"%d %d",&N,&M);
	FOR(i,1,M)
		FOR(j,1,N)
			fscanf(in," %c",&A[i][j]);
}
void solve(int x,int y,int s)
{
	int i;
	B[s]++;
	A[x][y] = '.';
	FOR(i,0,3)
		if(A[x+yon[i][0]][y+yon[i][1]] == '*')
			solve(x+yon[i][0],y+yon[i][1],s);
}
int main()
{
	int i,j,k=0;
	read();
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == '*')
				solve(i,j,++k);
	fprintf(out,"%d\n",*max_element(B+1,B+k+1));
	return 0;
}
