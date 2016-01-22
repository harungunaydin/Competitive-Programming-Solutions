#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N,K;
bool A[105][105];
void out(int x,int y,int p,int t)
{
	int a=p/2,i,j;
	FOR(i,1,M)
		FOR(j,1,N)
			if((i>=x-a && i<=x+a && j>=y-a && j<=y+a)!=t)
				A[i][j]=true;
}
void solve()
{
	int i,j,p,t=0,T,x,y;
	cin >> M >> N >> K;
	FOR(i,1,K)
	{
		cin >> x >> y >> p >> T;
		out(x,y,p,T);
	}
	for(i=1; i<=M; i++)
		FOR(j,1,N)
			t+=1-A[i][j];
	cout << t << endl;
}
int main()
{
	solve();
	return 0;
}
