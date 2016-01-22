#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 150005
using namespace std;
typedef pair < int , int > pii;
set < int > st;
pii SEG[MAXN];
int M,N,Q;
int A[MAXN],Query[MAXN],ST[4*MAXN];
void update(int pos,int s,int e,int a,int b)
{
	if(a <= A[s] && A[e] <= b) { ST[pos]++; return; }
	if(a > A[e] || b < A[s]) return;
	int m = ( s + e ) / 2;
	update(pos*2,s,m,a,b);
	update(pos*2+1,m+1,e,a,b);
}
int find(int pos,int s,int e,int a)
{
	if(a < A[s] || a > A[e]) return 0;
	if(s == e) return ST[pos];
	int m = ( s + e ) / 2;
	return find(pos*2,s,m,a) + find(pos*2+1,m+1,e,a) + ST[pos];
}
void solve()
{
	memset( ST , 0 , sizeof ST );
	st.clear();
	M = 0;
	int a,b,i;
	scanf("%d %d",&N,&Q);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		SEG[i] = make_pair(a,b);
		st.insert(a);
		st.insert(b);
	}
	FOR(i,1,Q)
	{
		scanf("%d" , Query+i);
		st.insert(Query[i]);
	}
	for(set < int > :: iterator it = st.begin(); it != st.end(); ++it)
		A[++M] = *it;
	FOR(i,1,N)
		update(1,1,M,SEG[i].first,SEG[i].second);
	FOR(i,1,Q)
		printf("%d\n" , find(1,1,M,Query[i]) );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
