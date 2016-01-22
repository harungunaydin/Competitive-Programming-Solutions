#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
int i,j;
void solve()
{
	int N;
	cin >> N;
	FOR(i,1,12)
		FOR(j,1,31)
			if(i*31 + j*12 == N)
				return;
}
int main()
{
	solve();
	if(j<10) printf("0");
	printf("%d/",j);
	if(i<10) printf("0");
	printf("%d\n",i);
	return 0;
}
