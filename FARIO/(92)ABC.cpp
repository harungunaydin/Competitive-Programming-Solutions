#include <iostream>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
map < string , bool > mp;
void solve()
{
	string str;
	register int N,i,j,k,t;
	register char S[20];
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%s",S);
		str = S;
		mp[str] = true;
	}
	map < string , bool > :: iterator it = mp.end();
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%s",S);
		str = S;
		t = str.size();
		if(mp.find(str) != it) printf("%s\n",S);
		else
		{
			for(j = 0; j < t; j++)
				FOR(k,'a','z')
					if(S[j] != k)
					{
						str[j] = k;
						if(mp.find(str) != it)
						{
							S[j] = k;
							printf("%s\n",S);
							goto durak;
						}
						str[j] = S[j];
					}
			printf("?\n");
durak:;
		}
	}
}
int main()
{
	solve();
	return 0;
}
