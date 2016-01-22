//SORU 436
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <climits>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "likecow.in"
#define OUTPUT "likecow.out"
#define MAXN 50
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
char A[MAXN+5][6][8];
int compare(int a,int b)
{
	int i,j,res=0;
	FOR(i,1,5)
		FOR(j,1,7)
			res+=(A[a][i][j] != A[b][i][j]);
	return res;
}
void solve()
{
	int N,i,j,k,mini = INT_MAX,res1,res2;
	in >> N;
	FOR(i,1,N)
		FOR(j,1,5)
			FOR(k,1,7)
				in >> A[i][j][k];
	FOR(i,1,N)
		FOR(j,i+1,N)
			if((k = compare(i,j)) < mini)
			{
				mini = k;
				res1 = i;
				res2 = j;
			}
	out << res1 << " " << res2 << endl;
}
int main()
{
	solve();
	return 0;
}
