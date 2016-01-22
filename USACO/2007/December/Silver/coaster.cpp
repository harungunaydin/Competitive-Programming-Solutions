//SORU 537
//PROGRAM C++
#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define INF 2000000000
#define INPUT "coaster.in"
#define OUTPUT "coaster.out"
#define mp make_pair
#define MAXN 10000
using namespace std;
typedef pair <int,int> pii;
FILE *in,*out;
vector < pair <int,pii> > V[MAXN+5];
int B,L,N;
bool flag;
long long DP[MAXN+5][1005];
void read()
{
	int a,b,c,d,i;
	fscanf(in,"%d %d %d",&L,&N,&B);
	FOR(i,1,N)
	{
		fscanf(in,"%d %d %d %d",&a,&b,&c,&d);
		V[a].push_back(mp(b,mp(c,d)));
	}
}
long long solve(int x,int c)
{
	if(x == L) { flag = true; return INF; }
	if(DP[x][c]) return DP[x][c];
	vector < pair <int,pii> > :: iterator it;
	long long maxi(0);
	for(it = V[x].begin(); it!=V[x].end(); ++it)
		if(x + it->f <= L && c + it->s.s <= B)
			maxi = max(maxi,solve(x + it->f,c+it->s.s) + it->s.f);
	return DP[x][c] = maxi;
}
int main()
{
	in = fopen(INPUT,"r");
	out = fopen(OUTPUT,"w");
	read();
	long long a = solve(0,0) - INF;
	fprintf(out,"%d\n",flag ? a : -1);
	return 0;
}
