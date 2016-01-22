//SORU 478
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "passwd.in"
#define OUTPUT "passwd.out"
#define MAXN 15
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int L,C;
int comb[MAXN+5];
char A[MAXN+5];
void Control_And_Print()
{
	int i,s1=0,s2=0;
	FOR(i,1,L)
		if(A[comb[i]] == 'a' || A[comb[i]] == 'e' || A[comb[i]] == 'i' || A[comb[i]] == 'o' || A[comb[i]] == 'u')
			s1++;
	if(!s1 || L-s1 < 2) return;
	FOR(i,1,L)
		out << A[comb[i]];
	out << endl;
}
void rec(int x)
{
	int i;
	if(x == L+1)
	{
		Control_And_Print();	
		return;
	}
	FOR(i,comb[x-1]+1,C)
	{
		comb[x] = i;
		rec(x+1);
	}
}
void solve()
{
	int i;
	in >> L >> C;
	FOR(i,1,C)
		in >> A[i];
	sort(A+1,A+C+1);
	rec(1);
}
int main()
{
	solve();
	return 0;
}
