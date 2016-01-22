#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 3000005
using namespace std;
int B[250] , C[250];
char A[MAXN];
bool control()
{
	int i;
	FOR(i,'A','Z')
		if(B[i] != C[i])
			return false;
	FOR(i,'a','z')
		if(B[i] != C[i])
			return false;
	return true;
}
void solve()
{
	int M,N,i,j,res(0);
	scanf("%d %d",&M,&N);
	scanf("%s",A);
	FOR2(i,M)
		B[A[i]]++;
	scanf("%s",A);
	FOR2(i,M)
		C[A[i]]++;
	while(i<N)
	{
		res += control();
		C[A[i-M]]--;
		C[A[i++]]++;
		if(i == N) res += control();
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
