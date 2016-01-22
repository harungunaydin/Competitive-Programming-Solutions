#include<iostream>
#include<cstdio>
#include<algorithm>
#define f first
#define s second
using namespace std;
pair < int , int  > A[1005];
int n,i;
int solve(int ind,int bnd)
{
	if(ind==n+1) return 0;
	int a,b;
	a=(solve(ind+1,A[ind].s) + 2*A[ind].s + A[ind].f - ((ind==1)  ? A[ind].s : (2*abs(A[ind].s-bnd))) - ( (ind==n) ? A[ind].s : 0));
  	b=(solve(ind+1,A[ind].f) + 2*A[ind].f + A[ind].s - ((ind==1)  ? A[ind].f : (2*abs(A[ind].f-bnd))) - ( (ind==n) ? A[ind].f : 0));
	cout << a << " " << b << endl;
	return max(a,b);
}
int main()
{
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> A[i].f >> A[i].s;
	cout << solve(1,0) << endl;
	return 0;
}
