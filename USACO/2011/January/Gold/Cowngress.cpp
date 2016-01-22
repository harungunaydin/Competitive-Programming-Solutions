#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
using namespace std;
typedef pair <int,bool> pib;
vector < pib > V[1005];
vector <int> V2;
vector <int> :: iterator it;
vector < pib > :: iterator it2;
int M,N,s;
bool hash[4005];
void read()
{
	int i,x;
	char c;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d",&x); scanf(" %c",&c);
		V[x].push_back(mp(i,c == 'Y' ));
		scanf("%d",&x); scanf(" %c",&c);
		V[x].push_back(mp(i,c == 'Y'));
	}
}
void solve(int x,string str)
{
	if(s == M)
	{
		int i;
		FOR(i,str.size() + 1,N) str+='?';
		cout << str << endl;
		exit(0);
	}
	if(x == N+1) return;
	int i;	
	if(!V[x].size()) { solve(x+1,str+"?"); return; }
	V2.clear();
	for(it2=V[x].begin(); it2!=V[x].end(); ++it2)
		if(it2->s == 1 && !hash[it2->f])
		{
			V2.push_back(it2->f);
			s++;
			hash[it2->f]=true;
		}
	solve(x+1,str+"Y");
	for(it=V2.begin(); it!=V2.end(); ++it,s--)
		hash[*it]=false;
	V2.clear();
	for(it2=V[x].begin(); it2!=V[x].end(); ++it2)
		if(it2->s == 0 && !hash[it2->f])
		{
			V2.push_back(it2->f);
			s++;
			hash[it2->f]=true;
		}
	solve(x+1,str+"N");
	for(it=V2.begin(); it!=V2.end(); ++it,s--)
		hash[*it]=false;
}
int main()
{
	read();
	solve(1,"");
	printf("IMPOSSIBLE\n");
	return 0;
}
