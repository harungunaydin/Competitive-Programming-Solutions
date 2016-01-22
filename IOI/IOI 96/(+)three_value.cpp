/*
ID : harung91
PROG : sort3
LANG : C++
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "sort3.in"
#define OUTPUT "sort3.out"
#define MAXN 1000
using namespace std;
FILE *in,*out;
int A[MAXN+5],B[MAXN+5],S[4][4];
void solve()
{
	int N,i,j,maxi=0,res;
	in = fopen(INPUT,"r");
	fscanf(in,"%d",&N);
	FOR(i,1,N)
	{
		fscanf(in,"%d",A+i);
		B[i] = A[i];
	}
	sort(B+1,B+N+1);
	FOR(i,1,N)
		S[B[i]][A[i]]++;
	res =min(S[1][2],S[2][1]);
	res+=min(S[1][3],S[3][1]);
	res+=min(S[2][3],S[3][2]);
	res+=abs(S[1][2] - S[2][1])*2;
	out = fopen(OUTPUT,"w");
	fprintf(out,"%d\n",res);
}
int main()
{
	solve();
	return 0;
}
