#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V;
int K,a,b;
double d;
int B[100005];
char A[100005];
int uzaklik(int x1,int y1,int x2,int y2)
{
	return (abs(x1-x2)<=1 && abs(y2-y1)<=1);
}
void solve()
{
	int a,b,i,k=0,x=0,y=0;
	char c;
	bool flag=true;
	cin >> a >> b;
	cin >> K;
	FOR(i,0,K-1)
	{
		cin >> c;
		if(uzaklik(x,y,a,b)) { flag=false; cout << i << endl; }
		if(c=='I') x++;
		if(c=='S') y++;
		if(c=='Z') x--;
		if(c=='J') y--;
	}
	if(flag) cout << -1 << endl;
	else if(uzaklik(x,y,a,b)) cout << i << endl;
}
int main()
{
	solve();
	return 0;
}

