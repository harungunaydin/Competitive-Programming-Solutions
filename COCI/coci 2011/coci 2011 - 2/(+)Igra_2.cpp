#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
vector <int> V[150];
bool used[MAXN+5];
void solve()
{
	vector <int> :: iterator it;
	string str,temp1="",temp2="";
	int a,i,j,k;
	bool flag;
	scanf("%d",&a);
	cin >> str;
	TFOR(i,a-1,0)
		V[str[i]].push_back(i);
	k = str.size()-1;
	while(1)
	{
		while(k>=0 && used[k]) k--;
		if(k == -1) break;
		temp2+=str[k];
		used[k] = true;
		V[str[k]].erase(V[str[k]].begin());
		flag = true;
		for(i='a'; i<='z' && flag; i++)
			for(it = V[i].begin(); it!=V[i].end(); ++it)
				if(!used[*it])
				{
					used[*it] = true;
					temp1+=str[*it];
					flag = false;
					V[i].erase(it);
					break;
				}
	}
	(temp1 < temp2) ? printf("DA\n") : printf("NE\n");
	cout << temp1 << endl;
}
int main()
{
	solve();
	return 0;
}
