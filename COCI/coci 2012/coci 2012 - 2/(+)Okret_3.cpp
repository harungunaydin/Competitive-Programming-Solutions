#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define KONTROL(x,y) (x > 0 && x <= M && y > 0 && y <= N)
using namespace std;
int M,N,i,j;
int yon[10][10]={ {1,0} , {0,1} , {-1,0} , {0,-1} };
char A[105][105];
int read()
{
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",&c);
			A[i][j] = (c == '.');
		}
	FOR(i,1,M)
		FOR(j,1,N)	
			if(A[i][j] && A[i+1][j] + A[i][j+1] + A[i-1][j] + A[i][j-1] == 1)
				return 1;
	return 0;
}
int main()
{
	cout << read() << endl;
	return 0;
}
