#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MOD 1000000007
#define MAXN 500005
using namespace std;
typedef pair < long long , int > pli;
pli P[MAXN];
long long M,N,X,Y,Z;
long long A[MAXN],B[MAXN],F[MAXN];
long long find(int i)
{
	long long res(0);

	for(; i ; i -= i&-i) res = ( res + F[i] ) % MOD;

	return res;
}
void update(int i,long long v)
{
	for(; i < MAXN ; i += i&-i) F[i] = ( F[i] + v ) % MOD;
}

void indirge()
{
	int i,j,s(0);

	FOR2(i,N) P[i] = make_pair( B[i] , i );

	sort(P,P+N);

	FOR2(i,N)
	{
		j = i;
		s++;
		while(i < N && P[i].f == P[j].f) B[P[i++].s] = s;
		i--;
	}
}

void solve()
{
	memset( F , 0 , sizeof F );
	memset( A , 0 , sizeof A );
	int i;

	scanf("%lld %lld %lld %lld %lld",&N,&M,&X,&Y,&Z);


	FOR2(i,M) scanf("%lld",A+i);

	FOR2(i,N)
	{
		B[i] = A[i%M];
		A[i%M] = ( X * A[i%M] + Y * (i+1) ) % Z;
	}

	indirge();

	long long res(0),t;

	FOR2(i,N)
	{
		t = find(B[i]-1) + 1ll;
		res = ( res + t ) % MOD;
		update(B[i],t);
	}
	printf("%lld\n" , res );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}

	return 0;
}
