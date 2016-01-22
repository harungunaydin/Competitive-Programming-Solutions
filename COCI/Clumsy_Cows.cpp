#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
using namespace std;
char A[MAXN+5];
void solve()
{
	int ac(0),i,kapa(0),res(0),t;
	scanf("%s",A);
	t = strlen(A);
	FOR2(i,t)
	{
		ac+=(A[i] == '(');
		kapa+=(A[i] == ')');
		if(ac - kapa == -1)
		{
			ac++;
			kapa--;
			res++;
		}
	}
	printf("%d\n",res + (ac-kapa)/2 );
}
int main()
{
	solve();
	return 0;
}
