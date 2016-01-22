#include <iostream>
using namespace std;
int K;
bool kontrol(int x)
{
	int a;
	while(x)
	{
		a=x%10;
		if(!(a==4 || a==7)) return 0;
		x/=10;
	}
	return 1;
}
void solve()
{
	int a=2,bas,i=1,s=0;
	scanf("%d",&K);
	while(s<K)
	{
		s+=a;
		a<<=1;
		i++;
	}
	K=K-(s-a/2)-1;
	i--;
	string str;
	while(i)
	{
		str+=(K%2)? '7' : '4';
		K/=2;
		i--;
	}
	reverse(str.begin(),str.end());
	cout << str << endl;
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
