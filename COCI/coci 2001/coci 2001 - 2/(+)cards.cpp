#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
//#define cin in
#define f first
#define s second
using namespace std;
ifstream in("cards.in");
pair <int,int> p[10000];
int b,C,N,x;
int A[100000],B[10000],perm[10];
int BS(int bas,int son)
{
	int orta=(bas+son)/2;
	return (bas==son)? bas : (A[orta]<x)? BS(orta+1,son): BS(bas,orta);
}
int LIS()
{
	int a,i,maxi=1;
	FOR(i,1,b)
	{
		x=B[i];
		a=BS(1,maxi);
		maxi+=(A[a])? 0 : 1;
		A[a]=x;
	}
	FOR(i,1,b) A[i]=B[i]=0;
	return b-maxi+1;
}
int bul(int x)
{
	int i;
	FOR(i,1,C)
		if(perm[i]==x)
			return i;
	return 0;
}
void hesapla()
{
	int i;
	FOR(i,1,b)
		B[i]=(bul(p[i].f)-1)*N+p[i].s;
}
void solve()
{
	int i,mini=10000000;
	cin >> C >> N;
	b=C*N;
	FOR(i,1,C) perm[i]=i;
	FOR(i,1,b)
		cin >> p[i].f >> p[i].s;
	do
	{
		hesapla();
		mini=min(mini,LIS());
	}while(next_permutation(perm+1,perm+C+1));
	cout << mini << endl;
}
int main()
{
	solve();
	return 0;
}
