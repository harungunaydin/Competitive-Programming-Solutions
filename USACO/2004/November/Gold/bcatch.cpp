//SORU 543
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "bcatch.in"
#define OUTPUT "bcatch.out"
#define MAXN 1000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int T,W;
int A[MAXN+5],DP[3][MAXN+5][35];
void read()
{
	int a,i;
	in >> T >> W;
	FOR(i,1,T)
	{
		in >> a;
		A[i] = a;
	}
}
int solve(int x,int t,int move)
{
	if(t > T || move > W) return 0;
	if(DP[x][t][move]) return DP[x][t][move];
	return DP[x][t][move] = max(solve(3-x,t+1,move+1),solve(x,t+1,move)) + (A[t] == x);
}
int main()
{
	read();
	out << solve(1,0,0) << endl;
	return 0;
}
