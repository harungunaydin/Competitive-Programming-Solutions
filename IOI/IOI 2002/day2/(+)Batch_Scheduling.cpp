#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 10005
using namespace std;
typedef pair < long long , long long > pll;
inline double inter_x(pll l1 , pll l2 ) { return (double) (l1.s - l2.s) / (l2.f - l1.f); }
pll sta[MAXN];
int K;
long long F[MAXN] , T[MAXN] , TF[MAXN] , TT[MAXN];
void trick(long long m,long long n)
{
	pll l = make_pair(m,n);
	while(K > 1 && inter_x(l,sta[K-2]) < inter_x(sta[K-1],sta[K-2])) K--;
	sta[K++] = make_pair(m,n);
}
int BS(int bas,int son,int x)
{
	int orta = (bas + son) / 2;
	if(orta == K - 1) return orta;
	if(!orta) return x < inter_x(sta[0],sta[1]) ? 0 : 1;
	double x1 = inter_x(sta[orta-1],sta[orta]);
	double x2 = inter_x(sta[orta],sta[orta+1]);
	if(x1 <= x && x <= x2) return orta;
	return (x < x1) ? BS(bas,orta-1,x) : BS(orta+1,son,x);
}
void solve()
{
	long long S,t;
	int N,i,j;
	scanf("%d %lld",&N,&S);
	FOR(i,1,N)
	{
		scanf("%lld %lld",T+i,F+i);
		TT[i] = TT[i-1] + T[i];
	}
	TFOR(i,N,1)
		TF[i] = TF[i+1] + F[i];

	//CONVEX_HULL_TRICK
	TFOR(i,N,1)
	{
		if(i == N) { trick(TT[N],0); continue; }
		t = BS(0,K-1,TF[i]);
		t = sta[t].f * TF[i] + sta[t].s + ( S - TT[i-1] ) * TF[i];
		trick(TT[i-1],t);
		
	}
	printf("%lld\n" , t );
}
int main()
{
	solve();
	return 0;
}
