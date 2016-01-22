#include <iostream>
using namespace std;
void solve(int bas,int son,int k)
{
	if(bas==son) Rjesenje(bas);
	int length=(son-bas)/10;
	while(!Baci(length,k));
}
int main()
{
	solve(1,1000000,1);
	system("PAUSE");
	return 0;
}
