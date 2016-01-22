#include <iostream>
#include <map>
#include <vector>
#include <conio.h>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef pair <int,int> pii;
map < pii , bool > hash;
vector <int> V[50005],yol,result;
int M,N,mini=INT_MAX;
bool hash2[50005];
void read()
{
	int i,x,y;
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
	{
		scanf("%d %d",&x,&y);
		V[x].push_back(y);
		V[y].push_back(x);
	}
}
bool kontrol()
{
	int i;
	FOR(i,1,N)
		if(!(V[i].size() & 1))
			return 0;
	return 1;
}
void rec(int x)
{
	if(kontrol())
	{
		if(yol.size() < mini)
		{
			mini = yol.size();
			result = yol;
		}
		return;
	}
	if(x > N) return;
	int y;
	if(!(V[x].size() & 1))
	{
		vector <int> :: iterator it,it2,it3;
		for(it=V[x].begin(); it!=V[x].end(); ++it)
		{
			if(!hash[mp(x,*it)])
			{
				y = (*it);
				V[x].erase(it);
				hash[mp(x,y)] = true;
				hash[mp(y,x)] = true;
				yol.push_back(x);
				for(it2=V[y].begin(); it2!=V[y].end(); ++it2)
					if(*it2 == x)
					{
						V[y].erase(it2);
						it3 = it2;
						break;
					}
				rec(x+1);
				yol.pop_back();
				V[y].insert(it3,x);
				V[x].insert(it,y);
			}
		}
	}
	else
		rec(x+1);
}
void solve()
{
	vector < int > :: iterator it;
	int i;
	rec(1);
	if(result.size())
	{
		for(it=result.begin(); it!=result.end(); ++it)
			hash2[*it]=true;
		result.clear();
		FOR(i,1,N)
			if(!hash2[i])
				result.push_back(i);
		printf("%d\n",result.size());
		for(it=result.begin(); it!=result.end(); ++it)
			printf("%d\n",*it);
				
	}
	else
		printf("-1\n");
}
int main()
{
	read();
	solve();
	return 0;
}
