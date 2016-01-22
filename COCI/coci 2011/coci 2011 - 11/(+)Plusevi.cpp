#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N;
char A[2005][2005];
bool kontrol(int x,int y,int k)
{
	int i,s=0;
	FOR(i,y-k,y+k)
	{
		s+=A[x+k][i]-'0';
		if(s > 1) return 1;
	}
	s=0;
	FOR(i,y-k,y+k)
	{
		s+=A[x-k][i]-'0';
		if(s > 1) return 1;
	}
	s=0;
	FOR(i,x-k,x+k)
	{
		s+=A[i][y-k]-'0';
		if(s > 1) return 1;
	}
	s=0;
	FOR(i,x-k,x+k)
	{
		s+=A[i][y+k]-'0';
		if(s > 1) return 1;
	}
	return 0;
}
void solve()
{
	int i,j,k,s=0;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf(" %c",&A[i][j]);
	FOR(i,1,N)
		FOR(j,1,N)
			if(A[i][j]=='1')
				for(k=1; k<=N/2; k++)
				{
					if(i+k > N || j+k > N || i-k < 1 || j-k < 1) break;
					if(A[i+k][j]!='1') break;
					if(A[i][j+k]!='1') break;
					if(A[i-k][j]!='1') break;
					if(A[i][j-k]!='1') break;
					if(kontrol(i,j,k)) break;
					s++;
				}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
