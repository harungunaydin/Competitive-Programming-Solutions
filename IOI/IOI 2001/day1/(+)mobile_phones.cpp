#include <cstdio>
#define MAXN 1025
int F[MAXN][MAXN];
void solve()
{
	int S,a,i,j,k,res,x1,x2,y1,y2;
	scanf("%d %d",&a,&S);
	while(1)
	{
		scanf("%d",&k);
		if(k == 1)
		{
			scanf("%d %d %d",&x1,&y1,&a);
			x1++; y1++;
			for(i = x1; i ; i-=i&-i)
				for(j = y1; j ; j-=j&-j)
					F[i][j] += a;
		}
		else if(k == 2)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1++; y1++; x2++; y2++;
			res = 0;
			for(i = x1; i <= S; i+=i&-i)
			{
				for(j = y1; j <= S; j+=j&-j)
					res += F[i][j];
				for(j = y2 + 1; j <= S; j+=j&-j)
					res -= F[i][j];
			}
			for(i = x2 + 1; i <= S; i+=i&-i)
			{
				for(j = y1; j <= S; j+=j&-j)
					res -= F[i][j];
				for(j = y2 + 1; j <= S; j+=j&-j)
					res += F[i][j];
			}
			printf("%d\n" , res );
		}
		else break;
	}
}
main()
{
	solve();
}
