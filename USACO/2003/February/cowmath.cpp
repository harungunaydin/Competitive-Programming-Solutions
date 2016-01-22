//SORU 367
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "cowmath.in"
#define OUTPUT "cowmath.out"
#define MAXN 25
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
long long res = 1;
int N;
long long A[MAXN+5][MAXN+5];
bool visited[MAXN+5];
long long gcd(long long a,long long b)
{
	return (!b) ? a : gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return (a/gcd(a,b))*b;
}
void rec(int x,long long ebob,int d)
{
	cout << x << " " << ebob << " " << d << endl; getchar();
	if(x == 2) { res = lcm(res,ebob); return; }
	int i;
	FOR(i,1,N)
		if(!visited[i] && A[x][i])
		{
			visited[i] = true;
			rec(i,gcd(ebob,A[x][i]),d+1);
			visited[i] = false;
		}
}
void solve()
{
	int i,j;
	cin >> N;
	FOR(i,1,N)
		FOR(j,1,N)
			cin >> A[i][j];
	visited[1] = true;
	FOR(i,2,N)
		if(A[1][i])
		{
			visited[i] = true;
			rec(i,A[1][i],1);
			visited[i] = false;
		}
	cout << res << endl;
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
