#include <iostream>
#include <set>
using namespace std;
set <string> st;
void kontrol(string str)
{
	int a=str.size()-1;
	if(str.find("@")==-1) return;
	if(str[0]=='.' || str[a]=='.' || str[0]=='@' || str[a]=='@') return;
	if(str.find("@.")!=-1 || str.find(".@")!=-1) return;
	st.insert(str);
}
void solve(string A,string B,int at,int nospam)
{
	if(at>1 || nospam>1) return;
	if(!A.size()) { kontrol(B); return; }
	if(A.substr(0,2)=="at") solve(A.substr(2),B+'@',at+1,nospam);
	if(A.substr(0,6)=="nospam") solve(A.substr(6),B,at,nospam+1);
	if(A.substr(0,8)=="anospamt") solve(A.substr(8),B+'@',at+1,nospam+1);
	solve(A.substr(1),B+A[0],at,nospam);
}
int main()
{
	string str;
	cin >> str;
	solve(str,"",0,0);
	for(set <string> :: iterator it=st.begin(); it!=st.end(); ++it)
		cout << *it << endl;
	return 0;
}
