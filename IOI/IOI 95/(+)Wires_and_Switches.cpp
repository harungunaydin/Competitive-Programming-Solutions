#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
using namespace std;
vector <int> V[100][100];
vector <int> :: iterator it;
int M;
int A[100];
bool degistir(int a)
{
	char b;
	printf("C %d\n",a);
	cin >> b;
	return (b == 'Y');
}
bool kontrol(int a)
{
	char b;
	printf("T %d\n",a);
	cin >> b;
	return (b == 'Y');
}
void dq(int bas,int son)
{
	if(V[bas][son].empty() || bas > son) return;
	int i,orta=(bas+son)/2;
	if(bas == son)
	{
		for(it = V[bas][son].begin(); it!=V[bas][son].end(); ++it)
			A[*it] = bas;
		return;
	}
	bool t;
	FOR(i,orta+1,son) t = degistir(i);
	for(it = V[bas][son].begin(); it!=V[bas][son].end(); ++it)
		if(kontrol(*it) == t)
			V[orta+1][son].push_back(*it);
		else
			V[bas][orta].push_back(*it);
	dq(bas,orta);
	dq(orta+1,son);
}
void solve()
{
	int i;
	scanf("%d",&M);
	FOR(i,1,M)
		V[1][M].push_back(i);
	dq(1,M);
	printf("D");
	FOR(i,1,M)
		printf(" %d",A[i]);
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
