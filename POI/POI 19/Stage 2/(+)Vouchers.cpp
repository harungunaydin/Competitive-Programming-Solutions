#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 1000000
using namespace std;
vector < long long > V;
int N;
int B[MAXN+5];
bool C[MAXN+5] , H[MAXN+5];
void solve()
{
	long long s2(0);
	int a,i,s;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&a);
		H[a] = true;
	}
	FOR(i,1,MAXN) B[i] = i;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&a);
		s = 0;
		for(i = B[a]; s < a && i <= MAXN; i += a)
			if(!C[i])
			{
				C[i] = true;
				s2++;
				if(H[i]) V.push_back(s2);
				s++;
			}
		s2 += (long long) a - s;
		B[a] = i;
	}

	printf("%d\n" , (int) V.size() );
	for(vector < long long > :: iterator it = V.begin(); it != V.end(); ++it)
		printf("%lld\n" , *it );

}
int main()
{
	solve();
	return 0;
}
