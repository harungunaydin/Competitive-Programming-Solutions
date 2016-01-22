#include <iostream>
using namespace std;
int A[1000];
double DP[100000][2];
int N;
double f(int x,bool y)
{
	if(DP[x][y]) return DP[x][y];
	if(x==-1) return 100.0;
	if(y) return DP[x][1]=max(f(x-1,1),(f(x-1,0)*A[x])/100.0);
	return DP[x][0]=max(f(x-1,0),(f(x-1,1)*100.0)/A[x]);
}
void solve()
{
	int i;
	cin >> N;
	for(i=0; i<N; i++)
		cin >> A[i];
	printf("%.2lf\n",f(N-1,0));
}
int main()
{
	solve();
	return 0;
}
