#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 250
using namespace std;
queue <char> Q;
string str[MAXN];
int B[MAXN];
bool hash[MAXN];
bool A[MAXN][MAXN];
string solve()
{
	string res;
	int N,i,j,k,syc,x;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str[i];
		FOR2(j,str[i].size())
			hash[str[i][j]] = true;
	}
	FOR(i,1,N-1)
	{
		k = 0;
		while(k<str[i].size() && k<str[i+1].size() && str[i][k] == str[i+1][k]) k++;
		if(k < str[i].size() && k < str[i+1].size())
		{
			if(A[str[i+1][k]][str[i][k]]) return "!";
			if(!A[str[i][k]][str[i+1][k]]) B[str[i+1][k]]++;
			A[str[i][k]][str[i+1][k]] = true;
		}
	}
	syc = 0;
	FOR(i,'a','z')
		if(!B[i] && hash[i])
		{
			if(++syc > 1) return "?";
			Q.push(i);
		}
	res.clear();
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();
		res+=x;
		syc = 0;
		FOR(i,'a','z')
			if(A[x][i] && !(--B[i]))
			{
				if(++syc > 1) return "?";
				Q.push(i);
			}
	}
	return res;
}
int main()
{
	cout << solve() << endl;
	return 0;
}
