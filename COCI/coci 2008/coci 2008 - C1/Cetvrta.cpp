#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
int X[MAXN+5],Y[MAXN+5];
void solve()
{
	int x1,x2,x3,y1,y2,y3;
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	X[x1]++; Y[y1]++;
	X[x2]++; Y[y2]++;
	X[x3]++; Y[y3]++;
	if(X[x1] == 1) printf("%d ",x1);
	if(X[x2] == 1) printf("%d ",x2);
	if(X[x3] == 1) printf("%d ",x3);
	if(Y[y1] == 1) printf("%d\n",y1);
	if(Y[y2] == 1) printf("%d\n",y2);
	if(Y[y3] == 1) printf("%d\n",y3);
}
int main()
{
	solve();
	return 0;
}
