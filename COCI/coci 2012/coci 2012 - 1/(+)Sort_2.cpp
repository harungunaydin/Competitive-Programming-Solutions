#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 300000
using namespace std;
long long N,res;
long long A[MAXN+5],F[MAXN+5];
void cevir(int a , int b)
{
	int i,n;
	n = b-a+1;
	for(i=0; i<=(b-a)/2; i++)
		swap(A[a+i],A[n-i-1+a]);
}
void fenwick_tree()
{
	int i,j;
	FOR(i,1,N)
	{
		j = A[i];
		for(; j; j-=(j&-j))
			res+=F[j];
		j = A[i];
		for(; j<=N; j+=(j&-j))
			F[j]++;
	}
}
void solve()
{
	int i,j,k;
	scanf("%lld",&N);
	FOR(i,1,N)
		scanf("%lld",A+i);
	FOR(i,1,N)
	{
		k = i;
		while(i<N && A[i] > A[i+1]) i++;
		res++;
		reverse(A+k,A+i+1);
	}
	reverse(A+1,A+N+1);
	fenwick_tree();
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
