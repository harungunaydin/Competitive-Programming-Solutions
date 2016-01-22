#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 9
using namespace std;
char A[MAXN+5][MAXN+5];
bool hash[MAXN+5][MAXN+5];
void hashing(int x,int y)
{
	int i;
	FOR2(i,MAXN)
		hash[x][i] = hash[i][y] = true;
}
void erase()
{
	int i,j;
	FOR2(i,MAXN)
		FOR2(j,MAXN)
			hash[i][j] = false;
}
bool kontrol(int a,int b,int x1,int y1,int x2,int y2)
{
	int i,j;
	FOR(i,x1,x2)
		FOR(j,y1,y2)
			if(a!=i && b!=j && !hash[i][j] && A[i][j] == '.' )
				return 0;
	return 1;
}
bool cont(int x1,int y1,int x2,int y2,char c)
{
	int i,j;
	FOR(i,x1,x2)
		FOR(j,y1,y2)	
			if(A[i][j] == c || (!hash[i][j] && A[i][j] == '.'))
				return 1;
	return 0;
}
bool satir_ve_sutun(int x,char c)
{
	int i;
	FOR2(i,MAXN)
		if(A[x][i] == c || (!hash[x][i] && A[x][i] == '.'))
			return 0;
	FOR2(i,MAXN)
		if(A[i][x] == c || (!hash[i][x] && A[i][x] == '.'))
			return 0;
	return 1;
}
bool control(char c)
{
	int i,j;
	for(i=0; i<MAXN; i+=3)
		for(j=0; j<MAXN; j+=3)
			if(!cont(i,j,i+2,j+2,c))
				return 1;
	FOR2(i,MAXN)
		if(satir_ve_sutun(i,c))
			return 1;
	return 0;
}
bool first_error_control()
{
	int i,j,k,l;
	int T[15];
	char t;
	FOR2(i,MAXN)
		FOR2(j,MAXN)
			if(A[i][j] != '.')
			{
				t = A[i][j];
				FOR2(k,MAXN)
					if(i!=k && A[k][j] == t)
						return 0;
				FOR2(k,MAXN)
					if(j!=k && A[i][k] == t)
						return 0;
			}
	for(i=0; i<MAXN; i+=3)
		for(j=0; j<MAXN; j+=3)
		{
			fill(T,T+11,0);
			FOR(k,i,i+2)
				FOR(l,j,j+2)
					if(A[k][l] != '.' && ++T[A[k][l]-'0'] > 1)
						return 0;
		}
	return 1;
}
bool kont(int x,int y,char c)
{
	int a=(x/3)*3,b=(y/3)*3,i,j;
	FOR(i,a,a+2)
		FOR(j,b,b+2)
			if( !(i == x && j == y) && (  ( !hash[i][j] && A[i][j] == '.') || A[i][j] == c ))
				return 0;
	return 1;
}
bool solve()
{
	int a,b,i,j,k,x,y;
	char bekci,c;
	FOR2(i,MAXN)
		FOR2(j,MAXN)
			scanf(" %c",A[i]+j);
	bekci = first_error_control();
	if(!bekci) return 0;
	int s = 0;
	while(bekci)
	{
		bekci = false;
		FOR(c,'1','9')
		{
			erase();
			FOR2(i,MAXN)
				FOR2(j,MAXN)
					if(A[i][j] == c)
					{
						hashing(i,j);
						break;
					}
			if(control(c)) return 0;
			FOR2(i,MAXN)
				FOR2(j,MAXN)
					if(!hash[i][j] && A[i][j] == '.')
						if(kont(i,j,c))
							A[i][j] = bekci = c;
		}
	}
	return 1;
}
void print()
{
	int i,j;
	for(i=0; i<MAXN; i++,printf("\n"))
		FOR2(j,MAXN)
			cout << A[i][j];
}
int main()
{
	if(solve())
		print();
	else
		printf("ERROR\n");
	return 0;
}
