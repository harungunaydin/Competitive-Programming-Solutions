/*
ID : harung91
PROG : castle
LANG : C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 50
#define INPUT "castle.in"
#define OUTPUT "castle.out"
#define KONTROL(x,y) (x>=1 && x<=M && y>=1 && y<=N && !visited[x][y])
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N,k,s;
int ODA[MAXN*MAXN+5];
int A[MAXN+5][MAXN+5],B[MAXN+5][MAXN+5];
bool visited[MAXN+5][MAXN+5];
void read()
{
	int i,j;
	in >> N >> M;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
}
void rec(int x,int y)
{
	k++;
	B[x][y] = s;
	visited[x][y] = true;
	if(!(A[x][y]&1) && KONTROL(x,y-1)) rec(x,y-1);
	if(!(A[x][y]&2) && KONTROL(x-1,y)) rec(x-1,y);
	if(!(A[x][y]&4) && KONTROL(x,y+1)) rec(x,y+1);
	if(!(A[x][y]&8) && KONTROL(x+1,y)) rec(x+1,y);
}
void Which_Wall()
{
	int cur,i,j,maxi=0,resx,resy;
	char yon;
	FOR(i,1,N)
		TFOR(j,M,1)
		{
			cur = B[j][i];
			if(A[j][i]&1 && B[j][i-1]!=cur && ODA[B[j][i-1]]+ODA[cur] > maxi)
			{
				maxi = ODA[cur]+ODA[B[j][i-1]];
				resx = j; resy = i; yon = 'W';
			}
			if(A[j][i]&8 && B[j+1][i]!=cur && ODA[B[j+1][i]]+ODA[cur] > maxi)
			{
				maxi = ODA[cur]+ODA[B[j+1][i]];
				resx = j; resy = i; yon = 'S';
			}
			if(A[j][i]&2 && B[j-1][i]!=cur && ODA[B[j-1][i]]+ODA[cur] > maxi)
			{
				maxi = ODA[cur] + ODA[B[j-1][i]];
				resx = j; resy = i; yon = 'N';
			}
			if(A[j][i]&4 && B[j][i+1]!=cur && ODA[B[j][i+1]]+ODA[cur] > maxi)
			{
				maxi = ODA[cur]+ODA[B[j][i+1]];
				resx = j; resy = i; yon = 'E';
			}
			
		}
	out << maxi << endl << resx << " " << resy << " " << yon << endl;
}
int main()
{
	int i,j,maxi=0;
	read();
	FOR(i,1,M)
		FOR(j,1,N)
			if(!visited[i][j])
			{
				s++;
				rec(i,j);
				ODA[s] = k;
				maxi = max(maxi,k);
				k = 0;
			}
	out << s << endl << maxi << endl;
	Which_Wall();
	return 0;
}
