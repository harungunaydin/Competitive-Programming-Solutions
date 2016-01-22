#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N;
int A[1005];
bool hash[1005];
int bul(int a,int b)
{
	int i,x=a;
	FOR(i,1,N) hash[i]=false;
	while(A[x])
	{
		hash[x]=true;
		x=A[x];
	}
	hash[x]=true;
	x=b;
	while(A[x])
	{
		if(hash[x]) return x;
		x=A[x];
	}
	return x;
}
void solve()
{
	int i,x,y;
	scanf("%d %d",&N,&M);
	FOR(i,2,N) scanf("%d",&A[i]);
	FOR(i,1,M)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",bul(x,y));
	}
}
int main()
{
	solve();
	return 0;
}
