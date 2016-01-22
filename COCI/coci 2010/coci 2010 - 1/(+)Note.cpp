#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int A[10];
string solve()
{
	int i;
	FOR(i,1,8)
		scanf("%d",A+i);
	FOR(i,1,7)
		if(A[i] > A[i+1])
			break;
	if(i == 8) return "ascending";
	FOR(i,1,7)
		if(A[i] < A[i+1])
			break;
	return (i == 8) ? "descending" : "mixed";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
