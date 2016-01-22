#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define mp(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define f first
#define s second
#define INF 100000000
#define MAXN 250
using namespace std;
typedef pair <int,int> pii;
typedef pair <pii,pii> pii4;
pii sat[MAXN+5],sut[MAXN+5];
pii satir[MAXN+5],sutun[MAXN+5];
int G,K,M,N;
int A[MAXN+5][MAXN+5],T[MAXN+5][MAXN+5];
int cevre(pii4 a)
{
	return (a.s.f - a.f.f + a.s.s - a.f.s + 2)<<1;
}
void calculate_something()
{
	int a,b,c,i,j,top=0;
	FOR(i,1,M)
		FOR(j,1,N)
			T[i][j] = T[i][j-1] + A[i][j];
	FOR(i,1,N)
		FOR(j,i,N)
		{
			a = b = 1;
			top = T[1][j] - T[1][i-1];
			while(b<=M)
			{
				if(top == K)
				{
				  sut[i].f <?= c = cevre(mp(a,i,b,j)); sut[j].s <?= c;
					sat[a].f <?= c; sat[b].s <?= c;
				}
				if(top >= K) 		 top-=T[a++][j] - T[a][i-1];
				else top+=T[++b][j] - T[b][i-1];
			}
		}
	TFOR(i,N,1)
		sutun[i].f = min(sutun[i+1].f,sut[i].f);
	TFOR(i,M,1)
		satir[i].f = min(satir[i+1].f,sat[i].f);
	FOR(i,1,N)
		sutun[i].s = min(sutun[i-1].s,sut[i].s);
	FOR(i,1,M)
		satir[i].s = min(satir[i-1].s,sat[i].s);
}
void read()
{
	int a,b,i;
	scanf("%d %d %d %d",&N,&M,&G,&K);
	FOR(i,1,G)
	{
		scanf("%d %d",&a,&b);
		A[M-b+1][a]++;
	}
}
void fill(pii a)
{
	fill(sut,sut+N+2,a);
	fill(sat,sat+M+2,a);
	fill(sutun,sutun+N+2,a);
	fill(satir,satir+M+2,a);
}
void solve()
{
	int i,res=INF;
	FOR(i,1,N)
		res<?=sutun[i].f + sutun[i-1].s;
	FOR(i,1,M)
		res<?=satir[i].f + satir[i-1].s;
	(res == INF) ? printf("NO\n") : printf("%d\n",res);
}
int main()
{
	read();
	fill(make_pair(INF,INF));
	calculate_something();
	solve();
	return 0;
}
