//SORU 510
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "bedhair.in"
#define OUTPUT "bedhair.out"
#define MAXN 80000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);

int A[MAXN+5],B[MAXN+5],stack[MAXN+5];
void solve()
{
	long long a,N,bas = 0,i,res=0;
	in >> N;
	FOR(i,1,N)
	{
		in >> A[i];
		while(bas && A[stack[bas]] <= A[i]) B[stack[bas--]] = i;
		stack[++bas] = i;
	}
	FOR(i,1,N)
		res+=(B[i]) ? B[i]-i-1 : N-i;
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
