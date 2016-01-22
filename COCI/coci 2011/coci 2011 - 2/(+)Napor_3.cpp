#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define RAKAM(x) (x>='0' && x<='9')
using namespace std;
vector <string> V;
bool cmp(const string &a,const string &b)
{
	if(a.size()<b.size()) return 1;
	if(a.size()>b.size()) return 0;
	return a<b;
}
void solve()
{
	int N,i,j;
	vector <string> :: iterator it;
	string str,temp;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str;
		temp.clear();
		FOR2(j,str.size())
		{
			if(RAKAM(str[j])) temp+=str[j];
			else
			{
				while(temp.size()>1 && temp[0]=='0') temp.erase(temp.begin());
				V.push_back(temp);
				temp.clear();
			}
		}
		while(temp.size()>1 && temp[0]=='0') temp.erase(temp.begin());
		V.push_back(temp);
	}
	sort(V.begin(),V.end(),cmp);
	for(it=V.begin(); it!=V.end(); ++it)
		if((*it)[0])
		cout << *it << endl;
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
