#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N,a,b;
int A[10005][3];
char C[10005];
int hesapla(int x,int y)
{
	int t1,t2;
	t1=A[y][1]-A[x-1][1];
	t2=A[y][2]-A[x-1][2];
	t1=A[N][1]-t1;
	t2=A[N][2]-t2;
	return abs(a-t1)+abs(b-t2);
}
void solve()
{
	scanf("%d %d %d",&a,&b,&N);
	int c,d,i,j,mini=10000000,t;
	FOR(i,1,N)
		scanf(" %c",&C[i]);
	FOR(i,1,N)
	{
		A[i][1]=A[i-1][1];
		A[i][2]=A[i-1][2];
		if(C[i]=='R') A[i][2]++;
		if(C[i]=='L') A[i][2]--;
		if(C[i]=='U') A[i][1]++;
		if(C[i]=='D') A[i][1]--;
	}
	FOR(i,1,N)
		FOR(j,i,N)
		{
			t=hesapla(i,j);
			if(t < mini)
			{
				mini=t;
				c=i;
				d=j;
			}
		}
}
int main()
{
	solve();
	return 0;
}
