//SORU 319
//PROGRAM C++
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "cowdom.in"
#define OUTPUT "cowdom.out"
#define MAXN 40
using namespace std;
FILE *in,*out;
int N;
int A[MAXN+5];
void rec_print(int x,bool carry)
{
	if(x > N && !carry) return;
	A[x]+=carry;
	rec_print(x+1,A[x]>9);
	fprintf(out,"%d",A[x]%10);
}
void solve()
{
	int a,b,i;
	in = fopen(INPUT,"r");
	fscanf(in,"%d",&N);
	FOR(i,1,N)
	{
		fscanf(in,"%d %d",&a,&b);
		A[i] = a + b;
	}
	sort(A+1,A+N+1);
	out = fopen(OUTPUT,"w");
	rec_print(1,0);
}
int main()
{
	solve();
	return 0;
}
