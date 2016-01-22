#include <iostream>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 
using namespace std;
typedef pair < int , int > pii;
map < string , bool > mp;
void solve()
{
	mp.clear();
	string str , tmp;
	int M,N,i,j , res(0);
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
	{
		cin >> str;
		str += '/';
		tmp = "";
		for(j = 0; j < str.size(); j++)
		{
			if(j && str[j] == '/') mp[tmp] = true;
			tmp += str[j];
		}
	}
	FOR(i,1,N)
	{
		cin >> str;
		str += '/';
		tmp = "";
		for(j = 0; j < str.size(); j++)
		{
			if(j && str[j] == '/' && !mp[tmp])
			{
				res++;
				mp[tmp] = true;
			}
			tmp += str[j];
		}
	}
	printf("%d\n" , res );
}
int main()
{
	freopen("inp","r",stdin);
	freopen("out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: " , i);
		solve();
	}
	return 0;
}
