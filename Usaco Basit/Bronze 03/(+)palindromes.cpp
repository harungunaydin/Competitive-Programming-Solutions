//SORU 458
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INPUT "pal.in"
#define OUTPUT "pal.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
string str;
int find_pal(int x)
{
	int i=1;
	while(x-i>=0 && x+i<=str.size())
	{
		if(str[x-i] != str[x+i])
			return 2*i-1;
		i++;
	}
	return 2*i-1;
}
int find_pal2(int x)
{
	int i=1;
	while(x-i>=0 && x+i-1<=str.size())
	{
		if(str[x-i] != str[x+i-1])
			return 2*i-2;
		i++;
	}
	return 2*i-2;
}
void solve()
{
	int a,i,maxi=0,maxindex=1,start,s=0;
	in >> str;
	FOR2(i,str.size())
	{
		a = find_pal(i);
		if(a > maxi)
		{
			maxi = a;
			maxindex = i;
		}
		a = find_pal2(i);
		if(a > maxi)
		{
			maxi = a;
			maxindex = i;
		}
	}
	s = 1;
	for(i=maxindex-maxi/2; s<=maxi; i++,s++)
		out << str[i];
}
int main()
{
	solve();
	return 0;
}
