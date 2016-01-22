//SORU 375
//PROGRAM C++
#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "cornfld.in"
#define OUTPUT "cornfld.out"
#define MAXN 250
#define MAX(a,b) ( (a>b) ? a : b )
#define MIN(a,b) ( (a<b) ? a : b )
using namespace std;
FILE *in,*out;
int B,K,N;
int A[MAXN+5][MAXN+5];
short MAXI[MAXN+5][MAXN+5][MAXN+5],MINI[MAXN+5][MAXN+5][MAXN+5];
int hesapla(int x,int y)
{
	int i,j,maxi=0,mini=251;
	FOR(i,x,x+B)
	{
		maxi = MAX(maxi,MAXI[i][y][y+B]);
		mini = MIN(mini,MINI[i][y][y+B]);
	}
	return maxi - mini;
}
void solve()
{
	int a,b,i,j,k,maxi,mini;
	in =  fopen(INPUT,"r");
	out = fopen(OUTPUT,"w");
	fscanf(in,"%d %d %d",&N,&B,&K);
	B--;
	FOR(i,1,N)
		FOR(j,1,N)
			fscanf(in,"%d",A[i]+j);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			maxi = 0;
			mini = 251;
			FOR(k,j,N)
			{
				MAXI[i][j][k] = maxi = MAX(maxi,A[i][k]);
				MINI[i][j][k] = mini = MIN(mini,A[i][k]);
			}
		}
	FOR(i,1,K)
	{
		fscanf(in,"%d %d",&a,&b);
		fprintf(out,"%d\n",hesapla(a,b));
	}
}
int main()
{
	solve();
	return 0;
}
