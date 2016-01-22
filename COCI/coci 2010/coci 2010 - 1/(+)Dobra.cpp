#include <iostream>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
map < string , bool > mp;
string str;
long long N,res;
long long A[15],C[15],H[300];
bool B[300];
inline bool kontrol(string tmp)
{
	int i;
	if(mp[tmp]) return 1;
	mp[tmp] = true;
	FOR2(i,tmp.size()-2)
		if(B[tmp[i]] == B[tmp[i+1]] && B[tmp[i+1]] == B[tmp[i+2]])
				return 1;
	return 0;
}
void rec(long long x)
{
	if(x == N + 1)
	{
		string temp = str;
		long long a,b,c,i,s(0),t(1);
		FOR(i,1,N)
			if(H[i] != 1)
				temp[A[i]] = C[i] ? 'I' : 'R';
		if(kontrol(temp)) return;
		FOR(i,1,N)
		{
			if(H[i] == 1) continue;
			if(H[i] > 1)
				t*=C[i] ? 5 : 20;
			else
				t*=C[i] ? 5 : 21;
		}
		res+=t;
		return;
	}
	C[x] = 0;
	rec(x+1);
	C[x] = 1;
	rec(x+1);
}
void solve()
{
	long long i,vis;
	bool flag = true;
	B['A'] = B['E'] = B['I'] = B['O'] = B['U'] = true;
	cin >> str;
	FOR2(i,str.size())
		if(str[i] == '_')
			A[++N] = i;
		else if(str[i] == 'L')
			flag = false;
	vis = N + 1;
	if(flag)
		FOR(i,1,N)
		{
			mp.clear();
			string temp = str;
			str[A[i]] = 'L';
			H[i] = 1;
			rec(1);
			H[i] = vis;
			str = temp;
		}
	else
		rec(1);
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
