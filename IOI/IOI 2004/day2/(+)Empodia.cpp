#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
#define MAXN 1100000
using namespace std;
typedef pair <int,int> pii;
stack <int> st;
int number_of_res;
pii B[MAXN+5],C[MAXN+5],res[MAXN+5];
int A[MAXN+5],D[MAXN+5],last[MAXN+5],next[MAXN+5];
bool used[MAXN+5];
void solve()
{
	int M=0,N,a,b,i,j;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	for(i=1; i<=N; last[i] = j,i++)
		for(j=i-1; j>=1 && A[j] < A[i]; j = last[j]);
	for(i=N; i>=1; next[i] = j,i--)
		for(j=i+1; j<=N && A[j] > A[i]; j = next[j]);
	FOR(i,1,N)
		B[i] = make_pair(A[i]-i,i);
	sort(B+1,B+N+1);
	FOR(i,1,N)
	{
		a = B[i].second;
		for(j=i+1; j<=N && B[i].first == B[j].first; j++)
		{
			b = B[j].second;
			if(next[a] <= b) break;
			if(last[b] < a)
			{
				D[b] = a;
				C[++M] = make_pair(a, +(i+1));
				C[++M] = make_pair(b, -(i+1));
				break;
			}
		}
	}
	sort(C+1,C+M+1);
	FOR(i,1,M)
	{
		a = C[i].second;
		if(a > 0) st.push(a);
		if(a < 0 && !used[abs(a)])
		{
			while(!st.empty())
			{
				used[st.top()] = true;
				st.pop();
			}
			b = C[i].first;
			res[number_of_res++] = make_pair(D[b],b);
		}
	}
	printf("%d\n",number_of_res);
	FOR2(i,number_of_res)
		printf("%d %d\n",res[i].first , res[i].second);
}
int main()
{
	solve();
	return 0;
}
