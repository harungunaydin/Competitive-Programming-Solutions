#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
using namespace std;
int asal[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector < int > v;
int DP[1005];
int main()
{
	register int a,i,n,j;
	scanf("%d",&n);
	a=n;
	for(i=0;i<=100;i++)
		if(asal[i] && n-asal[i]>0)
			v.pb(asal[i]);	
	DP[0]=1;
	for(i=0;i<v.size();i++)
		for(j=v[i];j<=n;j++)
		{
			DP[j]+=DP[j-v[i]];
		}
	printf("%d",DP[n]);
	return 0;
}
