//SORU 538
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "wpb.in"
#define OUTPUT "wpb.out"
#define all(x) x.begin(),x.end()
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int D,N;
int bas(int a)
{
	int s = 0;
	while(a)
	{
		s++;
		a/=10;
	}
	return s;
}
bool asal(int a)
{
	if(!(a&1) || a == 1 || bas(a) < D) return 0;
	int b = (int)sqrt(a),i;
	for(i=3; i<=b; i+=2)
		if(!(a%i))
			return 0;
	return 1;
}
int solve()
{
	int a,b,d,i,j,k=1;
	in >> D >> N;
	for(j=1; j<=D; j++)
			k*=10;
	d = -2*D + 1;
	for(i=N; ;i++)
	{
		a = bas(i) + d;
		b = k;
		FOR(j,1,a)
		{
			if(asal(i/b) && asal(i%b))
				return i;
			b*=10;
		}
	}
}
int main()
{
	out << solve() << endl;
	return 0;
}
