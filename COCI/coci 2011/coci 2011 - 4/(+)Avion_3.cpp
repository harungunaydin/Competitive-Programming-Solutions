#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V;
void solve()
{
	string str;
	int a,i;
	bool flag=false;
	FOR(i,1,5)
	{
		cin >> str;
		if(str.find("FBI")!=-1)
			V.push_back(i);
	}
	if(V.empty()) printf("HE GOT AWAY!");
	a=V.size()-1;
	FOR(i,0,a)
	{
		printf("%d",V[i]);
		if(i!=a)
			printf(" ");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
