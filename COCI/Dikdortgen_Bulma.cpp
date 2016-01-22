#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
class ii
{
	public:
	int x,y;
};
int n,k,sayac;
ii A[5005];
int main()
{
	register int i,j,cnt,x1,y1,x2,y2,l,cx,cy;
	scanf("%d %d",&n,&k);
	k-=2;
	for(i=1;i<=n;i++)
		scanf("%d %d",&A[i].x,&A[i].y);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(i==j) continue;
			x1=A[i].x;
			y1=A[i].y;
			
			x2=A[j].x;
			y2=A[j].y;
			if( (x1<x2 && y1>y2) || (x1>x2 && y1<y2))
			{
				if(x1>x2) swap(x1,x2);
				if(y1>y2) swap(y1,y2);
				cnt=k;
				for(l=1;l<=n;l++)
				{
					if(l==i || l==j) continue;
					cx=A[l].x;
					cy=A[l].y;
					if(cx>=x1 && cx<=x2 && cy>=y1 && cy<=y2 && (cx==x1 || cx==x2 || cy==y1 || cy==y2) )
					{	
						cnt--;
						if(!cnt)
						{
							sayac++;
							break;
						}
					}
				}
			}
		}
	}
	printf("%d\n",sayac);
	return 0;
}
