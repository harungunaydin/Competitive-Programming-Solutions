#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
typedef pair < pii , int > pii3;
vector < pii3 > V;
vector < int > S[MAXN];
int A[MAXN],B[MAXN],F[MAXN],RES[MAXN];
int N,Q;
int update(int a,int k)
{
	for(; a ; a -= a&-a) F[a] += k;
}
int find(int a,int b)
{
	int sum(0),x;
	for(x = a; x < MAXN; x += x&-x ) sum += F[x];
	for(x = b + 1; x < MAXN; x += x&-x ) sum -= F[x];
	return sum;
}
void hallet(int a,int b)
{
	int i;
	FOR(i,a,b)
	{
		if(B[A[i]] + 1 < S[A[i]].size())
			update(S[A[i]][ ++B[A[i]] ] , 1 );
		update(i,-1);
	}
}
void solve()
{
	V.clear();
	memset( B , 0 , sizeof B );
	memset( F , 0 , sizeof F );
	int a,b,i,last(1);
	scanf("%d %d",&N,&Q);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		if(S[A[i]].empty()) update(i,1);
		S[A[i]].push_back(i);
	}
	FOR(i,1,Q)
	{
		scanf("%d %d",&a,&b);
		V.push_back(make_pair(make_pair(a,b),i));
	}
	sort(V.begin(),V.end());
	vector < pii3 > :: iterator it;
	for(it = V.begin(); it != V.end(); ++it)
	{
		if(it->f.f > last)
		{
			hallet(last,it->f.f-1);
			last = it->f.f;
		}
		RES[it->s] = find(it->f.f,it->f.s);
	}
	FOR(i,1,Q)
		printf("%d\n" , RES[i] );
	FOR(i,1,N) S[A[i]].clear();
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
