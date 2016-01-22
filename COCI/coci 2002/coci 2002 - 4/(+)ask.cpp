#include <iostream>
#include "lib.h"
using namespace std;
string str;
void solve()
{
	bool flag;
	while(1)
	{
		flag=true;
		if(Ask((str+'0').c_str()))
			str+='0',flag=false;
		if(Ask(('0'+str).c_str()))
			str='0'+str,flag=false;
		if(Ask((str+'1').c_str()))
			str+='1',flag=false;
		if(Ask(('1'+str).c_str()))
			str='1'+str,flag=false;
		if(flag)
			Solution(str.c_str());
	}
}
int main()
{
	Init();
	solve();
	return 0;
}
