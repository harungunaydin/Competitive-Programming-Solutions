#include <iostream>
using namespace std;
void solve()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a + b == c) 			printf("%d+%d=%d\n",a,b,c);
	else if(a - b == c) printf("%d-%d=%d\n",a,b,c);
	else if(a * b == c) printf("%d*%d=%d\n",a,b,c);
	else if(a / b == c) printf("%d/%d=%d\n",a,b,c);
	else if(a == b + c) printf("%d=%d+%d\n",a,b,c);
	else if(a == b - c) printf("%d=%d-%d\n",a,b,c);
	else if(a == b * c) printf("%d=%d*%d\n",a,b,c);
	else if(a == b / c) printf("%d=%d/%d\n",a,b,c);
}
int main()
{
	solve();
	return 0;
}
