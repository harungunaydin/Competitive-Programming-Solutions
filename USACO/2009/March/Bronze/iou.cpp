//SORU 1231
//PROGRAM C++
#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "iou.in"
#define OUTPUT "iou.out"
#define MAXN 100000
using namespace std;
FILE *in,*out;
int A[MAXN+5];
void solve()
{
	int N,firstowe(0),i,money(0),owe(0),res(0);
	fscanf(in,"%d",&N);
	FOR(i,1,N)
		fscanf(in,"%d",A+i);
	FOR(i,1,N)
	{
		res++;
		if(A[i] < 0)
		{
			if(!owe && money>=-A[i])
			{
				money+=A[i];
				continue;
			}
			if(!owe)
				firstowe = i;
			owe-=A[i];
			continue;
		}
		money+=A[i];
		if(owe && money > owe)
		{
			money-=owe;
			owe = 0;
			res+=(i-firstowe)<<1;
		}
	}
	fprintf(out,"%d\n",res);
}
int main()
{
	in = fopen(INPUT,"r");
	out = fopen(OUTPUT,"w");
	solve();
	return 0;
}
