#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100
using namespace std;
char A[MAXN+5][MAXN+5];
void solve()
{
	int b,i,j,M,N;
	string str;
	cin >> str;
	N = str.size();
	b = (int)sqrt(N);
	TFOR(i,b,1)
		if(!(N%i))
			break;
	M = i;
	N/=M;
	b = 0;
	FOR(j,1,N)
		FOR(i,1,M)
			A[i][j] = str[b++];
	FOR(i,1,M)
		FOR(j,1,N)
			printf("%c",A[i][j]);
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
