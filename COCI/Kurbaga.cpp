#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define f first
#define s second
using namespace std;
pair < pair < int , int > , int > A[100005];
int n,k,DP[100005][15];
bool cmp(pair < pair < int , int > , int > x ,pair < pair < int , int > , int > y)
{
	return (x.f.s > y.f.s);
}
int solve(int tas,int zip)
{
	if(DP[tas][zip]) return DP[tas][zip];
	int _max=-999999,w=0;
	for(register int i=tas+1;i<=n;i++)
	{
		if(A[i].f.f>A[tas].f.f)
		{
			w=1;
			_max=max(_max,solve(i,zip)+A[tas].s);
		}
		else if(zip)
			_max=max(_max,solve(i,zip-1)+A[tas].s);
	}
	if(_max!=-999999)
	return DP[tas][zip]=_max;
	if(!w) return DP[tas][zip]=A[tas].s;
}
int main()
{
	int i,mx=-9999;
	for(i=1;i<=n;i++)
	scanf(" %d %d",&n,&k);
		scanf("%d %d %d",&A[i].f.f,&A[i].f.s,&A[i].s);
	sort(A+1,A+n+1,cmp);
	for(i=1;i<=n;i++)
		printf("%d %d\n",A[i].f.f,A[i].f.s);
	for(i=n ;i >= 1;i--)
	{
		mx=max(mx,solve(i,k));
	}
	cout << mx << endl;
	return 0;
}
