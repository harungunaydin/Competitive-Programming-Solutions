#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 5
using namespace std;
FILE *in,*out;
string str;
int N,res;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN+5][MAXN+5];
bool control(string str)
{
	int i,t = str.size();
	if(t&1 || t <= res ) return 0;
	FOR2(i,t/2)
		if(str[i] != '(')
			return 0;
	FOR(i,t/2,t-1)
		if(str[i] != ')')
			return 0;
	return 1;
}
void rec(int x,int y)
{
	int i,xx,yy;
	if(control(str)) res = str.size();
	char c;
	FOR2(i,4)
	{
		xx = x + yon[i][0];
		yy = y + yon[i][1];
		if(A[xx][yy])
		{
			c = A[xx][yy];
			str+=c;
			A[xx][yy] = 0;
			rec(xx,yy);
			A[xx][yy] = c;
			str.resize(str.size()-1);
		}
	}
}
void solve()
{
	int i,j;
	in = fopen("hshoe.in","r");
	out = fopen("hshoe.out","w");
	fscanf(in,"%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			fscanf(in," %c",A[i]+j);
	str+=A[1][1];
	rec(1,1);
	fprintf(out,"%d\n",res);
}
int main()
{
	solve();
	return 0;
}
