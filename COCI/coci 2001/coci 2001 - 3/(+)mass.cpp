#include <iostream>
#define sayi(x) (x>='0' && x<='9')
#define HESAPLA(c) ((c=='H')? 1 : (c=='C')? 12 : 16)
using namespace std;
string str;
int pos;
bool kontrol(int x,int y)
{
	for(int i=x; i<=y; i++)
		if(str[i]=='(')
			return 0;
	return 1;
}
int find2(int x,int y)
{
	for(int i=x; i<=y; i++)
		if(str[i]=='(')
			return i;
}
int find3(int x,int y)
{
	for(int i=y; i>=x; i--)
		if(str[i]==')')
			return i;
}
int coz()
{
	int sum=0;
	if(str[pos]=='(')
	{
		pos++;
		while(str[pos]!=')')
			sum+=coz();
		pos++;
	}
	else
	{
		sum+=HESAPLA(str[pos]);
		pos++;
	}
	if(sayi(str[pos]))
	{
		sum*=(str[pos]-'0');
		pos++;
	}
	return sum;
}
int main()
{
	cin >> str;
	str='('+str+')';
	cout << coz() << endl;
	return 0;
}
