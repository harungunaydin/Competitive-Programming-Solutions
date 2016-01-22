#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V[10005];
int K,N;
int DP[10005];
void read()
{
	int i,x,y;
	cin >> N >> K;
	FOR(i,1,K)
	{
		cin >> x >> y;
		V[x].push_back(y);
	}
}
void solve()
{
	int i,j,l,maxi;
	for(i=N; i; i--)
	{
		l=V[i].size();
		maxi=0;
		if(l)
		{
			for(j=0; j<l; j++)
				maxi=max(maxi,DP[i+V[i][j]]);
			DP[i]=maxi;
			continue;
		}
		DP[i]=DP[i+1]+1;
	}
	cout << DP[1] << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
