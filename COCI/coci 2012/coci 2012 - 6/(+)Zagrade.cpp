#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 305
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
vector < string > V;
pii P[MAXN];
int M,N,h;
int H[MAXN] , sta[MAXN];
char str[MAXN];
bool C[MAXN];
void rec(int x)
{
	if(x == M + 1)
	{
		h++;
		int i;
		bool flag = true;
		FOR(i,1,M)
			if(C[i])
			{
				H[ P[i].f ] = H[ P[i].s ] = h;
				flag = false;
			}

		if(flag) return;

		string tmp = "";

		FOR(i,1,N)
			if(H[i] != h)
				tmp += str[i];

		V.pb(tmp);
		return;
	}
	C[x] = false;
	rec(x+1);
	C[x] = true;
	rec(x+1);
}

void solve()
{
	int bas(0),i;
	scanf("%s" , str+1 );
	N = strlen(str+1);

	FOR(i,1,N)
		if(str[i] == '(')
			sta[bas++] = i;
		else if(str[i] == ')')
			P[++M] = make_pair( sta[--bas] , i );

	rec(1);

	sort( all(V) );
	unique( all(V) );
	
	vector < string > :: iterator it;
	for(it = V.begin(); it != V.end(); ++it)
		cout << *it << endl;

}
int main()
{
	solve();
	return 0;
}
