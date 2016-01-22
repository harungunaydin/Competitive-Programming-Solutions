#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 105
using namespace std;
char A[6][MAXN];
void hallet(int k,char a,char c)
{
	int i,j;
	A[1][k] = '.'; A[1][k+1] = '.'; A[1][k+2] = c; A[1][k+3] = '.'; A[1][k+4] = '.';
	A[2][k] = '.'; A[2][k+1] = c; A[2][k+2] = '.'; A[2][k+3] = c; A[2][k+4] = '.';
	A[3][k] = c; A[3][k+1] = '.'; A[3][k+2] = a; A[3][k+3] = '.'; A[3][k+4] = c;
	A[4][k] = '.'; A[4][k+1] = c; A[4][k+2] = '.'; A[4][k+3] = c; A[4][k+4] = '.';
	A[5][k] = '.'; A[5][k+1] = '.'; A[5][k+2] = c; A[5][k+3] = '.'; A[5][k+4] = '.';
}
void solve()
{
	string str;
	int i,j,k(1),t;
	cin >> str;
	t = (int) str.size();

	for(i = 0; i < t; i++ , k += 4)
		if(i % 3 < 2)
			hallet(k,str[i],'#');

	k = 1;

	for(i = 0; i < t; i++ , k += 4)
		if(i % 3 == 2)
			hallet(k,str[i],'*');


	t = t * 4 + 1;

	for(i = 1; i <= 5; i++,printf("\n"))
		FOR(j,1,t)
			printf("%c" , A[i][j] );


}
int main()
{
	solve();
	return 0;
}
