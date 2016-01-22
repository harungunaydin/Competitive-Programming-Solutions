//SORU 501
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "solitair.in"
#define OUTPUT "solitair.out"
#define MAXN 7
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
int A[MAXN+5][MAXN+5],DP[MAXN+5][MAXN+5];
int cevir(char c)
{
	if(c == 'A') return 1;
	if(c == 'T') return 10;
	if(c == 'J') return 11;
	if(c == 'Q') return 12;
	if(c == 'K') return 13;
	return c-'0';
}
int rec(int x,int y)
{
	if(x < 1 || x > N || y < 1 || y > N) return 0;
	if(x == 1 && y == N) return A[1][N];
	if(DP[x][y]) return DP[x][y];
	return DP[x][y] = max(rec(x-1,y),rec(x,y+1)) + A[x][y];
}
void solve()
{
	int i,j;
	char a,b;
	in >> N;
	FOR(i,1,N)
		FOR(j,1,N)
		{
			in >> a >> b;
			A[i][j] = cevir(a);
		}
	out << rec(N,1) << endl;
}
int main()
{
	solve();
	return 0;
}
