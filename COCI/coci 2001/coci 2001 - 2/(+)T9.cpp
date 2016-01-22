#include <iostream>
#include <map>
using namespace std;
int M;
string harf[8]={"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
map <string,string> mp;
map <string,string> :: iterator it;
map <string,bool> hash;
string find(string str)
{
	string temp;
	temp.clear();
	for(int i=0; i<str.size(); i++)
			for(int j=0; j<8; j++)
			{
				if(harf[j].find(str[i])!=-1)
				{
					temp+=j+'0'+2;
					break;
				}
			}
	return temp;
}
void read()
{
	string temp,str;
	cin >> M;
	for(int i=0; i<M; i++)
	{
		cin >> str;
		temp=find(str);
		if(!hash[temp])
			mp[temp]=str;
		hash[temp]=1;
	}
}
void solve()
{
	int N;
	char c;
	string temp;
	cin >> N;
	temp.clear();
	for(int i=0; i<N; i++)
	{
		cin >> c;
		if(i==N-1) temp+=c;
		if(c=='1' || i==N-1)
		{
			bool flag=true;
			for(it=mp.begin(); it!=mp.end(); ++it)
				if(it->first==temp)
				{
					cout << it->second;
					flag=false;
					break;
				}
			if(flag)
				for(int j=0; j<temp.size(); j++)
					cout << "*";
			temp.clear();
			cout << " ";
			continue;
		}
		temp+=c;
	}
	cout << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
