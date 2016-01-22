	#include<iostream>
	#include<cstdio>
	#include<queue>
	#define mp make_pair
	#define f first
	#define ss second
	#define add(s,x,y,g) q.push(mp( mp(-(s),(x)) ,  mp((y),(g)) ))
	#define control(x,y) (x>=1 && x<=n && y>=1 && y<=m)
	using namespace std;

	priority_queue < pair < pair < int , int > , pair < int , int > > > q;
	int n,m,T,G,A[105][105],yon[4][2]={{1,0},{0,1},{-1,0},{0,-1}},deger[55][55],cnt;
	bool H[65][70][55][55];
	
	int solve()
	{
		add(0,1,1,0);
		register int x,y,g,s,i,xx,yy,w,j,o,t;
		while(q.empty()==0)
		{
			s=-(q.top().f.f);
			x=q.top().f.ss;
			y=q.top().ss.f;
			g=q.top().ss.ss;
			q.pop();
			printf("%d ",g);
			if(0 && x==1 && y==1)
				return s;
			H[s%60][g][x][y]=1;
			for(i=0;i<4;++i)
			{
				xx=yon[i][0],yy=yon[i][1];
				if(control(x+xx,y+yy))
				{
					if(((!A[x+xx][y+yy])|| (A[x+xx][y+yy]>0 && (s+1)%A[x+xx][y+yy])) && !H[s%60][g][x+xx][y+yy])
					{
						H[s%60][g][x+xx][y+yy]=1;
						add(s+1,x+xx,y+yy,g);
					}
					if(A[x+xx][y+yy] && !((s+1)%A[x+xx][y+yy]) && (s+2)%A[x+xx][y+yy] && !H[s%60][g][x+xx][y+yy] && ((A[x][y] && (s+1)%A[x][y]) || A[x][y]<=0 ))
					{
						H[s%60][g][x+xx][y+yy]=1;
						add(s+2,x+xx,y+yy,g);
					}
					t = 1 << deger[x+xx][y+yy];
					if(A[x+xx][y+yy]==-1 && !H[s%60][g & t][x+xx][y+yy])
					{
						H[s%60][g+t][x+xx][y+yy]=1;
						add(s+1,x+xx,y+yy,g+t);
					}
				}
			}
		}
	}
	int main()
	{
		register int i,j,a,b,c;
		scanf("%d %d %d",&n,&m,&T);
		for(i=0;i<T;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			A[a][b]=c;
		}
		scanf("%d",&G);
		for(i=0;i<G;i++)
		{
			scanf("%d %d",&a,&b);
			A[a][b]=-1;
			deger[a][b]=1+i;
		}
		printf("%d\n",solve());
		return 0;
	}
