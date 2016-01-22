#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[1005];
int solve()
{
	int K,M,N,a,b,i,k=0,s=1;
	cin >> N >> K >> M;
	FOR(i,1,N) A[i]++;
	FOR(i,1,M)
	{
		cin >> a >> b;
		A[a]+=b;
	}
	for(i=1; i<=N;)
	{
		if(A[i]>K) { i++; s++; continue; }
		if(k+A[i]>K)
		{
			s++;
			k=0;
			continue;
		}
		k+=A[i++];
	}
	return s;
}
int main()
{
	cout << solve() << endl;
	return 0;
}
