#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	int N,a,b,i,j,res=0;
	cin >> N;
	a = N*N;
	FOR(i,1,N)
	{
		b = a - i*i;
		FOR(j,1,N)
			if(j*j <= b)
				res++;
	}
	cout << (res<<2) + (N<<2) + 1 << endl;
}
int main()
{
	solve();
	return 0;
}
