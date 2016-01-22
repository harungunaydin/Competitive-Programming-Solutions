#include <iostream>
#include <climits>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define KONTROL(x,y) (x>0 && x<=M && y>0 && y<=N && !hash[A[x][y]])
using namespace std;
int M,N,maxi=INT_MIN;
char A[1000][1000];
bool hash[1000];
int izracunaj(int x,int y,int s)
{
	bool flag=true;
	if(KONTROL(x-1,y))
	{
		flag=false;
		hash[A[x-1][y]]=true;
		izracunaj(x-1,y,s+1);
		hash[A[x-1][y]]=false;
	}
	if(KONTROL(x,y+1))
	{
		flag=false;
		hash[A[x][y+1]]=true;
		izracunaj(x,y+1,s+1);
		hash[A[x][y+1]]=false;
	}
	if(KONTROL(x+1,y))
	{
		flag=false;
		hash[A[x+1][y]]=true;
		izracunaj(x+1,y,s+1);
		hash[A[x+1][y]]=false;
	}
	if(KONTROL(x,y-1))
	{
		flag=false;
		hash[A[x][y-1]]=true;
		izracunaj(x,y-1,s+1);
		hash[A[x][y-1]]=false;
	}
	if(flag) maxi=max(maxi,s);
}
void solve()
{
	int i,j;
	cin >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			cin >> A[i][j];
	hash[A[1][1]]=true;
	izracunaj(1,1,1);
	cout << maxi << endl;
}
int main()
{
	solve();
	return 0;
}
