#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	int grup(1),i,j,t(0);
	string str;
	cin >> str;
	FOR2(i,str.size()-1)
	{
		if(str[i] == ':' && str[i+1] == ':') { grup++; i++; continue; }
		if(str[i] == ':') grup++;
	}
	FOR2(i,str.size()-1)
	{
		if(str[i] == ':' && str[i+1] == ':')
		{
			while(grup<=7)
			{
				str.insert(i+2,"0000:");
				grup++;
			}
			str.erase(str.begin()+i);
			str.erase(str.begin()+i);
			str.insert(i,":");
			break;
		}
	}
	str.insert(0,":");
	str+=":";
	string temp = str,tmp;
	int s(0);
	FOR2(i,str.size())
	{
		if(str[i] == ':')
		{
			for(j=i+1; ; j++)
				if(str[j] == ':')
					break;
			t = j - i - 1;
			if(t == 4) continue;
			tmp = "";
			FOR2(j,4-t)
				tmp+="0";
			temp.insert(s+i+1,tmp);
			s+=4-t;
		}
	}
	temp.erase(temp.begin());
	temp.erase(temp.end()-1);
	cout << temp << endl;
}
int main()
{
	solve();
	return 0;
}
