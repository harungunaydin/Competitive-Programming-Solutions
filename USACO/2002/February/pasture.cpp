//SORU 330
//PROGRAM C++
#include <iostream>
#include <cstdio>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define RFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INPUT "pasture.in"
#define OUTPUT "pasture.out"
#define MAXN 40
using namespace std;
FILE *in,*out;
bool DP[1605][1605];
int solve()
{
	int N,a,b,c,i,j,top(0);
	double u,res(0);
	fscanf(in,"%d",&N);
	DP[0][0] = true;
	while(N--)
	{
		fscanf(in,"%d",&a);
		RFOR(i,top,0)
			RFOR(j,top,0)
				if(DP[i][j])
					DP[i][j+a] = DP[i+a][j] = true;
		top+=a;
	}
	u = top/2.0;
	FOR(i,0,top)
		FOR(j,0,top)
			if(DP[i][j])
			{
				a = i; b = j; c = top-i-j;
				if(a+b > c && a+c > b && b+c > a)
					res = max(res,u*(u-a)*(u-b)*(u-c));
			}
	return res ? int(sqrt(res)*100) : -1;
}
int main()
{
	in = fopen(INPUT,"r");
	out = fopen(OUTPUT,"w");
	fprintf(out,"%d\n",solve());
	return 0;
}
