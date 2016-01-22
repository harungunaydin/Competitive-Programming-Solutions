#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100000
using namespace std;
FILE *in,*out;
char str[MAXN+5];
int solve()
{
	int ac(0),kapa(0),i,res(0),t,tac(0),tkapa(0);
	fscanf(in,"%s",str);
	t = strlen(str);
	if(str[t-1] == '(') return 1;
	FOR2(i,t)
	{
		tac+=(str[i] == '(');
		tkapa+=(str[i] == ')');
	}
	FOR2(i,t)
	{
		if(str[i] == '(')
		{
			if(tac - tkapa == 2 && ac - kapa >= 1)
			{
				if(ac - kapa == 1 && str[i+1] == ')') res--;
				res++;
			}
			ac++;
		}
		else
		{
			res+=(i && i != t - 1 && tkapa - tac == 2);
			kapa++;
		}
	}
	return res;
}
int main()
{
	in = fopen("typo.in","r");
	out = fopen("typo.out","w");
	fprintf(out,"%d\n",solve() );
	return 0;
}
