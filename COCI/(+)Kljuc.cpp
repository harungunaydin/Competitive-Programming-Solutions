#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
string str;
string bul(string temp,int k)
{
	int i,j,n;
	n = temp.size();
	FOR(i,1,n)
	{
		for(j = 0; j<=n/2; j++)
			if(j+i >= n || temp[j] != temp[j+i])
				break;
		if((j == n/2 && j+i >=n) ||j == n/2 + 1)
			FOR2(j,n)
				if(!((k+j)%i))
					return temp.substr(j,i);
	}
	return "";
}
void hallet(string a,string b,int k)
{
	string temp = "";
	int i;
	FOR2(i,a.size())
		temp+=char(a[i] - b[i] + (b[i] > a[i])*26) + 'a';
	string tmp = bul(temp , k);
	if(!tmp.empty())
	{
		while(tmp.size() < str.size()) tmp+=tmp;
		FOR2(i,str.size())
			printf("%c",str[i]-tmp[i] + (tmp[i] > str[i])*26 + 'a');
		printf("\n");
		exit(0);
	}
}
void solve()
{
	string str2;
	int i;
	cin >> str;
	cin >> str2;
	FOR2(i,str.size()-str2.size()+1)
		hallet(str.substr(i,str2.size()),str2,i);
}
int main()
{
	solve();
	return 0;
}
