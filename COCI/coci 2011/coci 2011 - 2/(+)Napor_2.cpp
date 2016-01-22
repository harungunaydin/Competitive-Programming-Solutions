#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define RAKAM(x) (x>='0' && x<='9')
using namespace std;
vector <string> V;
bool cmp(const string &a,const string &b)
{
	if(a.size() < b.size()) return 1;
	if(a.size() > b.size()) return 0;
	return a < b;
}
void solve()
{
	string str,temp;
	int N,c,i,j,k,s;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str;
		j = 0;
		while(j < str.size())
		{
			c = 1;
			temp.clear();
			while(RAKAM(str[j]) && j < str.size())
				temp+=str[j++];
			while((*temp.begin()) == '0' && temp.size())
			{
				if(temp == "0") break;
				temp.erase(temp.begin());
			}
			if(temp.size())
			V.push_back(temp);
			j++;
		}
	}
	sort(all(V),cmp);
	vector <string> :: iterator it;
	for(it = V.begin(); it!=V.end(); ++it)
		cout << *it << endl;
}
int main()
{
	solve();
	return 0;
}
