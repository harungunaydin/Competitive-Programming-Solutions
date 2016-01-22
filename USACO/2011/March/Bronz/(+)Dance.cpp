#include <iostream>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
stack < char > st;
int N;
void solve()
{
	int N,i,j,s;
	char c;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&s);
		FOR(j,1,s)
		{
			scanf(" %c",&c);
			(!st.empty() && st.top()=='>' && c=='<')? st.pop() : st.push(c);
		}
		(st.empty()) ? printf("legal\n") : printf("illegal\n");
		while(!st.empty()) st.pop();
	}
}
int main()
{
	solve();
	return 0;
}
