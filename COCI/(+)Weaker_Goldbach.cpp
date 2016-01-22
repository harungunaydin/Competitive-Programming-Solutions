#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 500000
using namespace std;
vector < int > V;
int A[MAXN+5],DP2[MAXN+5];
bool DP[MAXN+5];
bool asal(int x)
{
	if(!(x&1)) return 0;
	int i;
	for(i = 3; i*i <= x; i+=2)
		if(!(x%i))
			return 0;
	return 1;
}
bool bul(int x)
{
	int i(x);
	if(!DP2[i]) return 0;
	while(i)
	{
		V.push_back(i - DP2[i]);
		i = DP2[i];
	}
	return 1;
}
void print()
{
	int i;
	sort( all(V) );
	printf("%d\n" , (int) V.size() );
	FOR2(i,(int)V.size())
		printf("%d%c",V[i],(i != V.size() - 1) ? ' ' : '\n');
	V.clear();
}
void knapsack()
{
	int i,j,s(0);
	FOR(i,3,5000)
		if(asal(i))
			A[++s] = i;
	DP[0] = true;
	FOR(i,1,s)
		TFOR(j,5000,A[i])
			if(DP[j-A[i]])
			{
				DP[j] = true;
				DP2[j] = j - A[i];
			}
}
void solve()
{
	int N,a,i,j;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		j = a;
		if(asal(a)) j--;
		while(1)
		{
			if(a-j >= 10 && asal(j) && bul(a-j)) break;
			V.clear();
			j--;
		}
		V.push_back(j);
		print();
	}
}
int main()
{
	knapsack();
	solve();
	return 0;
}
