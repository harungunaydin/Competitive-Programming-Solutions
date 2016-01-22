#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define all(x) x.begin(),x.end()
using namespace std;
vector <long long> UE,UK,KE,KK;
int N;
void solve()
{
	int N,i,j,s=0,x;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&x);
		if(x >= 0) UE.push_back(x);
		else KE.push_back(-x);
	}
	FOR(i,1,N)
	{
		scanf("%d",&x);
		if(x >=0) UK.push_back(x);
		else KK.push_back(-x);
	}
	sort( all(UE) );
	sort( all(KE) );
	sort( all(UK) );
	sort( all(KK) );
	i=j=0;
	while(i < UE.size() && j < KK.size())
		if(KK[j++] > UE[i])
		{
			s++;
			i++;
		}
	i=j=0;
	while(i < UK.size() && j < KE.size())
		if(KE[j++] > UK[i])
		{
			s++;
			i++;
		}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
