//SORU 439
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "ptwo.in"
#define OUTPUT "ptwo.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[1000];
void solve()
{
	int N,carry,i,j,size=1;
	in >> N;
	A[0] = 1;
	FOR(i,1,N)
	{
		carry = 0;
		for(j = 0; j<size || carry; j++)
		{
			carry+=A[j]*2;
			A[j] = carry%10;
			carry/=10;
		}
		size = max(size,j);
	}
	reverse(A,A+size);
	FOR2(i,size)
		out << A[i];
}
int main()
{
	solve();
	return 0;
}
