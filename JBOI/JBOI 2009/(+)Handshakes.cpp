#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100000
using namespace std;
char A[MAXN+5];
void solve()
{
	long long a,b,i,s(0),s2(0),t;
	scanf("%s",A);
	t = strlen(A);
	FOR2(i,t)
		if(A[i] == 'R')
			break;
	a = i;
	TFOR(i,t-1,0)
		if(A[i] == 'L')
			break;
	b = i;
	FOR(i,a,b-1)
	{
		if(A[i] == 'L') s++;
		if(A[i] == 'R') { s = (s > 0) ? s-1 : 0; s2++; }
	}
	printf("%lld ",s + s2);
	s = s2 = 0;
	FOR(i,0,b)
		(A[i] == 'R') ? s++ : s2+=s;
	printf("%lld\n",s2);
}
int main()
{
	solve();
	return 0;
}
