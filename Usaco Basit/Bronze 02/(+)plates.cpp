//SORU 448
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "plates.in"
#define OUTPUT "plates.out"
#define all(x) x.begin(),x.end()
#define MAXN 5000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
int A[MAXN+5],DP[MAXN+5];
int BS(int bas,int son,int x)
{
	int orta = (bas+son)/2;
	return (bas == son) ? bas : (DP[orta] >= x) ? BS(bas,orta,x) : BS(orta+1,son,x);
}
void solve()
{
	int a,i,index,maxi=0;
	in >> N;
	FOR(i,1,N)
		in >> A[i];
	reverse(A+1,A+N+1);
	FOR(i,1,N)
	{
		index = BS(0,maxi,A[i]);
		maxi+=!(DP[index]);
		DP[index] = A[i];
	}
	out << maxi << endl;
}
int main()
{
	solve();
	return 0;
}
