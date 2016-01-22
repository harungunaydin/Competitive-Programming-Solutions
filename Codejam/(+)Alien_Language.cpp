#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 50005
using namespace std;
ifstream in("a.in");
ofstream out("a.out");
string S[MAXN];
int D,L,N;
int A[20][300];
void hallet(string str)
{
	memset( A , 0 , sizeof A );
	int i,k(0),s(0);
	for(i = 0; i < str.size(); i++)
	{
		if(str[i] == '(') { k++; s++; }
		else if(str[i] == ')') s--;
		else
		{
			if(s) A[k][str[i]] = true;
			else A[++k][str[i]] = true;
		}
	}
}
bool control(string str)
{
	int i;
	FOR(i,1,L)
		if(!A[i][str[i-1]])
			return false;
	return true;
}
void solve()
{
	string str;
	int i,j,s(0);
	cin >> L >> D >> N;
	FOR(i,1,D)
		cin >> S[i];
	FOR(i,1,N)
	{
		s = 0;
		cin >> str;
		hallet(str);
		FOR(j,1,D)
			s += control(S[j]);
		printf("Case #%d: %d\n",i,s);
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	solve();
	return 0;
}
