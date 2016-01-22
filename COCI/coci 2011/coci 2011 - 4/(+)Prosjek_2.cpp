#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
int us(int a,int b)
{
	return !b ? 1 : a*us(a,b-1);
}
int to_int_from_str(string str)
{
	int i,k(1),s(0);
	for(i=str.size()-1; i>=0; i--,k*=10)
		s+=(str[i]-'0')*k;
	return s;
}
void solve()
{
	string str;
	int a,b,c,d,e,g,i;
	cin >> str;
	d = to_int_from_str(str.substr(2));
	e = str[0]-'0';
	if(e == 5 && !d) { printf("0 0 0 0 1\n"); return; }
	c = us(10,str.size()-2);
	b = c - d;
	g = __gcd(b,d);
	b/=g;
	d/=g;
	FOR(i,1,e-1)
		printf("0 ");
	printf("%d %d",b,d);
	FOR(i,e+2,5)
		printf(" 0");
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
