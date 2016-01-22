#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define BUYUK(x) (x>='A' && x<='Z')
#define MAXN 10000
using namespace std;
class nop
{
	public:
		char a;
		int k;
}A[MAXN+5];
void solve()
{
	string str;
	int i,j,res(0),t;
	cin >> str;
	FOR2(i,str.size())
	{
		A[i].a = str[i];
		A[i].k = i;
	}
	FOR2(i,str.size())
		if(BUYUK(str[i]) && A[i].k%4)
		{
			t = 4 - A[i].k%4;
			res+=t;
			for(j=i; j<str.size(); j++)
				A[j].k+=t;
		}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
