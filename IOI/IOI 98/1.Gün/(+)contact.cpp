#include <iostream>
#include <map>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 200000
#define all(x) x.begin(),x.end()
using namespace std;
map <string,int> mp;
vector <string> V[MAXN+5];
int s;
bool cmp(string a,string b)
{
	if(a.size() < b.size()) return 1;
	if(a.size() > b.size()) return 0;
	return a < b;
}
void print(string str)
{
	if(s + str.size() > 80) { s = 0; printf("\n"); }
	cout << str;
	s+=str.size();
}
void solve()
{
	string str="",temp;
	int A,B,N,i,j,maxi=0;
	char a;
	scanf("%d %d %d",&A,&B,&N);
	while(cin >> a) str+=a;
	FOR(i,A,B)
	if(i<=str.size())
	{
		temp = str.substr(0,i);
		mp[temp]++;
		for(j=i; j<str.size(); j++)
		{
			temp.erase(temp.begin());
			temp+=str[j];
			mp[temp]++;
		}
	}
	map <string,int> :: iterator it;
	for(it = mp.begin(); it!=mp.end(); ++it)
	{
		V[it->s].push_back(it->f);
		maxi = max(maxi,it->s);
	}
	for(i=maxi; i>=0 && N; i--)
		if(V[i].size())
		{
			N--;
			sort(all(V[i]),cmp);
			printf("%d\n",i);
			s = 0;
			FOR2(j,V[i].size())
			{
				print(V[i][j]);
				if(s + V[i][j].size() < 80 && j != V[i].size()-1)
					printf(" ");
			}
			printf("\n");
		}
}
int main()
{
	solve();
	return 0;
}
