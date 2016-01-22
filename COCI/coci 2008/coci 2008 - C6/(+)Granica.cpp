#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100
using namespace std;
vector <int> V;
int N;
int A[MAXN+5];
bool control(int x)
{
	int a = A[1]%x,i;
	FOR(i,1,N)
		if(A[i]%x != a)
			return 0;
	return 1;
}
void solve()
{
	int i,t;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	t = abs(A[1] - A[2]);
	for(i=1; i*i<=t; i++)
		if(!(t%i))
		{
			if(control(i) && i!=1) V.push_back(i);
			if(control(t/i) && t/i != i) V.push_back(t/i);
		}
	sort(all(V));
	FOR2(i,V.size())
	{
		printf("%d",V[i]);
		if(i < V.size()-1)
			printf(" ");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
