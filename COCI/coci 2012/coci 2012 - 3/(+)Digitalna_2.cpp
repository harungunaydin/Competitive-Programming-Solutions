#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 100
using namespace std;
int A[MAXN+5];
void solve()
{
	string str;
	int N,a,b,i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str;
		if(str == "BLJTV1") a = i;
		else if(str == "BLJTV2") b = i;
	}
	A[a] = 1; A[b] = 2;
	FOR(i,1,a-1)
		printf("1");
	TFOR(i,a,2)
	{
		printf("4");
		swap(A[i],A[i-1]);
	}
	FOR(i,1,N)
		if(A[i] == 2)
			break;
	b = i;
	FOR(i,1,b-1)
		printf("1");
	TFOR(i,b,3)
		printf("4");
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
