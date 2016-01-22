#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[10005];
void solve()
{
	int i,N;
	cin >> N;
	FOR(i,1,N)
		cin >> A[i];
	sort(A+1,A+N+1);
	FOR(i,1,N)
		if(i>=A[i]+1)
			break;
	cout << i << endl;
}
int main()
{
	solve();
	return 0;
}
