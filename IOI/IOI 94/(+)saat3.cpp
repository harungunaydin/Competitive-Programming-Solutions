#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int A[15][15] = { {3,3,3,3,3,2,3,2,0},
									{2,3,2,3,2,3,1,0,1},
									{3,3,3,2,3,3,0,2,3},
									{2,3,1,3,2,0,2,3,1},
									{2,3,2,3,1,3,2,3,2},
									{1,3,2,0,2,3,1,3,2},
									{3,2,0,3,3,2,3,3,3},
									{1,0,1,3,2,3,2,3,2},
									{0,2,3,2,3,3,3,3,3}
								};
int a[1005],res[1005];
void solve()
{
	int i,j;
	string str = "";
	FOR2(i,9)
	{
		scanf("%d",a+i);
		a[i] = (a[i] == 12) ? 0 : (a[i] == 3) ? 3 : (a[i] == 6) ? 2 : 1;
	}
	FOR2(i,9)
		FOR2(j,9)
			res[j] = (res[j] + A[i][j]*a[i])%4;
			
	FOR2(i,9)
		FOR2(j,res[i])
			str = str + " " + char(i+'1');
	cout << str.substr(1) << endl;
}
int main()
{
	solve();
	return 0;
}
