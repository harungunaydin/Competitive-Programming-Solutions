#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int N;
int A[1000000],B[1000000];
void solve()
{
	int a,b,c,d,i=1,j,k,l,K;
	scanf("%d %d",&N,&K);
	FOR(i,1,N) A[i]=i;
	FOR2(i,K)
	{
		scanf("%d %d %d",&a,&b,&c);
		k=l=0;
		FOR(j,a,b) B[k++]=A[j];
		d=b-a+1;
		FOR(j,b+1,N) A[j-d]=A[j];
		for(j=N; j-d>c; j--) A[j]=A[j-d];
		FOR(j,c+1,c+k)
			A[j]=B[l++];
	}
	for(i=1; i<=10; i++)
		cout << A[i] << endl;
}
int main()
{
	solve();
	return 0;
}
