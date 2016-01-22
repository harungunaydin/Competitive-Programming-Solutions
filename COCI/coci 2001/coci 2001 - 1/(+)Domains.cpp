#include <iostream>
#include <map>
using namespace std;
map <string,int> mp;
map <string,int> :: iterator it2;
string :: iterator it;
int find2(string str)
{
	for(int i=str.size()-1; i+1; i--)
		if(str[i]=='.')
			return i;
	return -1;
}
void solve()
{
	int a,i=0,N,maxi=0;
	cin >> N;
	string str;
	for(; i<N; i++)
	{
		cin >> str;
		a=str.find("http://");
		if(a!=-1)
			str=str.substr(a+7);
		a=str.find('/');
		if(a!=-1)
			str=str.substr(0,a);
		a=find2(str);
		if(a!=-1)
			str=str.substr(a+1);
		mp[str]++;
	}
	for(it2=mp.begin(); it2!=mp.end(); ++it2)
		if(it2->second>maxi) maxi=it2->second;
	cout << maxi << endl;
	for(it2=mp.begin(); it2!=mp.end(); ++it2)
		if(it2->second==maxi) cout << it2->first << " ";
}
int main()
{
	solve();
	return 0;
}
