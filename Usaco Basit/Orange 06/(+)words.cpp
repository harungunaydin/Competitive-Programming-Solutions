//SORU 366
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "words.in"
#define OUTPUT "words.out"
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
string str;
string yon2[8] = {"S","SE","E","NE","N","NW","W","SW"};
int M,N;
char yon[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
char A[MAXN+5][MAXN+5];
string find(int x,int y)
{
	for(int i = 0,k = 0; k<8; k++,i = 0)
	{
		while(A[x+i*yon[k][0]][y+i*yon[k][1]] == str[i] && i < str.size()) i++;
		if(i == str.size()) return yon2[k];
	}
	return "";
}
void solve()
{
	string temp;	
	int i,j,t;
	in >> N >> M;
	in >> str;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
	FOR(i,1,M)
		FOR(j,1,N)
			if((temp = find(i,j)).size())
			{
				out << i << " " << j << endl << temp << endl;
				return;
			}
	
}
int main()
{
	solve();
	return 0;
}
