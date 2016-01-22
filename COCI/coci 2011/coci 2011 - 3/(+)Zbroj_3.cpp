#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int hesapla(string str)
{
	int i,k=1,s=0;
	for(i=str.size()-1; i>=0; i--,k*=10)
		s+=(str[i]-'0')*k;
	return s;
}
void solve()
{
	int i;
	string str,str2,temp,temp2;
	cin >> str >> str2;
	temp=str;
	temp2=str2;
	FOR2(i,str.size())
	{
		if(temp[i]=='6')
			temp[i]='5';
		if(str[i]=='5')
			str[i]='6';
	}
	FOR2(i,str2.size())
	{
		if(temp2[i]=='6')
			temp2[i]='5';
		if(str2[i]=='5')
			str2[i]='6';
	}
	printf("%d %d\n",hesapla(temp) + hesapla(temp2),hesapla(str) + hesapla(str2));
}
int main()
{
	solve();
	return 0;
}
