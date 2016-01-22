#include <iostream>
#include <set>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(s,str) { qs.push(s); qstr.push(str); st.insert(str); }
#define BAK(s,str)  { s = qs.front(); str = qstr.front(); qs.pop(); qstr.pop(); }
using namespace std;
set <string> st;
queue <string> qstr;
queue <int> qs;
int N;
bool control(string str)
{
	int i,s(0);
	FOR2(i,2*N)
	{
		if(str[i] == 'B') return 0;
		if(str[i] == 'A' && ++s == N-1) return 1;
	}
	return 1;
}
void solve()
{
	string str="",temp;
	int a,i,s;
	char c;
	scanf("%d",&N);
	FOR2(i,2*N)
	{
		cin >> c;
		str+=c;
	}
	EKLE(0,str);
	while(!qs.empty())
	{
		BAK(s,str);
		a = str.find('O');
		if(control(str)) { printf("%d\n",s); return; }
		for(i=0; i<str.size()-1; i++)
			if(i!=a && i!=a+1 && i+1!=a)
			{
				swap(str[i],str[a]); swap(str[i+1],str[a+1]);
				if(st.find(str) == st.end())
					EKLE((s+1),str);
				swap(str[i],str[a]); swap(str[i+1],str[a+1]);
			}
	}
	printf("IMPOSSIBLE\n");
}
int main()
{
	solve();
	return 0;
}
