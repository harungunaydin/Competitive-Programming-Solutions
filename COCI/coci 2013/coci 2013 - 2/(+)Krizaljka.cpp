#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define S(a,b) str2[a][b]
using namespace std;
string str[10],str2[10];
int A[10] = {0,1,2,3,4,5,6};
void solve()
{
	int i;
	FOR(i,1,6) cin >> str[i];
	do
	{
		FOR(i,1,6) str2[i] = str[A[i]];
		if(S(1,0) != S(4,0) || S(2,0) != S(4,1) || S(3,0) != S(4,2) || S(1,1) != S(5,0) || S(2,1) != S(5,1) || S(3,1) != S(5,2))
			continue;
		if(S(1,2) != S(6,0) || S(2,2) != S(6,1) || S(3,2) != S(6,2))
			continue;
		FOR(i,1,3)
			cout << str2[i] << endl;
		return;
	}while(next_permutation(A+1,A+7));
	printf("0\n");
}
int main()
{
	solve();
	return 0;
}
