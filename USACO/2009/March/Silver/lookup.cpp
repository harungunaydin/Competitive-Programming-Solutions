//SORU 1230
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "lookup.in"
#define OUTPUT "lookup.out"
#define MAXN 100000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
stack <int> st;
int A[MAXN+5],res[MAXN+5];
void solve()
{
	int N,i;
	in >> N;
	FOR(i,1,N)
		in >> A[i];
	FOR(i,1,N)
	{
		while(!st.empty() && A[i] > A[st.top()])
		{
			res[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	FOR(i,1,N)
		out << res[i] << endl;
}
int main()
{
	solve();
	return 0;
}
