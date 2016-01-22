#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int hesapla(int x,int y,int s)
{
	int i,j=y,top=0;
	for(i=x; 1; i++,j=0)
		for(; j<60; j++)
		{
			top+=(i>6 && i<19)? 10 : 5;
			if(!(--s)) return top;
		}
}
void solve()
{
	int N,i,top=0,x,y,s;
	char c;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> x >> c >> y >> s;
		top+=(x==23)? s*5 : hesapla(x,y,s);
	}
	cout << top << endl;
}
int main()
{
	solve();
	return 0;
}
