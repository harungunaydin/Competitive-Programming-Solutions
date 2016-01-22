#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 55
using namespace std;
char A[MAXN][MAXN];
int main()
{
	int M,N,a,b,i,j;
	scanf("%d %d %d %d",&M,&N,&a,&b);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf(" %c" , A[i] + j );

	for(i = 1; i <= M*a; i++,printf("\n"))
		FOR(j,1,N*b)
			printf("%c" , A[ (i+a-1)/a ][ (j+b-1)/b ] );

	return 0;
}
