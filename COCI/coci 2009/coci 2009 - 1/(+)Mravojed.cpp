#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 200
using namespace std;
int M,N,x1,x2,y1,y2;
char A[MAXN+5][MAXN+5];
bool kontrol(int a,int b,int k)
{
	register int i,j;
	FOR(i,a,a+k-1)
		FOR(j,b,b+k-1)
			if(A[i][j] != 'x')
				return 0;
	return 1;
}
void bunu_hallet()
{
	register int a,i,j,k,l;
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == 'x')
			{
				k = i+1;
				while(A[k][j] == 'x') k++;
				l = j+1;
				while(A[i][l] == 'x') l++;
				a = min(k-i,l-j);
				if(kontrol(i,j,a))
				{
					x1 = i; y1 = j; x2 = i+a-1; y2 = j+a-1;
					printf("%d %d %d\n",i,j,a);
					return;
				}
			}
}
void oburunu_de()
{
	register int a,i,j,k,l;
	register int dx1,dx2,dy1,dy2;
	TFOR(i,M,1)
		TFOR(j,N,1)	
			if(A[i][j] == 'x')
			{
				k = i-1;
				while(A[k][j] == 'x') k--;
				l = j-1;
				while(A[i][l] == 'x') l--;
				a = min(i-k,j-l);
				dx1 = i-a+1; dy1 = j-a+1;
				dx2 = i; dy2 = j;
				if(!(x1 <= dx1 && dx2 <= x2 && y1 <= dy1 && dy2 <= y2) && kontrol(dx1,dy1,a))
				{
					printf("%d %d %d\n",dx1,dy1,a);
					return;
				}
			}
}
void solve()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf(" %c",A[i]+j);
	bunu_hallet();
	oburunu_de();
}
int main()
{
	solve();
	return 0;
}
