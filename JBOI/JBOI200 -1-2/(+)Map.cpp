#include <iostream>
#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define control(x) (x == 'n' || x == 's' || x == 'w' || x == 'e')
#define RAKAM(x) (x >= '0' && x <= '9')
using namespace std;
void solve()
{
	string str;
	int a,i,k,t,x(0),y(0);
	getline(cin,str);
	FOR2(i,str.size())
		if(control(str[i]))
		{
			k = 0;
			t = i;
			i++;
			while(RAKAM(str[i]))
			{
				k = k * 10 + str[i] - '0';
				i++;
			}
			i--;
			if(str[t] == 'n') y+=k;
			if(str[t] == 's') y-=k;
			if(str[t] == 'e') x+=k;
			if(str[t] == 'w') x-=k;
		}
	printf("%.2lf\n",sqrt( x*x + y*y ));
}
int main()
{
	solve();
	return 0;
}
