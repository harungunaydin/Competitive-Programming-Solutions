#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
vector <int> V;
void solve()
{
	string str;
	int i,a;
	bool flag = false;
	FOR(i,1,5)
	{
		cin >> str;
		if(str.find("FBI") != -1)
			V.push_back(i);
	}
	if(V.empty())
		printf("HE GOT AWAY!");
	a = V.size();
	FOR2(i,a)
	{
		printf("%d",V[i]);
		if(i != a-1) printf(" ");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
