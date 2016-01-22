#include<iostream>
#include<set>
#include<cstdio>
#define inf 999999999
#define f first
#define s second
#define add(x,y) st.insert(make_pair(x,y))
using namespace std;
int A[1005][1005],n,m;
bool H[1004][1003];
set < pair <int , int > > st;
set < pair <int , int > > :: iterator it;
int main()
{
	register int i,j,k,a,b,c,w;
	scanf("%d %d",&n,&m);
	for(i=0;i<500;i++)
		for(j=0;j<500;j++)
			A[i][j]=inf;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		A[a][b]=c;
		H[a][b]=1;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(A[i][j]>=A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					if(H[i][j])
					add(i,j);
					H[i][j]=0;
				}
	printf("%d\n",st.size());
	for(it=st.begin();it!=st.end();it++)
		printf("%d %d\n",(*it).f,(*it).s);
	return 0;
}
