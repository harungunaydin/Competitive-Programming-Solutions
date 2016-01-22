#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
long long C[300];
bool H[100],H2[300];
string str;
void hallet(char c)
{
	int i;
	FOR2(i,str.size())
		if(str[i] == c)
			H[i] = true;
}
void solve()
{
	memset( H , 0 , sizeof H );
	memset( H2 , 0 , sizeof H2 );

	cin >> str;

	long long res(0),s(1);
	int i;
	C[str[0]] = 1;
	hallet(str[0]);
	for(i = 1; i < str.size(); i++)
		if(!H[i])
		{
			C[str[i]] = (s == 1) ? 0 : s;
			s++;
			hallet(str[i]);
		}

	s = 0;

	FOR2(i,str.size())
		if(!H2[str[i]])
		{
			s++;
			H2[str[i]] = true;
		}
	if(s == 1) s = 2;
	FOR2(i,str.size())
		res = (res * s + C[ str[i] ] );
	printf("%lld\n" , res );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
