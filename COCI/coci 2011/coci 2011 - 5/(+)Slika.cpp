#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 1005
#define MAXQ 100005
#define MAXT 5000
using namespace std;
class paint
{
	public:
		int c,x1,x2,y1,y2;
		paint() { c = x1 = x2 = y1 = y2 = 0; }
		void read() { scanf("%d %d %d %d %d",&c,&x1,&y1,&x2,&y2); x1++; y1++; x2++; y2++; }
}P[MAXQ];

int K,M,N,T1,T2;
int L[MAXQ] , S[MAXQ];
int RES[MAXN][MAXN];

void boya(int x,int a,int b,int renk)
{
	for(int i = a; i <= b; i += 2)
		RES[x][i] = renk;
}

class KD
{
	public:
		char ST[MAXT];

		int update(int pos,int s,int e,int a,int b,int x,int renk,bool k)
		{
			
			if(a > e || b < s) return ST[pos];
			
			if(ST[pos] == 2) return 2;
			
			if(a <= s && e <= b && !ST[pos])
			{
				if(k) boya(x,s*2-1,e*2-1,renk);
				else boya(x,s*2,e*2,renk);
				return ST[pos] = 2;
			}
			
			int m = ( s + e ) >> 1;
			int sol = pos << 1;
			int sag = sol | 1;

			int k1 = update(sol,s,m,a,b,x,renk,k);
			int k2 = update(sag,m+1,e,a,b,x,renk,k);

			return ST[pos] = (k1 == k2) ? k1 : 1;
		}


}A[MAXN] , B[MAXN];


void paint(int renk,paint p)
{
	int a1,a2,b1,b2,i;
	bool k = (p.y1 & 1);

	a1 = p.y1/2+1; b1 = (p.y2+1)/2;
	a2 = (p.y1+1)/2; b2 = p.y2/2;

	FOR(i,p.x1,p.x2)
	{
		if(k) A[i].update(1,1,T1,a1,b1,i,renk,1);
		else  B[i].update(1,1,T2,a2,b2,i,renk,0);
		k = !k;
	}

}
void solve()
{
	int i,j,s(0);
	string str;
	scanf("%d %d %d",&N,&K,&M);

	FOR(i,1,N)
		FOR(j,1,N)
			RES[i][j] = 1;

	FOR(i,1,M)
	{
		cin >> str;
		if(str[0] == 'P')
			P[i].read();
		else if(str[0] == 'S')
			S[++s] = i;
		else
			scanf("%d" , L+i );

	}

	T1 = (N+1) >> 1;
	T2 = N >> 1;

	TFOR(i,M,1)
		if(P[i].c)
			paint(P[i].c,P[i]);
		else if(L[i])
			i = S[ L[i] ] ;

	FOR(i,1,N)
	{
		FOR(j,1,N)
			printf("%d " , RES[i][j] );
		if(i != N) printf("\n");
	}

}
int main()
{
	solve();
	return 0;
}
