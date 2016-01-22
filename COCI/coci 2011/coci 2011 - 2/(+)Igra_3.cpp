#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
vector <int> V[150];
int N;
string mirko,slavko,str;
bool hash[100005];
void solve()
{
	int a,i,k;
	char c,j;
	scanf("%d",&N);
	cin >> str;
	TFOR(i,N-1,0)
		V[str[i]].push_back(i);
	a=N/2;
	FOR(i,1,a)
	{
		k=str.size()-1;
		while(hash[k]) k--;
		c=str[k];
		str.resize(k);
		mirko+=c;
		V[c].erase(V[c].begin());
		FOR(j,'a','z')
			if(V[j].size())
			{
				slavko+=str[V[j][0]];
				hash[V[j][0]]=true;
				V[j].erase(V[j].begin());
				break;
			}
	}
	(slavko < mirko)? printf("DA\n") : printf("NE\n");
	cout << slavko << endl;
}
int main()
{
	solve();
	return 0;
}
