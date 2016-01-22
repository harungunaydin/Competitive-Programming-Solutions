#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define pb push_back

using namespace std;

vector< int > v[80005];

int n,m,Y[80005],k;

bool H[8005],h[8005];

bool solve(int part)
{
	if(part==n)
	{
		if(!H[part*2-1])
		{
			Y[++k]=part*2-1;
			return 1;
		}
		else if(!H[part*2])
		{
			Y[++k]=part*2;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int w=0;
	if(!H[part*2-1]) 
	{
		w=1;
		register int t=part*2-1,l=v[t].size();

		for(register int i=0;i<l;++i)
			H[v[t][i]]=1;

		if(solve(part+1))
		{
			Y[++k]=t;
			return 1;
		}
		for(register int i=0;i<l;++i)
			H[v[t][i]]=0;
	}
	if(!H[part*2])
	{
		w=1;
		register int t=part*2,l=v[t].size();

		for(register int i=0;i<l;++i)
			H[v[t][i]]=1;

		if(solve(part+1))
		{
			Y[++k]=t;
			return 1;
		}
		for(register int i=0;i<l;++i)
			H[v[t][i]]=0;
	}
	if(!w) return 0;
}
int main()
{
	register int i,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	if(!solve(1))
	{
		printf("NIE\n");
		return 0;
	}
	sort(Y+1,Y+k+1);
	for(i=1;i<=k;++i)
		printf("%d\n",Y[i]);
	return 0;
}
