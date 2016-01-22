#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
//#define cin in
using namespace std;
ifstream in("mo.in");
int P;
int A[10005];
void print()
{
	int i;
	FOR(i,1,P)
		cout << A[i] << " ";
	getchar(); cout << endl;
}
bool bulbeartik(int x,int y,int s)
{
	int i;
	FOR(i,x,y)
		if(A[i]!=s)
			return 0;
	return 1;
}
void hallet(int x,int y)
{
	int i;
	FOR(i,x,y)
		A[i]=0;
}
void bitirsuisikocumbe(int x)
{
	int i,j;
	bool flag=true;
	for(i=x; i<=P && flag; i++)
		for(j=x+1; j<=P; j++)
			if(A[j]==A[x])	
			{
				if(bulbeartik(x+1,j-1,3-A[x]))
					hallet(x+1,j-1);
				flag=false;
				break;
			}
	for(i=x; i; i--)
		for(j=x-1; j; j--)
			if(A[j]==A[x])
			{
				if(bulbeartik(j+1,x-1,3-A[x]))
					hallet(j+1,x-1);
				return;
			}
}
void solve()
{
	int M,b=0,i,s=0,x;
	cin >> P >> M;
	FOR(i,1,M)
	{
		cin >> x;
		A[x]=2-(i&1);
		bitirsuisikocumbe(x);
	}
	FOR(i,1,P)
		b+=(A[i]==1),
		s+=(A[i]==2);
	cout << b << " " << s << endl;
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
