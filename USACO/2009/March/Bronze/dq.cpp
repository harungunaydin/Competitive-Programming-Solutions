//SORU 1234
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "dq.in"
#define OUTPUT "dq.out"
#define MAXN 10
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int C,N,maxi,s;
int A[MAXN],DP[1005][1005];
void read()
{
	int i,j;
	in >> N >> C;
	FOR(i,1,C)
		in >> A[i];
}
int solve(int a,int x)
{
	if(x == N) return 1;
	if(x > N) return 0;
	if(DP[a][x]) return DP[a][x];
	int i,s=0;
	FOR(i,a,C)
		s+=solve(i,x+A[i]);
	return DP[a][x] = s;
}
int main()
{
	read();
	out << solve(1,0) << endl;
	return 0;
}
