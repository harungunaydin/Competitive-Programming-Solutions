#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int solve()
{
	int N,a=0,b=0,c=0,d,i,t=0;
	string str;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str;
		(str=="1/2")? a++ : (str=="1/4")? b++ : c++;
	}
	t=(a+1)/2+c;
	d=(a%2)*2+c;
	return (d>=b)? t : t+((b-d)/4)+((b-d)%4>0);
}
int main()
{
	cout << solve() << endl;
	return 0;
}
