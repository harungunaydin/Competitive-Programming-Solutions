#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
map < string , int > mp;
string f(string str)
{
	string tmp = "";
	int i , k = (int) str.size();
	for(i = 0; i < k; i += 2)
		tmp += str[i];

	i = k - 1 - (k&1);

	for(; i >= 0; i -= 2)
		tmp += str[i];

	return tmp;

}
string str,tmp;
void solve()
{
	int i,k,t;
	int X = read();
	cin >> str;

	tmp = str;
	
	mp[str] = 1;

	FOR(i,1,X)
	{
		str = f(str);
		if(mp[str])
		{
			k = i - ( mp[str] - 1 );

			t = X;

			if(t%k)
			{
				t /= k;
				t *= k;
				t += i%k;
			}
			else
				t = X - (k - i%k);
			break;

		}
		mp[str] = i+1;

	}
	if(i == X + 1) { cout << str << endl; return; }

	FOR(i,t,X-1)
		str = f(str);

	cout << str << endl;

}
int main()
{
	solve();
	return 0;
}
