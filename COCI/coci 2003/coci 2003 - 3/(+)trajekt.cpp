#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
ifstream in("trajekt.in");
int M,N,t;
int A[5005][4],B[5005][4];
void bul1(int a,int x)
{
	int i;
	FOR(i,1,M)
		if(x+t<=B[i][1] && !B[i][3])
		{
			A[a][2]=B[i][3]=1;
			return;
		}
}
void bul2(int a,int x)
{
	int i;
	FOR(i,1,N)
		if(x+t<=A[i][1] && !A[i][3])
		{
			B[a][2]=A[i][3]=1;
			return;
		}
}
void solve()
{
	int i,s=0,x,y;
	char c;
	cin >> t >> i;
	t+=i;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> x >> c >> y;
		A[i][1]=x*60+y;
	}
	cin >> M;
	FOR(i,1,M)
	{
		cin >> x >> c >> y;
		B[i][1]=x*60+y;
	}
	FOR(i,1,N)
		bul1(i,A[i][1]);
	FOR(i,1,M)
		if(!B[i][2])
			bul2(i,B[i][1]);
	FOR(i,1,N)
		s+=!A[i][3];
	FOR(i,1,M)
		s+=!B[i][3];
	cout << s << endl;
}
int main()
{
	solve();
	return 0;
}
