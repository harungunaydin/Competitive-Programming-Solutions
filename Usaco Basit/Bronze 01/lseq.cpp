//SORU 437
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "lseq.in"
#define OUTPUT "lseq.out"
#define MAXN 30
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5];
void solve()
{
	int N,i,j,k,res=0;
	in >> N;
	FOR(i,1,N)
		in >> A[i];
	FOR(i,1,N)
		FOR(j,i+1,N)
				FOR(k,j+1,N)
					res+=((A[k] - A[j]) == (A[j] - A[i]));
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
