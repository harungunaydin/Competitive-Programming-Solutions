#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1500
using namespace std;
class point
{
	public:
		long long s,x,y;
		point() { s = x = y = 0; }
		point(long long a,long long b) { x = a; y = b; s = 0; }
		void dondur() { swap(x,y); y = - y; s++; }
}P[MAXN+5],T[MAXN+5];
point make_point(long long a,long long b)
{
	point p(a,b);
	return p;
}
long long N,S;
void kaydir(long long a,long long b)
{
	long long i;
	S = 0;
	FOR(i,1,N)
		if(P[i].x != a || P[i].y != b)
			T[++S] = make_point(P[i].x-a,P[i].y-b);
}
void tasi()
{
	long long i;
	FOR(i,1,N)
		if(T[i].x || T[i].y)
			while(T[i].x <= 0 || T[i].y < 0)
				T[i].dondur();
}
bool cmp(const point &a , const point &b)
{
	return a.y * b.x < a.x * b.y;
}
void solve()
{
	long long res(0);
	long long A[5];
	long long i,j,k;
	double m;
	scanf("%lld",&N);
	FOR(i,1,N)
		scanf("%lld %lld",&P[i].x,&P[i].y);
	FOR(i,1,N)
	{
		kaydir(P[i].x,P[i].y);
		tasi();
		sort(T+1,T+S+1,cmp);
		FOR(j,1,S)
		{
			k = j;
			fill(A,A+4,0);
			while(T[j].y * T[k].x == T[j].x * T[k].y && j<=S) A[T[j++].s]++;
			j--;
			res += A[0] * A[1] + A[1] * A[2] + A[2] * A[3] + A[3] * A[0];
		}
	}
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
