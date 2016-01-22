#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 50
using namespace std;
string S[MAXN+5];
int hesapla(char a,char b)
{
	if(a == 'S' && b == 'P') return 2;
	if(a == 'P' && b == 'R') return 2;
	if(a == 'R' && b == 'S') return 2;
	return a == b;
}
void solve()
{
	string str;
	int N,R,i,j,maxires(0),maxi,res(0),t;
	scanf("%d",&R);
	cin >> str;
	scanf("%d",&N);
	FOR(i,1,N)
		cin >> S[i];
	FOR2(i,R)
	{
		t = 0;
		FOR(j,1,N)
			t+=hesapla('R',S[j][i]);
		if(str[i] == 'R') res+=t;
		maxi = t;
		t = 0;
		FOR(j,1,N)
			t+=hesapla('P',S[j][i]);
		if(str[i] == 'P') res+=t;
		maxi = max( maxi , t);
		t = 0;
		FOR(j,1,N)
			t+=hesapla('S',S[j][i]);
		if(str[i] == 'S') res+=t;
		maxi = max( maxi , t);
		maxires+=maxi;
	}
	printf("%d\n%d\n",res,maxires);
}
int main()
{
	solve();
	return 0;
}
