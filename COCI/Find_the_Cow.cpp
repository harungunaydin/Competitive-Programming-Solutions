#include <iostream>
#include <fstream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 50000
using namespace std;
ifstream in("cowfind.in");
ofstream out("cowfind.out");
int N;
int A[MAXN+5],T[MAXN+5];
bool B[MAXN+5];
void solve()
{
	string str;
	int i,res(0),t;
	in >> str;
	t = str.size();
	FOR2(i,t-1)
		if(str[i] == '(' && str[i+1] == '(')
			A[++N] = i+1;
	TFOR(i,t-1,0)
		if(str[i] == ')' && str[i+1] == ')')
			B[i+1] = true;
	TFOR(i,t-1,0)
		T[i] = T[i+1] + B[i];
	FOR(i,1,N)
		res+=T[A[i]];
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
