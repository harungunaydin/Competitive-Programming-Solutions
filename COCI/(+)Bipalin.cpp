#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1000000
using namespace std;
vector < long long > V[15];
long long M,N,a;
long long A[MAXN+5],B[MAXN+5],us10[15];
void init()
{
	long long a,b,c,d,e;
	FOR2(a,10)
	{
		V[1].push_back(a);
		V[2].push_back(11*a);
		FOR2(b,10)
		{
			V[3].push_back(101*a+10*b);
			V[4].push_back(1001*a+110*b);
			FOR2(c,10)
			{
				V[5].push_back(10001*a+1010*b+100*c);
				V[6].push_back(100001*a+10010*b+1100*c);
				FOR2(d,10)
				{
					V[7].push_back(1000001*a+100010*b+11000*c+1000*d);
					V[8].push_back(10000001*a+1000010*b+100100*c+11000*d);
					FOR2(e,10)
					{
						V[9].push_back(100000001*a+10000010*b+1000100*c+101000*d+10000*e);
						V[10].push_back(1000000001*a+100000010*b+10000100*c+1001000*d+110000*e);
					}
				}
			}
		}
	}
}
void solve()
{
	long long i,res(0),t;
	scanf("%lld %lld",&N,&M);
	N>>=1;
	us10[0] = 1;
	FOR(i,1,12) us10[i] = us10[i-1] * 10;
	vector < long long > :: iterator it;
	for(it = V[N].begin(); it!=V[N].end(); ++it)
	{
			t = *it;
			A[t%M]++;
			t = (t%M)*(us10[N]%M);
			t%=M;
			if((*it)%10)
				B[t]++;
	}
	FOR(i,0,M)
		res+=A[i]*B[(M-i)%M];
	printf("%lld\n",res);
}
int main()
{
	init();
	solve();
	return 0;
}
