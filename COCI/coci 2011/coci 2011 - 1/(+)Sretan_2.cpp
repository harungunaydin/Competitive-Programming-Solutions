#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	string str = "";
	long long N,k(2),s(1);
	int i;
	bool flag = false;
	scanf("%lld",&N);
	while(1)
	{
		if(N <= k) break;
		N-=k;
		k<<=1;
		s++;
	}
	k>>=1;
	if(N <= k)
	{
		N--;
		for(i=0; i<s; i++)
		{
			k = N&1;
			N>>=1;
			str+=( (!k) ? '4' : '7');
		}
		reverse(all(str));
		cout << str << endl;
		return;
	}
	k+=(N-k-1);
	while(k)
	{
		str+=(k&1) ? '7' : '4';
		k>>=1;
	}
	reverse(all(str));
	cout << str << endl;
}
int main()
{
	solve();
	return 0;
}
