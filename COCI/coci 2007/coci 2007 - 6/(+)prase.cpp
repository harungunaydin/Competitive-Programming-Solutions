#include <cstdio>
#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
map < string , int > mp;
int A[300];
void solve()
{
	string str;
	int N,a,i,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str;
		mp[str]++;

		res += (mp[str] > i - mp[str] + 1);

	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
