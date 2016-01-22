//SORU 933
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "lake.in"
#define OUTPUT "lake.out"
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int K,M,N,s;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int B[MAXN+5];
int A[MAXN+5][MAXN+5];
void read()
{
	in >> M >> N >> K;
	int a,b,i;
	FOR(i,1,K)
	{
		in >> a >> b;
		A[a][b] = true;
	}
}
void solve(int x,int y)
{
	A[x][y] = 0;
	B[s]++;
	for(int i=0; i<4; i++)
		if(A[ x+yon[i][0] ][ y+yon[i][1] ])
			solve(x+yon[i][0],y+yon[i][1]);
}
int main()
{
	read();
	int i,j;
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j])
			{
				s++;
				solve(i,j);
			}
	out << *max_element(B,B+s+1) << endl;
	return 0;
}
