// O(N)
#include <iostream>
#define SAG(x,y) SAG[x][y]
#define SOL(x,y) SOL[x][y]
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 750
using namespace std;
int SAG(MAXN,100),SOL(MAXN,2);
void solve()
{
	string str;
	int N,i,res=0;
	cin >> str;
	str+=str;
	N = str.size();
	FOR(i,1,N)
	{
		if(str[i-1] == 'r')
		{
			SOL(i,0) = SOL(i-1,0) + 1;
			SOL(i,1) = 0;
		}
		else if(str[i-1] == 'b')
		{
			SOL(i,1) = SOL(i-1,1) + 1;
			SOL(i,0) = 0;
		}
		else if(str[i-1] == 'w')
		{
			SOL(i,0) = SOL(i-1,0) + 1;
			SOL(i,1) = SOL(i-1,1) + 1;
		}
	}
	TFOR(i,N,1)
	{
		if(str[i] == 'r')
		{
			SAG(i,0) = SAG(i+1,0) + 1;
			SAG(i,1) = 0;
		}
		else if(str[i] == 'b')
		{
			SAG(i,1) = SAG(i+1,1) + 1;
			SAG(i,0) = 0;
		}
		else if(str[i] == 'w')
		{
			SAG(i,0) = SAG(i+1,0) + 1;
			SAG(i,1) = SAG(i+1,1) + 1;
		}
	}
	FOR2(i,N)
		res = max(res,max(SOL(i,0),SOL(i,1)) + max(SAG(i,0),SAG(i,1)));
	res = min(N/2,res);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
