#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
pii p[405];
int r[405];
double uzaklik(pii x,pii y)
{
	int a,b;
	a=abs(x.f-y.f);
	b=abs(x.s-y.s);
	return sqrt(a*a + b*b);
}
void solve()
{
	int N,i,j,s=0;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d %d",&p[i].f,&p[i].s,&r[i]);
	FOR(i,1,N)
	{
		s=0;
		FOR(j,1,N)
			if(i!=j && r[i]+r[j] > uzaklik(p[i],p[j]))
				s++;
		printf("%d\n",s);
	}
}
int main()
{
	solve();
	return 0;
}
