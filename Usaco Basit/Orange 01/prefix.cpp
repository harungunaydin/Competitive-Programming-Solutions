//SORU 326
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "prefix.in"
#define OUTPUT "prefix.out"
#define MAXN 20000
#define f first
#define s second
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
typedef pair <string,int> psi;
set <pair <int,string> > st;
psi p[MAXN+5];
int A[MAXN+5];
void solve()
{
	int N,i,j,maxi = 0,mini,u;
	string str="yok";
	in >> N;
	mini = N+1;
	FOR(i,1,N)
	{
		in >> p[i].f;
		p[i].s = i;
	}
	sort(p+1,p+N+1);
	FOR(i,1,N-1)
	{
		u = min(p[i].f.size(),p[i+1].f.size());
		j = 0;
		while(p[i].f[j] == p[i+1].f[j] && j<u) j++;
		maxi = max(maxi,j);
	}
	FOR(i,1,N-1)
	{
		u = min(p[i].f.size(),p[i+1].f.size());
		j = 0;
		while(p[i].f[j] == p[i+1].f[j] && j<u) j++;
		if(j == maxi)
		{ 
			st.insert(make_pair(p[i].s,p[i].f));
			st.insert(make_pair(p[i+1].s,p[i+1].f));
		}
	}
	str = st.begin()->s;
	out << str << endl;
	set < pair <int,string> > :: iterator it;
	for(it = st.begin(); it!=st.end(); ++it)
	{
		j = 0;
		u = min(str.size(),it->s.size());	
		while(str[j] == it->s[j]) j++;
		if(j == maxi)
		{
			out << it->s << endl;
			break;
		}
	}
}
int main()
{
	solve();
	return 0;
}
