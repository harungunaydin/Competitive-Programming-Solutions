#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1000000
using namespace std;
char str[MAXN+5];
void solve()
{
	int N,a,b,i,k,k2,s1(0),s2(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf(" %c",str+i);
	i = N;
	while(i>0)
	{
		k = str[i];
		k2 = i;
		if(s1&1) k = (k == 'A') ? 'B' : 'A';
		while(i>0)
		{
			a = str[i];
			if(s1&1) a = (a == 'A') ? 'B' : 'A';
			if(a != k) break;
			i--;
		}
		if(k2-i > 1 && k == 'B')
			s1++;
		if(k2-i == 1 && k == 'B') s2++;
	}
	printf("%d\n",s1+s2);
}
int main()
{
	solve();
	return 0;
}
