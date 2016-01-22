#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
set < pii > st;
vector < int > S[MAXN],V[MAXN];
int C,K,N;
int A[MAXN],B[MAXN];
bool H[MAXN];
void solve()
{
	int a,b,i,s(0);
	scanf("%d %d %d",&N,&C,&K);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		V[A[i]].push_back(i);
	}
	FOR(i,1,N) V[A[i]].push_back(N+1);
	FOR(i,1,N)
	{
		a = A[i];
		if(H[a])
		{
			st.erase( st.find( make_pair( - V[a][B[a]] , a ) ) );
			st.insert( make_pair( - V[a][++B[a]] , a ) );
			continue;
		}
		if(st.size() < K)
		{
			st.insert( make_pair( - V[a][++B[a]], a ) );
			H[a] = true;
			s++;
		}
		else
		{
			H[(st.begin()) -> second] = false;
			st.erase(st.begin());
			st.insert( make_pair( - V[a][++B[a]] , a ) );
			H[a] = true;
			s++;
		}
	printf("%d\n" , s );
}
int main()
{
	solve();
	return 0;
}
