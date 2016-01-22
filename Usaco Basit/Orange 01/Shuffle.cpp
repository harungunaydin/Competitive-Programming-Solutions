//SORU 327
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "shuffle.in"
#define OUTPUT "shuffle.out"
#define MAXN 9000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN*2+5],B[2*MAXN+5];
void solve()
{
	int N,i,j,s,res=0;
	in >> N;
	N<<=1;
	FOR(i,1,N)
		A[i] = i;
	while(1)
	{
		res++;
		FOR(i,1,N)
			B[i] = A[i];
		i = N;
		s = 1;
		while(i>0)
		{
			A[i] = B[s];
			i--;
			A[i] = B[N/2+s];
			i--;
			s++;
		}
		if(adjacent_find(A+1,A+N+1,greater <int>()) == A+N+1) break;
	}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
