#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 50001
using namespace std;
class interval
{
	public:
		int a,b,c;
		interval() { a = b = 0; c = -1; }
		interval(int x,int y,int z) { a = x; b = y; c = z; }
}ST[16][4*MAXN];
inline interval make_interval(int a,int b,int c) { interval I(a,b,c); return I; }
int M,N,Q;
bool A[MAXN][16];
interval init(int pos,int s,int e,int k)
{
	if(s == e) return ST[k][pos] = make_interval(A[s][k],!A[s][k],-1);
	int m = (s + e) / 2;
	interval I1 = init(pos*2,s,m,k);
	interval I2 = init(pos*2+1,m+1,e,k);
	ST[k][pos].a = I1.a + I2.a;
	ST[k][pos].b = I1.b + I2.b;
	return ST[k][pos];
}
int update(int pos,int s,int e,int a,int b,int t,int k)
{
	if(a > e || b < s) return ST[k][pos].b;
	int m = ( s + e ) / 2;
	if(a <= s && e <= b)
	{
		ST[k][pos].c = t;
		return ST[k][pos].b = (t) ? ST[k][pos].a : e - s + 1 - ST[k][pos].a;
	}
	if(ST[k][pos].c != -1)
	{
		update(pos*2,s,m,s,m,ST[k][pos].c,k);
		update(pos*2+1,m+1,e,m+1,e,ST[k][pos].c,k);
		ST[k][pos].c = -1;
	}	
	return ST[k][pos].b = update(pos*2,s,m,a,b,t,k) + update(pos*2+1,m+1,e,a,b,t,k);
}
void solve()
{
	int i,j,s(0),t,x1,x2,y1,y2;
	char c;
	scanf("%d %d %d",&M,&N,&Q);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",&c);
			A[i][j] = c - '0';
		}
	FOR(i,1,N)
		init(1,1,M,i);
	FOR(i,1,Q)
	{
		scanf("%d %d %d %d %d",&x1,&x2,&y1,&y2,&t);
		FOR(j,y1,y2)
			update(1,1,M,x1,x2,t,j);
		s = 0;
		FOR(j,1,N) s += ST[j][1].b;
		printf("%d\n" , s );
	}
}
int main()
{
	solve();
	return 0;
}
