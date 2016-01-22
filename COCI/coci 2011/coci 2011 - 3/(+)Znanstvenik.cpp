#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define BASE 1009ll
#define MAXN 1005
using namespace std;
string str[MAXN];
long long A[MAXN];
int M,N;
long long hash( string str )
{
	long long t(0);
	for(int i = 0; i < (int) str.size(); i++)
		t = t * BASE + str[i];
	return t;
}
bool control(int k)
{
	int i;
	FOR(i,1,N)
		A[i] = hash( str[i].substr(k) );

	sort( A+1 , A+N+1 );

	FOR(i,1,N-1)
		if(A[i] == A[i+1])
			return false;

	return true;

}
int BS(int bas,int son)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return control(son) ? son : bas;
	int orta = ( bas + son ) >> 1;
	return control(orta) ? BS(orta,son) : BS(bas,orta-1);
}
void solve()
{
	int i,j;
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c" , &c );
			str[j] += c;
		}

	printf("%d\n" , BS(0,M-1) );

}
int main()
{
	solve();
	return 0;
}
