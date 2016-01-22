#include <iostream>
using namespace std;
int N;
char A[20][20];
char harf[4]={'U','L','D','R'};
void read()
{
	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=i; j++)
			cin >> A[i][j];
}
void yazdir()
{
	for(int i=1; i<=N; i++,cout << endl)
		for(int j=1; j<=i; j++)
			cout << A[i][j];
	cout << endl; getchar();
}
void kaydir(int x,int y)
{
		cout << N-x+1 << " " << y << endl;
		for(int i=0; i<4; i++)
			if(A[x-1][y]==harf[i])
			{
				A[x-1][y]=harf[(i+1)%4];
				break;
			}
		for(int i=0; i<4; i++)
			if(A[x-1][y-1]==harf[i])
			{
				A[x-1][y-1]=harf[(i+1)%4];
				break;
			}
}
void gonder(int i,int j,int x)
{
	for(int k=0; k<x; k++)
		kaydir(i,j);
}
void solve()
{
	int i=N,j;
	for(; i; i--)
		for(j=1; j<=i; j++)
			if(A[i][j]!='U')
			{
				if(A[i][j]=='L')
					gonder(i,j,1);
				else if(A[i][j]=='R')
					gonder(i,j,3);
				else if(A[i][j]=='D')
					gonder(i,j,2);
			}
}
int main()
{
	read();
	solve();
	return 0;
}
