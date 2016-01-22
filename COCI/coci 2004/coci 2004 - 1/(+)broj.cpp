#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int bas[]={0,9,180,2700,36000,450000,5400000,63000000,720000000}; 
int us(int a,int b)
{
	return (!b)? 1 : us(a,b-1)*a;
}
void solve()
{
	int a,i,N,s=0,t=0;
	cin >> N;
	a=N;
	while(a)
	{
		a/=10;
		s++;
	}
	FOR(i,1,s-1)
		t+=bas[i];
	t+=(N-us(10,s-1)+1)*s;
	cout << t << endl;
}
int main()
{
	solve();
	return 0;
}
