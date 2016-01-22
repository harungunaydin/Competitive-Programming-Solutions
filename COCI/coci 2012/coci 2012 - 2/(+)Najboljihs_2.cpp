#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define MAXN 8
using namespace std;
typedef pair <int,int> pii;
vector <int> V;
pii A[MAXN+5];
void solve()
{
	int i,res(0);
	FOR2(i,MAXN)
	{
		scanf("%d",&A[i].f);
		A[i].s = i+1;
	}
	sort(A,A+MAXN);
	reverse(A,A+MAXN);
	FOR2(i,5)
	{
		res+=A[i].f;
		V.push_back(A[i].s);
	}
	sort(all(V));
	printf("%d\n",res);
	FOR2(i,V.size())
	{
		printf("%d",V[i]);
		if(i!=V.size()-1)
			printf(" ");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
