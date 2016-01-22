//SORU 489
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "trt.in"
#define OUTPUT "trt.out"
#define MAXN 2000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
int A[MAXN+5],DP[MAXN+5][MAXN+5];
int solve(int a,int b)
{
	if(DP[a][b]) return DP[a][b];
	if(a > b) return 0;
	int g = a+N-b;
	return DP[a][b] = max(solve(a,b-1)+A[b]*g,solve(a+1,b)+A[a]*g);
}
int main()
{
	int i;
	in >> N;
	FOR(i,1,N)
		in >> A[i];
	out << solve(1,N) << endl;
	return 0;
}
