#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,s,str) { qx.push(x); qs.push(s); qstr.push(str); }
#define BAK(x,s,str) { x=qx.front(); s=qs.front(); str=qstr.front(); qx.pop(); qs.pop(); qstr.pop(); }
using namespace std;
queue <int> qx,qs;
queue <string> qstr;
vector <int> V[1005];
map < pair<string,int>,bool > hash;
bool A[105][105];
string str;
int a,b,N,S;
void degis(int x)
{
	for(vector <int> :: iterator it=V[x].begin(); it!=V[x].end(); ++it)
		str[*it]=(str[*it]=='0')? '1' : '0';
}
void read()
{
	int i,j,s,x;
	char c;
	cin >> N >> S;
	str+='0';
	FOR(i,1,N)
	{
		cin >> c >> s;
		str+=c;
		FOR(j,1,s)
		{
			cin >> x;
			A[i][x]=true;
		}
	}
	FOR(i,1,S)
	{
		cin >> s;
		FOR(j,1,s)
		{
			cin >> x;
			V[i].push_back(x);
		}
	}
	cin >> a >> b;
}
int solve()
{
	int c,i,x,s;
	pair <string,int> p;
	EKLE(a,0,str);
	while(!qx.empty())
	{
		BAK(x,s,str);
		if(x==b) return s;
		p=make_pair(str,x);
		if(hash[p]) continue;
		hash[p]=true;
		if(x<=S)
		{
			degis(x);
			EKLE(x,s,str);	
		}
		FOR(i,1,N)
			if(A[x][i] && str[i]=='0')
				EKLE(i,s+1,str);
	}
}
int main()
{
	read();
	cout << solve() << endl;
	return 0;
}
