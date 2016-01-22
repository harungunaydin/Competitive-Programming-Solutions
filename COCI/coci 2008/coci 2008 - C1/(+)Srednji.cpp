 #include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100000
#define MAXL 100000
using namespace std;
int A[MAXN+5],B[MAXL*2+5],C[MAXL*2+5];
void solve()
{
	long long res(0);
	int K,N,c(0),i,k;
	scanf("%d %d",&N,&K);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		if(A[i] == K) k = i;
	}
	B[MAXL]++;
	TFOR(i,k-1,1)
	{
		(A[i] < K) ? c++ : c--;
		B[MAXL+c]++;
	}
	c = 0;
	C[MAXL]++;
	FOR(i,k+1,N)
	{
		(A[i] < K) ? c++ : c--;
		C[MAXL+c]++;
	}
	FOR(i,1,MAXL)
		res+=(B[MAXL+i]*C[MAXL-i]) + (B[MAXL-i]*C[MAXL+i]);
	printf("%lld\n",res+B[MAXL]*C[MAXL]);
}
int main()
{
	solve();
	return 0;
}
