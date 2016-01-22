//SORU 386
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "icecrm.in"
#define OUTPUT "icecrm.out"
#define MAXN 1000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int repeat[MAXN+5];
int bas(int a)
{
	int res=0;
	while(a)
	{
		res++;
		a/=10;
	}
	return res;
}
int middle_4_digits(int a)
{
	int k=1,s=0,res=0;
	a/=10;
	while(a && s < 4)
	{
		s++;
		res+=(a%10)*k;
		k*=10;
		a/=10;
	}
	return res;
}
void solve()
{
	int N,b,i=0;
	in >> N;
	b = N;
	while(++i)
	{
		b = middle_4_digits(b);
		b = (b*b)%MAXN;
		if(repeat[b]) { out << b << " " << i-repeat[b] << " "; break; }
		repeat[b] = i;
	}
	out << i << endl;
}
int main()
{
	solve();
	return 0;
}
