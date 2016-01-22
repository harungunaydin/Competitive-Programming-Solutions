#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
string oyuncu1 , oyuncu2 , str;
int Q;
bool control(int a,int b,int k)
{
	if(a == b) return false;
	if(a < b && oyuncu1 == "federer") return false;
	if(b < a && oyuncu2 == "federer") return false;
	if(a < b) swap(a,b);
	if(a >= 7 && a - b > 2) return false;
	if(a >= 6 && a - b >= 2) return true;
	if(k < 3 && a == 7 && b == 6) return true;
	return false;
}
bool hallet()
{

	if(str.size() 

	if( !control(str[0]-'0',str[2]-'0',1) ) return false;

	int a(0),b(0);

	(str[0] > str[2]) ? a++ : b++;


	if( !control(str[4]-'0',str[6]-'0',2) ) return false;

	(str[4] > str[6]) ? a++ : b++;

	if(a == 1 && b == 1 && (int)str.size() <= 7) return false;

	if(a == 2 || b == 2) return ( (int)str.size() <= 7 );

	if( !control(str[8]-'0',str[10]-'0',3) ) return false;

	return true;
}
void solve()
{
	cin >> oyuncu1 >> oyuncu2;
	scanf("%d",&Q);
	int a,b;
	getline(cin,str);
	while(Q--)
	{
		getline(cin,str);
		str.resize( str.size() - 1 );

		a = b = 0;

		hallet() ? printf("da\n") : printf("ne\n");

	}
}
int main()
{
	solve();
	return 0;
}
