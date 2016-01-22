#include <iostream>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
stack <int> st;
int N;
int A[300005];
int LMIN[300005];
int RMIN[300005];
int LMAX[300005];
int RMAX[300005];
void clear()
{
	while(!st.empty()) st.pop();
}
void solve()
{
	long long i,mini=0,maxi=0;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",&A[i]);
	A[0] = INT_MIN;
	st.push(0);
	FOR(i,1,N)
	{
		while(A[i] <= A[st.top()]) st.pop();
		LMIN[i]=st.top();
		st.push(i);
	}
	A[0] = INT_MAX;
	clear();
	st.push(0);
	FOR(i,1,N)
	{
		while(A[i] >= A[st.top()]) st.pop();
		LMAX[i] = st.top();
		st.push(i);
	}
	clear();
	st.push(N + 1);
	A[N+1] = INT_MIN;
	TFOR(i,N,1)
	{
		while(A[i] < A[st.top()]) st.pop();
		RMIN[i] = st.top();
		st.push(i);
	}
	clear();
	st.push(N + 1);
	A[N+1] = INT_MAX;
	TFOR(i,N,1)
	{
		while(A[i] > A[st.top()]) st.pop();
		RMAX[i] = st.top();
		st.push(i);
	}
	FOR(i,1,N)
	{
		mini+=(i - LMIN[i]) * (RMIN[i] - i) * A[i];
		maxi+=(i - LMAX[i]) * (RMAX[i] - i) * A[i];
	}
	printf("%lld\n",maxi-mini);
}
int main()
{
	solve();
	return 0;
}
