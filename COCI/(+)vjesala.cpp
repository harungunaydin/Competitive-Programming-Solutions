#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 10000000
#define MAXN 100
using namespace std;
int N;
int D[250][250];
char cur('A');
char A[MAXN+5],B[MAXN+5];
bool H[250];
int rec(char cur,int s)
{
	int i,mini(INF),res(INF);
	char k,k2(0);
	set <int> st;
	FOR(i,1,N)
		if(!H[A[i]])
			mini = min( mini , D[cur][A[i]] );
	if(mini == INF) return 0;
	FOR(i,1,N)
		if(!H[A[i]] && D[cur][A[i]] == mini)
			st.insert(A[i]);
	set <int> :: iterator it;
	for(it = st.begin(); it != st.end(); ++it)
	{
		H[*it] = true;
		B[s] = *it;
		res = min(res , rec(*it,s+1) + mini);
		H[*it] = false;
	}
	return res;
}
void solve()
{
	int i,j,mini(INF),k,k2(0),s(0);
	string str;
	getline(cin,str);
	N = str.size();
	FOR2(i,str.size())
		A[i+1] = str[i];
	FOR(i,'A','Z')
		FOR(j,i,'Z')
			D[i][j] = D[j][i] =  min( j-i , i-j+26 );
	H[' '] = true;
	FOR(i,1,N)
		if(!H[A[i]])
		{
			H[A[i]] = true;
			s++;
		}
	fill(H,H+'a',0);
	H[' '] = true;
	printf("%d\n",rec('A',1) + s);
	FOR(i,1,s)
		printf("%c",B[i]);
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
