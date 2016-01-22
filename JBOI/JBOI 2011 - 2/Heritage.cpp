#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define EKLE(str,s) { qs.push(s); qstr.push(str); mp[str] = true; }
#define BAK(str,s) {  s = qs.front(); str = qstr.front(); qs.pop(); qstr.pop(); }
using namespace std;
map < string , bool > mp;
queue < string > qstr;
queue < int > qs;
int N,bs,ss;
bool control(string str)
{
	int i;
	FOR2(i,bs)
		if(str[i] != '1')
			return 0;
	TFOR(i,N-1,N-ss)
		if(str[i] != '2')
			return 0;
	return 1;
}
int solve()
{
	string str = "",temp;
	int i,s;
	char c;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf(" %c",&c);
		bs+=(c == '1');
		ss+=(c == '2');
		str+=c;
	}
	EKLE(str,0);
	while(!qs.empty())
	{
		BAK(str,s);
		if(control(str)) return s;
		FOR2(i,N)
			if(str[i] == '2')
			{
				if(i < N-1 && str[i+1] == '0')
				{
					str[i] = '0';
					str[i+1] = '2';
					if(!mp[str]) EKLE(str,s+1);
					str[i] = '2';
					str[i+1] = '0';
				}
				if(i < N-2 && str[i+1] != '0' && str[i+2] == '0')
				{
					str[i] = '0';
					str[i+2] = '2';
					if(!mp[str]) EKLE(str,s+1);
					str[i] = '2';
					str[i+2] = '0';
				}
			}
			else if(str[i] == '1')
			{
				if(i > 0 && str[i-1] == '0')
				{
					str[i] = '0';
					str[i-1] = '1';
					if(!mp[str]) EKLE(str,s+1);
					str[i] = '1';
					str[i-1] = '0';
				}
				if(i > 1 && str[i-1] != '0' && str[i-2] == '0')
				{
					str[i] = '0';
					str[i-2] = '1';
					if(!mp[str]) EKLE(str,s+1);
					str[i] = '1';
					str[i-2] = '0';
				}
			}
	}
	return -1;
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
