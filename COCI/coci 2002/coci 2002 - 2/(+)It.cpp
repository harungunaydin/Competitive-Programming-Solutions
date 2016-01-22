#include <iostream>
using namespace std;
char A[10][10];
int K[]={0,3,3,2,1};
int K2[]={0,0,0,0,1,2,3,3};
void at(int x,char c)
{
	for(int i=6; i; i--)
		if(!A[i][x])
		{
			A[i][x]=c;
			return;
		}
}
void yazdir()
{
	for(int i=1; i<7; i++,cout << endl)
		for(int j=1; j<8; j++)
			(A[i][j])? cout << A[i][j] << " " : cout << "0 ";
	cout << endl << endl;
}
int kontrol()
{
	for(int i=1; i<7; i++)
		for(int j=1; j<5; j++)
			if(A[i][j] && A[i][j]==A[i][j+1] && A[i][j+1]==A[i][j+2] && A[i][j+2]==A[i][j+3])
				return 2-(A[i][j]=='+');
	return 0;
}
int kontrol2()
{
	for(int i=1; i<8; i++)
		for(int j=1; j<4; j++)
			if(A[j][i] && A[j][i]==A[j+1][i] && A[j+1][i]==A[j+2][i] && A[j+2][i]==A[j+3][i])
				return 2-(A[j][i]=='+');
	return 0;
}
int kontrol3()
{
	for(int i=1; i<5; i++)
		for(int j=1; j<=K[i]; j++)
			if(A[j][i+j-1] && A[j][i+j-1]==A[j+1][i+j] && A[j+1][i+j]==A[j+2][i+j+1] && A[j+2][i+j+1]==A[j+3][i+j+2])
				return 2-(A[j][i+j-1]=='+');
	if(A[2][1] && A[2][1]==A[3][2] && A[3][2]==A[4][3] && A[4][3]==A[5][4])
		return 2-(A[2][1]=='+');
	if(A[3][2] && A[3][2]==A[4][3] && A[4][3]==A[5][4] && A[5][4]==A[6][5])
		return 2-(A[3][2]=='+');
	if(A[3][1] && A[3][1]==A[4][2] && A[4][2]==A[5][3] && A[5][3]==A[6][4])
		return 2-(A[3][1]=='+');
	for(int i=1;i<8; i++)
		for(int j=1; j<7; j++)
			if(A[i][j] && A[i][j] == A[i+1][j-1] && A[i][j] == A[i+2][j-2] && A[i][j] == A[i+3][j-3])
				return 2-(A[i][j]=='+');
	return 0;
}
void solve()
{
	int a,i=1,x,y;
	for(; i<22; i++)
	{
		cin >> x >> y;
		at(x,'+');
		a=kontrol();
		if(!a) a=kontrol2();
		if(!a) a=kontrol3();
		if(a==1) { cout << "mirko " << i << endl; return; }
		if(a==2) { cout << "slavko " << i << endl; return; }
		at(y,'-');
		a=kontrol();
		if(!a) a=kontrol2();
		if(!a) a=kontrol3();
		if(a==1) { cout << "mirko " << i << endl; return; }
		if(a==2) { cout << "slavko " << i << endl; return; }
	}
	cout << "remi" << endl;
}
int main()
{
	solve();
	return 0;
}
