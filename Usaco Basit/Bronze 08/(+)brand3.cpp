//SORU 513
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INPUT "brand3.in"
#define OUTPUT "brand3.out"
#define MAXN 15
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
string str[MAXN+5];
int A,B,N,s;
char comb[MAXN+5];
bool used[505];
void rec(int x)
{
	int i;
	if(x == N+1)
	{
		if(++s > B) exit(0);
		if(s >= A)
		{
			FOR(i,1,N)
				out << comb[i];
			out << endl;
		}
		return;
	}
	FOR2(i,str[x].size())
		if(!used[str[x][i]])
		{
			used[str[x][i]] = true;
			comb[x] = str[x][i];
			rec(x+1);
			used[str[x][i]] = false;
		}
}
void solve()
{
	int i;
	in >> N >> A >> B;
	FOR(i,1,N)
		in >> str[i];
	rec(1);
}
int main()
{
	solve();
	return 0;
}
