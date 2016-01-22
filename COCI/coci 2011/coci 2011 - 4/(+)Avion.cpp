#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
void solve()
{
	string str;
	int i;
	bool flag = true;
	FOR(i,1,5)
	{
		cin >> str;
		if(str.find("FBI") != -1)
		{
			printf("%d " , i );
			flag = false;
		}
	}
	if(flag) printf("HE GOT AWAY!\n");
}
int main()
{
	solve();
	return 0;
}
