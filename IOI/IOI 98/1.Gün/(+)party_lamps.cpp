#include <iostream>
#include <queue>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(s,str) { qs.push(s); qstr.push(str); hash.insert(make_pair(s,str)); }
#define BAK(s,str)  { s = qs.front(); str = qstr.front(); qs.pop(); qstr.pop(); }
using namespace std;
queue <string> qstr;
queue <int> qs;
set <string> st;
set < pair <int , string> > hash;
int C,N;
int K[105];
char A[105];
bool control(string str)
{
	int i;
	FOR2(i,str.size())
		if(A[i]!=0 && A[i] != str[i])
			return 0;
	return 1;
}
void solve()
{
	string str;
	K['0'] = '1';
	K['1'] = '0';
	int a,b,c,d,i,s;
	scanf("%d %d",&N,&C);
	scanf("%d",&a);
	while(a != -1)
	{
		A[a-1] = '1';
		scanf("%d",&a);
	}
	scanf("%d",&a);
	while(a != -1)
	{
		A[a-1] = '0';
		scanf("%d",&a);
	}
	FOR(i,1,N) str+="1";
	EKLE(0,str);
	C%=16;
	while(!qs.empty())
	{
		BAK(s,str);
		if(s == C && control(str)) st.insert(str);
		if(s == C) continue;
		FOR2(i,str.size())
			str[i] = K[str[i]];
		
		if(hash.find(make_pair(s+1,str)) == hash.end())
			EKLE(s+1,str);
		
		FOR2(i,str.size())
			str[i] = K[str[i]];
		
		for(i=0; i<str.size(); i+=2)
			str[i] = K[str[i]];
			
		if(hash.find(make_pair(s+1,str)) == hash.end())
			EKLE(s+1,str);
		
		for(i=0; i<str.size(); i+=2)
			str[i] = K[str[i]];
		
		
		for(i=1; i<str.size(); i+=2)
			str[i] = K[str[i]];
			
		if(hash.find(make_pair(s+1,str)) == hash.end())	
			EKLE(s+1,str);
		
		for(i=1; i<str.size(); i+=2)
			str[i] = K[str[i]];
		
		for(i=0; i<str.size(); i+=3)
			str[i] = K[str[i]];
			
		if(hash.find(make_pair(s+1,str)) == hash.end())
			EKLE(s+1,str);
	}
}
int main()
{
	solve();
	if(st.size() == 0) st.insert("IMPOSSIBLE");
	set <string> :: iterator it;
	for(it = st.begin(); it!=st.end(); ++it)
		cout << *it << endl;
	return 0;
}
