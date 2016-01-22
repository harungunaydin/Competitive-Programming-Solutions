//SORU 350
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "route.in"
#define OUTPUT "route.out"
#define f first
#define s second
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
typedef pair <int,int> pii;
int C,M,N,S;
bool SNOW[MAXN+5][MAXN+5];
pii A[MAXN*MAXN+5];
void read()
{
	int a,b,i;
	in >> M >> N >> C >> S;
	FOR(i,1,C)
		in >> A[i].f >> A[i].s;
	A[++C] = make_pair(1,1);
	A[++C] = make_pair(M,N);
	sort(A+1,A+C+1);
	FOR(i,1,S)
	{
		in >> a >> b;
		SNOW[a][b] = true;
	}
}
int solve_it(int x1,int y1,int x2,int y2)
{
	int i,j;
	int DP[101][101]={0};
	for(i=x1; i<=x2 && !SNOW[i][y1]; i++)
		DP[i][y1] = 1;
	for(i=y1; i<=y2 && !SNOW[x1][i]; i++)
		DP[x1][i] = 1;
	FOR(i,x1+1,x2)
		FOR(j,y1+1,y2)
			if(!SNOW[i][j])
				DP[i][j]+=DP[i][j-1]*(!SNOW[i][j-1]) + DP[i-1][j]*(!SNOW[i-1][j]);
	return DP[x2][y2];
}
void solve()
{
	int i,res=1;
	FOR(i,1,C-1)
		res*=solve_it(A[i].f,A[i].s,A[i+1].f,A[i+1].s);
	out << res << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
