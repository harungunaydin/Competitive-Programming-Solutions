#include <iostream>
using namespace std;
string str[10][5];
string A[10][10];
void read()
{
	for(int i=0; i<5; i++)
		for(int j=0; j<4; j++)
			cin >> A[j][i];
}
void tut()
{
	str[0][0]="###"; str[0][1]="#.#"; str[0][2]="#.#"; str[0][3]="#.#"; str[0][4]="###";
	str[1][0]="..#"; str[1][1]="..#"; str[1][2]="..#"; str[1][3]="..#"; str[1][4]="..#";
	str[2][0]="###"; str[2][1]="..#"; str[2][2]="###"; str[2][3]="#.."; str[2][4]="###";
	str[3][0]="###"; str[3][1]="..#"; str[3][2]="###"; str[3][3]="..#"; str[3][4]="###";
	str[4][0]="#.#"; str[4][1]="#.#"; str[4][2]="###"; str[4][3]="..#"; str[4][4]="..#";
	str[5][0]="###"; str[5][1]="#.."; str[5][2]="###"; str[5][3]="..#"; str[5][4]="###";
	str[6][0]="###"; str[6][1]="#.."; str[6][2]="###"; str[6][3]="#.#"; str[6][4]="###";
	str[7][0]="###"; str[7][1]="..#"; str[7][2]="..#"; str[7][3]="..#"; str[7][4]="..#";
	str[8][0]="###"; str[8][1]="#.#"; str[8][2]="###"; str[8][3]="#.#"; str[8][4]="###";
	str[9][0]="###"; str[9][1]="#.#"; str[9][2]="###"; str[9][3]="..#"; str[9][4]="###";
}
int kontrol(int a)
{
	int i=0,j,k;
	bool flag;
	for(; i<10; i++)
	{
		flag=true;
		for(j=0; j<5 && flag; j++)
			for(k=0; k<3 && flag; k++)
				if(A[a][j][k]=='#' && str[i][j][k]=='.')
					flag=false;
		if(flag==true)
			return i;
	}
	return -1;				
}
void solve()
{
	cout << kontrol(0) << kontrol(1) << ":" << kontrol(2) << kontrol(3) << endl;
}
int main()
{
	tut();
	read();
	solve();
	return 0;
}
