#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int gcd(int a,int b)
{
	return (!b)? a : gcd(b,a%b);
}
int pow(int a,int b)
{
	return (!b)? 1 : pow(a,b-1)*a;
}
int hesapla(string str)
{
	int i,k=1,s=0;
	for(i=str.size()-1; i>=0; i--,k*=10)
		s+=(str[i]-'0')*k;
	return s;
}
void solve()
{
	int a,i,k,m,n,x,y;
	char c[15];
	string str;
	scanf("%d.%s",&n,c);
	str=c;
	while(str[str.size()-1]=='0') str.resize(str.size()-1);
	k=str.size();
	k=pow(10,k);
	a=hesapla(str);
	x=k-a;
	y=a;
	m=gcd(x,y);
	x/=m;
	y/=m;
	FOR(i,1,5) (i==n)? cout << x << " " : (i==n+1)? cout << y << " " : cout << "0 ";
	cout << endl;
}
int main()
{
	solve();
	return 0;
}
