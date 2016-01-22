#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void solve()
{
	string str;
	cin >> str;
	int i,res(0);
	FOR2(i,str.size())
	{
		if(i+1 < str.size() && str[i] == 'c' && str[i+1] == '=') i++;
		if(i+1 < str.size() && str[i] == 'c' && str[i+1] == '-') i++;
		if(i+1 < str.size() && str[i] == 'd' && str[i+1] == '-') i++;
		if(i+1 < str.size() && str[i] == 'l' && str[i+1] == 'j') i++;
		if(i+1 < str.size() && str[i] == 'n' && str[i+1] == 'j') i++;
		if(i+1 < str.size() && str[i] == 's' && str[i+1] == '=') i++;
		if(i+1 < str.size() && str[i] == 'z' && str[i+1] == '=') i++;
		if(i+2 < str.size() && str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') i+=2;
		res++;
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
