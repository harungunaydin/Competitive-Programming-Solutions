#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V;
int D,N,sol,sag;
void read()
{
	int i,x,s1,s2;
	scanf("%d %d",&D,&N);
	V.push_back(0);
	FOR(i,1,N)
	{
		scanf("%d",&x);
		V.push_back(x);
	}
	V.push_back(D);
	scanf("%d",&s1);
	FOR(i,1,s1)
	{
		scanf("%d",&x);
		sol>?=x;
	}
	scanf("%d",&s2);
	FOR(i,1,s2)
	{
		scanf("%d",&x);
		sag>?=x;
	}
}
void solve()
{
	int i,mini=2000000000;
	for(i=0; i<V.size(); i++)
		mini<?= (sol+V[i]>? sag+D-V[i]) + ( V[i]>? D-V[i]);
	cout << mini << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
