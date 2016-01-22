#include<iostream>
#include<queue>
#include<cstdio>
#define se second
#define f first
#define mp make_pair
#define add(s,x,y,ss,xx,yy) qa.push(mp(s,mp(x,y))),qb.push(mp(ss,mp(xx,yy)))
#define control1(x,y) (x>=1 && x<=n && y>=1 && y<=m && A[x][y]!='#' && !h[x][y])
#define control2(x,y) (x>=1 && x<=n && y>=1 && y<=m && B[x][y]!='#' && !h[x][y])
using namespace std;
queue < pair < int , pair < int , int > > > qa,qb;
string ssa,ssb;
char A[15][15],B[15][15];
bool H[15][15][15][15],h[15][15];
int n,m,yol[15][15],yolb[15][15],ax,ay,bx,by;
bool wa,wb;
void yazdira(int x,int y)
{
	if(x==ax && y==ay) return;
	switch(yol[x][y])
	{
		case 1: yazdira(x,y+1); ssa+="b"; break;
		case 2: yazdira(x+1,y); ssa+="k"; break;
		case 3: yazdira(x,y-1); ssa+="d"; break;
		case 4: yazdira(x-1,y); ssa+="g"; break;
	}
}
void yazdirb(int x,int y)
{
	if(x==bx && y==by) return;
	switch(yolb[x][y])
	{
		case 1: yazdirb(x,y+1); ssb+="d"; break;
		case 2: yazdirb(x+1,y); ssb+="g"; break;
		case 3: yazdirb(x,y-1); ssb+="b"; break;
		case 4: yazdirb(x-1,y); ssb+="k"; break;
	}
}
int solve()
{
	int x,y,xx,yy,s,ss;
	while(qa.empty()==0)
	{
		if(!wa)
		{
			x=qa.front().se.f;
			y=qa.front().se.se;
		}
			s=qa.front().f;
			ss=qb.front().f;
		if(!wb)
		{
			xx=qb.front().se.f;
			yy=qb.front().se.se;
		}
		qa.pop();
		qb.pop();
		if(H[x][y][xx][yy])
			continue;
		H[x][y][xx][yy]=1;
		if(A[x][y]=='E')
			wa=1;


		
		if(wa)
		{
			int t=solvea(xx,yy)+s;
			if(t==s)
				return 0;
			yazdira(x,y);
			return t;
		}
		if(wb)
		{
			int t=solvea(x,y)+ss;
			if(t==ss)
				return 0;
			return t;
		}
		if(control1(x+1,y) && control2(xx-1,yy))	{ yol[x+1][y]=4; add(s+1,x+1,y,ss+1,xx-1,yy); }
		else if(control1(x+1,y) && !control2(xx-1,yy))	{ yol[x+1][y]=4; add(s+1,x+1,y,ss+1,xx,yy); }
		else if(!control1(x+1,y) && control2(xx-1,yy))	add(s+1,x,y,ss+1,xx-1,yy);

		if(control1(x,y-1) && control2(xx,yy+1))	{ yol[x][y-1]=1; add(s+1,x,y-1,ss+1,xx,yy+1); }
		else if(control1(x,y-1) && !control2(xx,yy+1))	{ yol[x][y-1]=1; add(s+1,x,y-1,ss+1,xx,yy); }
		else if(!control1(x,y-1) && control2(xx,yy+1))	add(s+1,x,y,ss+1,xx,yy+1);

		if(control1(x,y+1) && control2(xx,yy-1))	{ yol[x][y+1]=3; add(s+1,x,y+1,ss+1,xx,yy-1); }
		else if(control1(x,y+1) && !control2(xx,yy-1))	{ yol[x][y+1]=3; add(s+1,x,y+1,ss+1,xx,yy); }
		else if(!control1(x,y+1) && control2(xx,yy-1))	add(s+1,x,y,ss+1,xx,yy-1);

		if(control1(x-1,y) && control2(xx+1,yy))	{ yol[x-1][y]=2; add(s+1,x-1,y,ss+1,xx+1,yy); }
		else if(control1(x-1,y) && !control2(xx+1,yy))	{ yol[x-1][y]=2; add(s+1,x-1,y,ss+1,xx,yy); }
		else if(!control1(x-1,y) && control2(xx+1,yy))	add(s+1,x,y,ss+1,xx+1,yy);

	}
	return 0;
}
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&A[i][j]);
			if(A[i][j]=='R')
			{
				ax=i;
				ay=j;
				qa.push(mp(0,mp(i,j)));
			}
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&B[i][j]);
			if(B[i][j]=='R')
			{
				bx=i;
				by=j;
				qb.push(mp(0,mp(i,j)));
			}
		}
	int tt=solve();
	printf("%d\n",tt);
	if(!tt) return 0;
	cout << ssa << ssb << endl;
	return 0;
}
