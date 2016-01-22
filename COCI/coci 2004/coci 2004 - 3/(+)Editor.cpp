#include <iostream>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
stack <int> l,r;
void solve()
{
	int i,N;
	char c;
	string str;
	cin >> str;
	FOR2(i,str.size())
		l.push(str[i]);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf(" %c",&c);
		if(c=='L' && !l.empty())
		{
			r.push(l.top());
			l.pop();
		}
		if(c=='D' && !r.empty())
		{
			l.push(r.top());
			r.pop();
		}
		if(c=='B' && !l.empty())
			l.pop();
		if(c=='P')
		{
			scanf(" %c",&c);
			l.push(c);
		}
	}
	str.clear();
	while(!l.empty()) { str+=l.top(); l.pop(); }
	reverse(all(str));
	cout << str;
	while(!r.empty()) { cout << (char)r.top(); r.pop(); }
}
int main()
{
	solve();
	cout << endl;
	return 0;
}
