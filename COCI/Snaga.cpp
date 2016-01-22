#include<iostream>
#include<cstdio>
#include<map>
#define inf 10000000000
using namespace std;
unsigned long long a,b,sum;
int A[12];
map<int ,int > DP;
int f(int x)
{
	if(DP[x]) return DP[x];
	if(x==2) return 1;
	register unsigned long long k;
	for(k=2;k<x;k++)
		if(x%k) break;
	return DP[x]=f(k)+1;
}
int main()
{
    register unsigned long long i,j,k,cnt;
	cin >> a >> b;
	for(i=a;i<=b;i++)
	{
		sum+=f(i);
	}
	cout << sum << endl;
    return 0;
}
