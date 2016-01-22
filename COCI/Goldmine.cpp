#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAX(a,b) ( ( a > b ) ? (a) : (b) )
#define MAXK 60000
#define MAXL 30000
#define MAXN 15000
using namespace std;
typedef pair < int , int > pii;
vector < int > X[MAXK+5],Y[MAXK+5];
pii P[MAXN+5];
int N,S,W;
int H1(int x,int y1,int y2)
{
	vector < int > :: iterator it;
	int s(0);
	for(it = X[x].begin(); it != X[x].end() && *it <= y2; ++it)
		s+=(*it >= y1);
	return s;
}
int H2(int y,int x1,int x2)
{
	vector < int > :: iterator it;
	int s(0);
	for(it = Y[y].begin(); it != Y[y].end() && *it <= x2; ++it)
		s+=(*it >= x1);
	return s;
}
void read()
{
	int i;
	scanf("%d %d",&S,&W);
	S++; W++;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&P[i].f,&P[i].s);
		P[i] = make_pair( P[i].f + MAXL , P[i].s + MAXL );
		X[P[i].f].push_back(P[i].s);
		Y[P[i].s].push_back(P[i].f);
	}
	FOR(i,1,N)
	{
		sort( all( X[P[i].f] ) );
		sort( all( Y[P[i].s] ) );
	}
}
void solve()
{
	int alt,i,j,res(0),sag,sol,t,ust;
	FOR(i,1,N)
	{
		sol = P[i].f; ust = P[i].s;
		sag = sol + S - 1; alt = ust - W + 1;
		t = 0;
		FOR(j,sol,sag) t+=H1(j,alt,ust);
		FOR(j,2,S)
		{
			sag--; sol--;
			t = t + H1(sol,alt,ust) - H1(sag+1,alt,ust);
			res = MAX( res , t );
		}
		FOR(j,2,W)
		{
			alt++; ust++;
			t = t + H2(ust,sol,sag) - H2(alt-1,sol,sag);
			res = MAX( res , t );
		}
		FOR(j,2,S)
		{
			sag++; sol++;
			t = t + H1(sag,alt,ust) - H1(sol-1,alt,ust);
			res = MAX( res , t );
		}
		FOR(j,2,W)
		{
			alt--; ust--;
			t = t + H2(alt,sol,sag) - H2(ust+1,sol,sag);
			res = MAX( res , t );
		}
	}
	printf("%d\n",res);
}
int main()
{
	read();
	solve();
	return 0;
}
