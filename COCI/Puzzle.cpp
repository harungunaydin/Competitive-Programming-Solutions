#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int A[5][9][25][25],G[25][25],Temp[25][25],yerler[4]={1,2,3,4},Mat[50][50];
int n;
void yap(int t)
{
	register int dort=4,cnt=0,i,jj,j,ii;
	while(dort--)
	{
		cnt++;
		for(i=1;i<=n;i++)
			for(j=1;i<=n;++j)
				A[t][cnt][i][j]=G[i][j];
		cnt++;
	}
}
void yazdir()
{
	register int i,j;
	for(i=1;i<2*n;i++,printf("\n"))
		for(j=1;j<2*n;j++)
			printf("%d ",Mat[i][j]);
}
void bak(int i,int ii,int j,int jj,int t,int cnt)
{
	register int a,b,aa,bb;
	for(a=i,aa=1;a<=ii;a++,aa++)
		for(b=j,bb=1;b<=jj;b++,bb++)
			if(A[t][cnt][aa][bb] && !Mat[a][b])
			Mat[a][b]=A[t][cnt][aa][bb];
}
bool control()
{
	register int i,j;
	for(i=1;i<2*n;i++)
		for(j=1;j<2*n;j++)
				if(!Mat[i][j])
					return 0;
	return 1;
}
int main()
{
	register int i,j,k,l,a,b,c,d,w,ii,jj;
	scanf("%d",&n);
	for(k=1;k<=4;k++)
	{
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				scanf("%d",&G[i][j]);
		yap(k);
	}
	for(k=1;k<=4;k++)
	{
		for(ii=1;ii<=8;++ii,printf("\n"))
		for(i=1;i<=n;++i,printf("\n"))
			for(j=1;j<=n;++j)
				printf("%d ",A[k][ii][i][j]);
	}
	do
	{
		for(a=1;a<=8;a++)
			for(b=1;b<=8;b++)
				for(c=1;c<=8;c++)
					for(d=1;d<=8;d++)
					{
						memset(Mat , 0 , sizeof(Mat));
						bak(1,n,1,n,yerler[0],a);
						bak(1,n,n,2*n-1,yerler[1],b);
						bak(n,2*n-1,1,n,yerler[2],c);
						bak(n,2*n-1,n,n*2-1,yerler[3],d);
						if(control())
						{
							yazdir();
							return 0;
						}
					}
	}
	while(next_permutation(yerler,yerler+4));
	return 0;
}
