#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define SESSIZ(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
#define MAXN 1000
using namespace std;
int hash;
int H[MAXN+5];
void solve()
{
	int i;
	string str,temp="";
	while(cin >> str)
	{
		hash++;
		FOR(i,0,str.size()-1)
			if(i > 0 && str[i] == 'p' && H[i-1] < hash && SESSIZ(str[i-1]))
			{
				H[i] = H[i+1] = hash;
				i++;
			}
		FOR(i,0,str.size()-1)
			if(H[i] < hash)
				temp+=str[i];
		temp+=" ";
	}
	temp.resize(temp.size()-1);
	cout << temp;
}
int main()
{
	solve();
	return 0;
}
