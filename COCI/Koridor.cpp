#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define f first
#define ss second
#define add(mal,tel,ind) q.push(make_pair(mal,make_pair(tel,ind)))
using namespace std;
priority_queue<pair < int , pair < int , int > > > q;
int E[1005],v[1005][1005],n,M[1005],t,d,DP[1005][105],DD[1005][105],tar,hml,oha;
pair < int ,int > yol[1005][105];
bool H[1005][1005][105];
int solve(int ind,int tel)
{
	int a=999999,b=999999,c=999999;
	if(DP[ind][tel]!=-1){  return DP[ind][tel]; }
	if(ind==tar) { return 0; }
	if(M[ind+1]!=-1 && !H[ind][ind+1][tel])
	{
		H[ind][ind+1][tel]=1;
		a=solve(ind+1,tel)+M[ind+1];
		H[ind][ind+1][tel]=0;
		yol[ind+1][tel]=make_pair(ind,tel);
	}
	if(M[ind-1]!=-1 && ind && !H[ind][ind-1][tel])
	{
		H[ind][ind-1][tel]=1;
		b=solve(ind-1,tel)+M[ind-1];
		H[ind][ind-1][tel]=0;
		yol[ind-1][tel]=make_pair(ind,tel);
	}
	if(E[ind])
		for(int i=0;i<E[ind];i++)
		{
			c=solve(v[ind][i],tel+1)+d+tel;
			yol[v[ind][i]][tel]=make_pair(ind,tel);
		}
	return DP[ind][tel]=min(a,min(b,c));
}
void yazdir(int ind,int tel)
{

}
int main()
{
	int a,i,b,j;
	scanf("%d",&n);
	memset(DP , -1 , sizeof(DP));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		M[i]=a;
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		v[a][E[a]++]=b;
	}
	tar=n-1;
	scanf("%d",&d);
	oha=solve(0,0);
	cout << DP[0][0] << "\n";
	return 0;
}
