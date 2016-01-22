//SORU 337
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "life.in"
#define OUTPUT "life.out"
#define MAXN 10000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5];
int us(int a,int b)
{
	return !b ? 1 : us(a,b-1)*a;
}
int donustur(int x,int p)
{
	int t=0;
	while(x)
	{
		t+=us((x%10),p);
		x/=10;
	}
	return t;
}
int solve()
{
	int N,P,i=1;
	in >> N >> P;
	while(1)
	{
		A[N] = i;
		N = donustur(N,P);
		if(A[N]) return A[N] - 1;
		i++;
	}
}
int main()
{
	out << solve() << endl;
	return 0;
}
