//SORU 413
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "rects.in"
#define OUTPUT "rects.out"
#define MAXN 100
#define f first
#define s second
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
typedef pair <int,int> pii;
pii p[MAXN+5];
int DP[MAXN+5];
bool kapsar_mi(int a,int b,int c,int d)
{
	return (a >= c && b >= d && !(a == c && b == d));
}
void solve()
{
	int N,a,b,i,j,res=0;
	in >> N;
	FOR(i,1,N)
	{
		in >> a >> b;
		p[i] = make_pair(min(a,b),max(a,b));
	}
	sort(p+1,p+N+1);
	fill(DP+1,DP+N+1,1);
	cout << endl << endl;
	FOR(i,1,N)
		FOR(j,1,i-1)
			if(kapsar_mi(p[i].f,p[i].s,p[j].f,p[j].s) && DP[i] < DP[j]+1)
			{
				DP[i] = DP[j] + 1;
				res = max(res,DP[i]);
			}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
