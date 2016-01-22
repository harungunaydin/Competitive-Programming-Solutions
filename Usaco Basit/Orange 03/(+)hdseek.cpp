//SORU 349
//PROGRAM C++
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "hdseek.in"
#define OUTPUT "hdseek.out"
using namespace std;
FILE *in,*out;
double Distance(int x1,int y1,int x2,int y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
void solve()
{
	int x1,x2,x3,y1,y2,y3;
	in = fopen(INPUT,"r");
	out = fopen(OUTPUT,"w");
	fscanf(in,"%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	if(x1 == x2 && x2 == x3 && y1 == y2 && y2 == y3)
		fprintf(out,"p 0.00\n");
	else if(abs(double(y2-y1)/(x2-x1) - double(y3-y2)/(x3-x2)) < 0.00000001)
		fprintf(out,"l %.2lf\n",Distance(x1,y1,x2,y2) + Distance(x2,y2,x3,y3));
	else
		fprintf(out,"t %.2lf\n",abs(x1*y2+x2*y3+x3*y1 - (y1*x2+y2*x3+y3*x1))/2.0);
}
int main()
{
	solve();
	return 0;
}
