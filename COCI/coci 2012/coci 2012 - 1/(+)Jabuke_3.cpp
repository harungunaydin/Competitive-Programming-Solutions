#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
void solve()
{
	pii p;
	int M,N,S,i,s=0,x;
	scanf("%d %d %d",&M,&N,&S);
	p.f=1;
	p.s=N;
	FOR(i,1,S)
	{
		scanf("%d",&x);
		if(x < p.f)
		{
			s+=p.f - x;
			p.s-= p.f - x;
			p.f=x;
		}
		if(x > p.s)
		{
			s+=x - p.s;
			p.f+=x - p.s;
			p.s=x;
		}
	}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;	
}
