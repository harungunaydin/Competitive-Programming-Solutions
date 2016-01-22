#include <iostream>
#include "lib.h"
using namespace std;
void solve()
{
	int a,x,y;
	while(1)
	{	
		x = dimension_x();
		y = dimension_y();
		if(x < y)
		{
			a = x;
			while(a < y) a = a*2 + 1;
			a--; a/=2;
			cut(vertical,a);
		}
		else
		{
			a = y;
			while(a < x) a = a*2 + 1;
			a--; a/=2;
			cut(horizontal,a);
		}
	}
}
int main()
{
	solve();
	return 0;
}
