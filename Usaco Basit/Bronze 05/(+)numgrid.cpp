//SORU 479
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "numgrid.in"
#define OUTPUT "numgrid.out"
#define MAXN 5
#define KONTROL(x,y) (x>=1 && x<=MAXN && y>=1 && y<=MAXN && !hash[x][y])
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
set <string> st;
string str;
int N;
int A[MAXN+5][MAXN+5],yon[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };
bool hash[MAXN+5][MAXN+5];
void read()
{
	int i,j;
	FOR(i,1,MAXN)
		FOR(j,1,MAXN)
			in >> A[i][j];
}
void solve(int x,int y)
{
	if(str.size() == 6) { st.insert(str); return; }
	for(int i=0; i<4; i++)
		if(KONTROL(x+yon[i][0],y+yon[i][1]))
		{
			str+=A[x][y]+'0';
			solve(x+yon[i][0],y+yon[i][1]);
			str.resize(str.size()-1);
		}
}
int main()
{
	read();
	int a,b,i,j;
	FOR(i,1,MAXN)
		FOR(j,1,MAXN)
			solve(i,j);
	out << st.size() << endl;
	return 0;
}
