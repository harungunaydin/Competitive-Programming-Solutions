#include <iostream>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
set <string> A,son;
int mini=100000,N;
void izracunaj(set <string> :: iterator it,set <string> st)
{
	if(st.size()>=mini) return;
	if(st.size() > 5) return;
	if(it==A.end()) { if(st.size()<mini) { mini=st.size(); son=st; } return ; }
	string s=*it;
	it++;
	int a=s.size()-2;
	string str,str2;
	for(int i=3; i<a; i++)
	{
		set <string> st2;
		st2=st;
		str=s.substr(0,i);
		str2=s.substr(i);
		if(str.size()>8 || str2.size()>8) continue;
		if(str==str2) continue;
		st2.insert(str);
		st2.insert(str2);
		izracunaj(it,st2);
	}
}
void solve()
{
	int i;
	set <string> st;
	st.clear();
	scanf("%d",&N);
	FOR(i,1,N)
	{
		string str;
		cin >> str;
		A.insert(str);
	}
	izracunaj(A.begin(),st);
	cout << mini << endl;
	for(set <string> :: iterator it=son.begin(); it!=son.end(); ++it)
		cout << *it << endl;
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
