#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 105
#define MAXK 300
using namespace std;
queue < char > Q;
string str[MAXN];
int K,N;
int B[MAXK];
bool H[MAXK];
bool A[MAXK][MAXK];
string solve()
{
	int a,b,i,j,k;
	char x;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str[i];
		for(j = 0; j < (int) str[i].size(); j++)
			if(!H[ str[i][j] ])
				H[ str[i][j] ] = true;
	}

	FOR(i,1,N)
	{
		FOR(j,i+1,N)
		{
			a = (int) str[i].size();
			b = (int) str[j].size();

			k = 0;
			while(k < a && k < b && str[i][k] == str[j][k]) k++;
	
			if(k < a && k < b && !A[ str[i][k] ][ str[j][k] ])
			{
				A[ str[i][k] ][ str[j][k] ] = true;
				B[ str[j][k] ]++;
			}
		}
	}

	FOR(i,'a','z')
		if(H[i] && !B[i])
			Q.push(i);

	bool flag = false;

	string res = "";

	while(!Q.empty())
	{
		x = Q.front(); Q.pop();

		if(!Q.empty()) flag = true;

		res += x;

		FOR(i,'a','z')
			if(A[x][i] && !(--B[i]))
				Q.push(i);

	}

	FOR(i,'a','z')
		if(H[i])
			K++;

	if( (int) res.size() < K ) return "!";

	if(flag) return "?";

	return res;

}
int main()
{
	cout << solve() << endl;
	return 0;
}
