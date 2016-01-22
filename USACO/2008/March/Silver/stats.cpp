//SORU 1041
//PROGRAM C++
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "stats.in"
#define OUTPUT "stats.out"
#define MAXN 1000
using namespace std;
FILE *in,*out;
int A[MAXN+5];
void solve()
{
	int N,i;
	double top=0;
	in = fopen(INPUT,"r");
	fscanf(in,"%d",&N);
	FOR(i,1,N)
	{
		fscanf(in,"%d",A+i);
		top+=A[i];
	}
	sort(A+1,A+N+1);
	out = fopen(OUTPUT,"w");
	fprintf(out,"%.6lf\n%.6lf\n",top/N,(N&1) ? A[N/2+1] : ((A[N/2] + A[N/2+1] )/2.0));
}
int main()
{
	solve();
	return 0;
}
