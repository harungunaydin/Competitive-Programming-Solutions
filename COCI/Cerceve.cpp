#include<iostream>
#include<cstdio>
#include<vector>
#define control(x,y,c) ( (A[x][y]=='c' || A[x][y] == '.') && x<=n && x>=1 && y<=m && y>=1)
#define pb push_back
#define pp pop_back
using namespace std;
bool H[55][55][255];
char A[55][55],_max='A';
int n,m,cnt='A'-1;
void isUp(char c)
{
	int x,y,xx,yy,i,j,alt=0,ust=9999,sol=9999,sag=0,cot=0;
	bool w=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(A[i][j]==c)
			{
				if(sag<j) sag=j;
				if(sol>j) sol=j;
				if(ust>i) ust=i;
				if(alt<i) alt=i;
				cot=1;
			}
	if(!cot) return ;
	for(i=ust;i<=alt;i++)
	{
		if( !(A[i][sag] == c || A[i][sag] == '.' ) ) w=1;
		if( !(A[i][sol] == c || A[i][sol] == '.' ) ) w=1;
	}
	for(j=sol;j<=sag;j++)
	{
		if( !(A[ust][j] == c || A[ust][j] == '.') ) w=1;
		if( !(A[alt][j] == c || A[alt][j] == '.') ) w=1;
	}
	if(!w && ++cnt)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(A[i][j]==c)
					A[i][j]='.';
		cout << c;
	}
}
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&A[i][j]);
			_max=max(_max,A[i][j]);
		}
	while(cnt!=_max)
	{
		for(i='A';i<=_max;i++)
		{
			isUp(i);
		}
	}
	cout << endl;
	return 0;
}
