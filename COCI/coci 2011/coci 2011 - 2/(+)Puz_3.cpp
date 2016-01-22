#include <iostream>
using namespace std;
void solve()
{
	int A,B,V;
	scanf("%d %d %d",&A,&B,&V);
	A-=B;
	printf("%d\n",(V-B)/A+((V-B)%A>0));
}
int main()
{
	solve();
	return 0;
}
