#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int solve()
{
	int N,a,f,i,s,t;
	scanf("%d",&N);
	scanf("%d %d",&f,&s);
	a = s;
	FOR(i,3,N)
	{
		t = s;
		s = 2 * a - f;
		f = 2 * a - t;
		scanf("%d",&a);
		if(a < f) return 0;
		if(a < s) s = a;
	}
	return s - f + 1;
}
int main()
{
	printf("%d\n" , solve() );
	return 0;
}
