#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 50005
using namespace std;
vector < int > V;
string str;
long long A,B,X;
bool H[15];
void solve1()
{
	long long i,k,res(0);
	cin >> str;
	for(i = 0; i < (int) str.size(); i++)
		H[ str[i] - '0' ] = true;
	A = (A/X) * X + (X * !!(A%X) );
	for(i = A; i <= B; i += X)
	{
		k = i;
		while(k)
		{
			if(!H[k%10]) break;
			k /= 10;
		}
		res += !k;
	}

	printf("%lld\n" , res );

}
long long DP[14][MAXN][2][2];
long long dp(int x,int mod,bool k1,bool k2)
{
	long long &ret = DP[x][mod][k1][k2];
	if(ret != -1) return ret;

	if(x == (int) V.size() ) return !mod;

	ret = 0;

	if(!H[0] && !k2) ret += dp(x+1,0,0,0);

	int i;
	if(k1)
		for(i = 0; i <= V[x]; i++)
			if(H[i])
				ret += dp(x+1, (mod*10+i)%X , (i==V[x]) , 1 );

	if(!k1)
		for(i = 0; i < 10; i++)
			if(H[i])
				ret += dp( x+1 , (mod*10+i)%X , 0 , k2|i );

	return ret;

}
long long f(long long x)
{
	memset( DP , -1 , sizeof DP );
	long long tmp = x;
	V.clear();
	while(tmp)
	{
		V.push_back(tmp%10);
		tmp /= 10;
	}

	reverse( all(V) );

	return dp(0,0,1,0);

}
void solve2()
{
	cin >> str;
	for(int i = 0; i < (int) str.size(); i++)
		H[ str[i] - '0' ] = true;

	printf("%lld\n" , f(B) - f(A-1) );
}
int main()
{
	scanf("%lld %lld %lld",&X,&A,&B);
	(X > 50000) ? solve1() : solve2();
	return 0;
}
