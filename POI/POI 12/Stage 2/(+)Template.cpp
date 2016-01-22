#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define BASE 1009ll
#define MAXN 500005
using namespace std;
typedef pair < int , int > pii;
long long H[MAXN] , us[MAXN];
int N;
char A[MAXN];
bool control(int k)
{
	long long t = H[k];
	int i,pre;
	FOR(i,k,N)
		if( H[i] - H[i-k] * us[k] == t )
		{
			if(pre && pre + k < i - k + 1)
				return false;
			pre = i - k + 1;
		}

	return true;
}
void solve()
{
	scanf("%s" , A+1 );
	int i,k(1);
	N = strlen(A+1);
	us[0] = 1;
	FOR(i,1,N)
	{
		H[i] = H[i-1] * BASE + A[i];
		us[i] = us[i-1] * BASE;
	}

	while(k <= N)
		if(H[k] != H[N] - H[N-k] * us[k])
			k++;
		else
		{
			if(control(k)) { printf("%d\n" , k ); return; }
			else k = 2*k + 1;
		}
	printf("%d\n" , k );
}
int main()
{
	solve();
	return 0;
}
