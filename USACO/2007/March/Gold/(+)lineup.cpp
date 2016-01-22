#include <iostream>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define MOD 10000000000007ll
#define MAXN 100001
using namespace std;
map < long long , int > mp;
int K,N;
long long B[32];
long long hash()
{
	long long t(0);
	int i;
	FOR(i,1,K)
		t = ( t * 12312312ll + B[i] ) % MOD;
	return t;
}
void solve()
{
	int a,i,j,k,mini,res(0);
	scanf("%d %d",&N,&K);
	mp[0] = 0;
	FOR(i,1,N)
	{
		scanf("%d",&a);
		mini = MAXN;
		FOR(j,1,K)
		{
			B[j] += (a&1);
			mini = MIN( mini , B[j] );
			a >>= 1;
		}
		FOR(j,1,K) B[j] -= mini;
		long long t = hash();
		if(mp.find(t) != mp.end()) res = max( res , i - mp[t]);
		else mp[t] = i;
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
