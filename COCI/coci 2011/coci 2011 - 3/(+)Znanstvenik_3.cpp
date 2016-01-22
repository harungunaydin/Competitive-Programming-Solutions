#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N;
map <string,bool> mp;
string str[1005];
bool kontrol(int x)
{
	int i;
	string temp;
	mp.clear();
	FOR(i,1,N)
	{
		temp=str[i].substr(x);
		if(mp[temp]) return 0;
		mp[temp]=true;
	}
	return 1;
}
void solve()
{
	int i,j;
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",&c);
			str[j]+=c;
		}
	for(i=M-1; i; i--)
		if(kontrol(i))
			break;
	printf("%d\n",i);
}
int main()
{
	solve();
	return 0;
}
