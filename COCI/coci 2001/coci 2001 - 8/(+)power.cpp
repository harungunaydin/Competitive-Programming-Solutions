#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int D[1000000],W[100000],L[10000][10000],R[10000][10000],Guc[10000][10000];
int N,V,t;
void read()
{
	int i;
	cin >> N;
	cin >> V;
	FOR(i,1,N)
	{
		cin >> D[i];
		cin >> W[i];
		t+=W[i];
	}
}
int total(int x,int y)
{
	int i,t=0;
	FOR(i,x,y)
		t+=W[i];
	return t;
}
void power()
{
	int i,j;
	FOR(i,1,N)
		FOR(j,i,N)
			Guc[i][j]=t-total(i,j);
}
int Rmin(int a,int b);
int Lmin(int a,int b)
{
	int x,y;
	if(L[a][b]) return L[a][b];
	if(a==V && b==V) return 0;
	if(a>V || b<V) return 999999999;
	x=Lmin(a+1,b)+abs(D[a+1]-D[a])*Guc[a+1][b];
	y=Rmin(a+1,b)+abs(D[b]-D[a])*Guc[a+1][b];
	return L[a][b]=min(x,y);
}
int Rmin(int a,int b)
{
	int x,y;
	if(R[a][b]) return R[a][b];
	if(a==V && b==V) return 0;
	if(a>V || b<V) return 999999999;
	x=Lmin(a,b-1)+abs(D[b]-D[a])*Guc[a][b-1];
	y=Rmin(a,b-1)+abs(D[b]-D[b-1])*Guc[a][b-1];
	return R[a][b]=min(x,y);
}
int main()
{
	int i,j;
	read();
	power();
	cout<<min(Lmin(1,N),Rmin(1,N)) << endl;
	return 0;
}
