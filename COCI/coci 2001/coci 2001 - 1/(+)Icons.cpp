#include <iostream>
#include <cmath>
using namespace std;
void solve()
{
	int a,i,sat,sut,N;
	cin >> N;
	a=(int)sqrt(N);
	N-=a*a;
	sat=sut=a;
	if(!N) { cout << a << " " << a << endl; exit(0); }
	for(i=1; N>0; i++)
	{
		(i%2)? sat++ : sut++;
		N-=a;
	}
	cout << sat << " " << sut << endl;
}
int main()
{
	solve();
	return 0;
}
