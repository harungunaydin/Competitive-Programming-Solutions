#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
void solve()
{
	int a,i,s(0);
	FOR(i,1,10)
	{
		scanf("%d",&a);
		if(s + a >= 100)
		{
			if(s + a - 100 <= 100 - s)
				s += a;
			break;
		}
		s += a;
	}
	printf("%d\n" , s );
}
int main()
{
	solve();
	return 0;
}
