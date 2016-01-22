#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N;
int A[2550],hash[2550];
void rec(int x,int y)
{
	if(!x) x=N;
	if(hash[x] || !A[x]) { printf("%d\n",y);  exit(0); }
	hash[x]=true;
	int a,temp=A[x];
	A[x]=y;
	a=(x+x)%N;
	rec(a,temp);
}
int solve()
{
	int a,i,temp=0;
	scanf("%d",&N);
	FOR(i,1,N) A[i]=i;
	rec(1,0);
}
int main()
{
	solve();
	return 0;
}
