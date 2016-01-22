#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int k,s;
int A[489000],B[15];
void izracunaj(int x)
{
	if(!x) return;
	izracunaj(x/10);
	A[++k]=x%10;
}
void izracunaj2(int x)
{
	if(!x) return;
	izracunaj2(x/10);
	B[++s]=x%10;
}
int solve()
{
	int b,i,j,N;
	cin >> N;
	FOR(i,1,N)
		izracunaj(i);
	if(!N) s=1;
	else izracunaj2(N);
	FOR(i,1,k)
	{
		FOR(j,1,s)
			if(A[i+j-1]!=B[j])
				break;
		if(j==s+1) return i;
	}
}
int main()
{
	cout << solve() << endl;
	return 0;
}
