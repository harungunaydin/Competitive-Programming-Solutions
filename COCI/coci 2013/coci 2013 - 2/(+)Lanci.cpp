#include <algorithm>
#include <cstdio>
using namespace std;
int A[500000];
main( void )
{
	int N,i,s(0);
	scanf("%d",&N);
	for(i=1; i<=N; i++)
		scanf("%d",A+i);
	sort(A+1,A+N+1);
	for(i=1; i<=N && (s+=A[i]) <= N-i-1; i++);
	printf("%d\n" , N - i );
}
