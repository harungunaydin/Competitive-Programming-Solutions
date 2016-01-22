#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 10000000
#define MAXN 1000
using namespace std;
string str;
int N,sum;
int A[MAXN][5005];
int DP[MAXN][5005];
inline int rec(int x,int s)
{
	if(s < 0) return INF;
	if(x == N + 1) return s ? INF : 0;
	if(DP[x][s]) return DP[x][s];
	register int i,k(0),k2(N+1),mini(INF),t;
	FOR(i,x,N)
	{
		k = k * 10 + str[i] - '0';
		if(!k && i != N && str[i+1] == '0') continue;
		if(k > sum) break;
		t = rec(i+1,s-k) + 1;
		if(t < mini)
		{
			k2 = i + 1;
			mini = t;
		}
	}
	A[x][s] = k2;
	return DP[x][s] = mini;
}
void solve()
{
	int i,k(1),m(0),mini,s(0),t,x(0);
	cin >> str;
	for(i=str.size()-1; str[i] != '='; i--,k*=10)
		sum+=(str[i]-'0')*k;
	N = i - 1;
	str.resize(i);
	rec(0,sum);
	string temp = str;
	s = sum;
	while(x <= N)
	{
		t = A[x][s];
		temp.insert(temp.begin()+t+m,'+');
		k = 1;
		for(i=t-1; i>=x; i--,k*=10)
			s-=(str[i]-'0')*k;
		m++;
		x = t;
	}
	temp[temp.size()-1] = '=';
	cout << temp << sum << endl;
}
int main()
{
	solve();
	return 0;
}
