#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
int K[MAXN+5],K2[MAXN+5];
string str[] = {"none","one","both"};
void solve()
{
	int A,B,C,D,M,P,T,i(1),t;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	scanf("%d %d %d",&P,&M,&T);
	while(i < MAXN)
	{
		t = i+A;
		for(; i<t; i++)
			K[i] = true;
		i+=B;
	}
	i = 1;
	while(i < MAXN)
	{
		t = i+C;
		for(; i<t; i++)
			K2[i] = true;
		i+=D;
	}
	cout << str[K[P]+K2[P]] << endl;
	cout << str[K[M]+K2[M]] << endl;
	cout << str[K[T]+K2[T]] << endl;
}
int main()
{
	solve();
	return 0;
}
