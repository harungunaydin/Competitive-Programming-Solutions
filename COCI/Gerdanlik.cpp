#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define f first
#define s second
using namespace std;
pair < int , int > v[300000];
int G[50005],n,vis,A[5005][5005],sum,H[300005],_min=999999;
int solve(int ind)
{
	queue < int > q;
	q.push(ind);
	register int to,i,top=0;
	vis++;
	while(q.empty()==0)
	{
		to=q.front();
		q.pop();
		top+=G[to];
		H[to]=vis;
		for(i=1;i<=n;i++)
		{
			if(A[to][i] && H[i]!=vis)
			q.push(i);
		}
	}
	return top;
}
int main()
{
	register int i,a,b,k,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&G[i]);
		sum+=G[i];
	}
	sum;
	k=n-1;
	for(i=1;i<=k;i++)
	{
		scanf("%d %d",&a,&b);
		v[i].f=a;
		v[i].s=b;
		A[a][b]=A[b][a]=1;
	}
	for(i=1;i<=k;i++)
	{
		A[v[i].f][v[i].s]=A[v[i].s][v[i].f]=0;
		a=solve(i);
		if(abs((sum-2*abs(sum-a))) < _min )
		{
			x=v[i].f;
			y=v[i].s;
			_min=abs((sum-abs(sum-a))-abs(sum-a));
		}
		A[v[i].f][v[i].s]=A[v[i].f][v[i].s]=1;
	}
	cout << _min << " " << x << " " << y << endl;
	return 0;
}
