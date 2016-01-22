//SORU 929
//PROGRAM C++
#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define INPUT "milkprod.in"
#define OUTPUT "milkprod.out"
#define MAXN 1000000
using namespace std;
FILE *in,*out;
typedef pair <int,int> pii;
vector <pii> V[MAXN+5];
int M,N,R;
int DP[MAXN+5];
int solve(int x)
{
	if(x>=N) return 0;
	if(DP[x]) return DP[x];
	int i,maxi=0;
	vector <pii> :: iterator it;
	for(it = V[x].begin(); it!=V[x].end(); ++it)
		maxi = max(maxi,solve(it->f+R)+it->s);
	return DP[x] = max(maxi,solve(x+1));
}
int main()
{
	int a,b,c,i;
	in = fopen(INPUT,"r");
	fscanf(in,"%d %d %d",&N,&M,&R);
	FOR(i,1,M)
	{
		fscanf(in,"%d %d %d",&a,&b,&c);
		V[a].push_back(make_pair(b,c));
	}
	out = fopen(OUTPUT,"w");
	fprintf(out,"%d\n",solve(0));
	return 0;
}
