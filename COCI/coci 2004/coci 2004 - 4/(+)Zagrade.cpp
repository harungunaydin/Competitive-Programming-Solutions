#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
ifstream in("zagrade.in");
deque <char> qx;
deque <int> qs;
int N,home,end=-1,i;
void back(char c)
{
	home--;
	if((c=='[' && qx.back()==']') || (c=='(' && qx.back()==')') ) { printf("%d\n",qs.back()-home+1); qx.pop_back(); qs.pop_back(); return; }
	printf("0\n");
	qx.push_back(c); qs.push_back(home);
}
void front(char c,bool k)
{
	end++;
	if((c==']' && qx.front()=='[') || (c==')' && qx.front()=='(' )) { if(k) printf("%d\n",end-qs.front()+1); qx.pop_front(); qs.pop_front(); return; }
	if(k) printf("0\n");
	qx.push_front(c); qs.push_front(end);
}
void solve()
{
	string str;
	char b,c;
	cin >> str;
	FOR2(i,str.size())
		front(str[i],0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf(" %c %c",&b,&c);
		(b=='1')? front(c,1) : back(c);
	}
}
int main()
{
	solve();
	return 0;
}
