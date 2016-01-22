#include <iostream>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 4000
using namespace std;
long long A[MAXN+5];
void solve()
{
	long long N,a,i,j,k,res(0);
	char str[50];
	scanf("%lld",&N);
	FOR(i,1,N)
	{
		scanf("%s",str);
		a = strlen(str);
		k = 0;
		FOR2(j,a)
			k|=(1<<(str[j]-'0'+1));
		A[k]++;
	}
	FOR(i,0,2500)
		FOR(j,i+1,2500)
			if(i&j)
				res+=A[i]*A[j];
	FOR(i,0,2500)
		res+=(A[i]*(A[i]-1))/2;
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
