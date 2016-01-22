#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
int h;
int hash[20000005];
string int_to_str(int x)
{
	string str = "";
	while(x)
	{
		str += x%10 + '0';
		x /= 10;
	}
	reverse(all(str));
	return str;
}
int hesapla(string str)
{
	int i,t(0);
	for(i = 0; i < str.size(); i++)
		t = t * 10 + str[i] - '0';
	return t;
}
string rotate(string str)
{
	str = str[str.size()-1] + str;
	str.resize(str.size()-1);
	return str;
}
int solve()
{
	string str;
	int A,B,i,j,k,s(0),t;

	scanf("%d %d",&A,&B);

	FOR(i,A,B)
	{
		h++;
		str = int_to_str(i);
		k = str.size();
		FOR2(j,k)
		{
			str = rotate(str);
			t = hesapla(str);
			if(i == t) break;
			if(hash[t] != h && i < t && t <= B) { hash[t] = h; s++; }
		}
	}
	return s;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
		printf("Case #%d: %d\n",i,solve());
	return 0;
}
