//SORU 1155
//PROGRAM C++
#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "patheads.in"
#define OUTPUT "patheads.out"
#define MAXN 100005
#define MAXA 1000005
using namespace std;
FILE *in,*out;
int N;
int A[MAXN],sayi[MAXA],result[MAXA];
void solve()
{
	int i,j;
	in = fopen(INPUT,"r");
	out = fopen(OUTPUT,"w");
	fscanf(in,"%d",&N);
	FOR(i,1,N)
	{
		fscanf(in,"%d",A+i);
		sayi[A[i]]++;
	}
	for(i=0; i<MAXA; i++)
		if(sayi[i])
			for(j=i; j<MAXA; j+=i)
				result[j]+=sayi[i];
	FOR(i,1,N)
		fprintf(out,"%d\n",result[A[i]]-1);
}
int main()
{
	solve();
	return 0;
}
