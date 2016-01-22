#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define BASE 1009ll
#define MAXN 200005
using namespace std;
int N;
long long H[MAXN] , T[MAXN] , us[MAXN];

bool control(int k)
{
	long long t = us[k];
	int i,s(0);
	FOR(i,k,N)
		T[++s] = H[i] - H[i-k] * t;

	sort( T+1,T+s+1 );

	FOR(i,1,s)
		if(T[i] == T[i-1])
			return true;

	return false;
}
int BS(int bas,int son)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return control(son) ? son : bas;
	int orta = ( bas + son ) >> 1;
	return control(orta) ? BS(orta,son) : BS(bas,orta-1);
}
char A[MAXN];
void solve()
{
	scanf("%d",&N);

	scanf("%s",A+1);

	int i;
	us[0] = 1;
	FOR(i,1,N)
	{
		H[i] = H[i-1] * BASE + (long long)A[i];
		us[i] = us[i-1] * BASE;
	}

	printf("%d\n" , BS(0,N) );

}
int main()
{
	solve();
	return 0;
}
