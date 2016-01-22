#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N;
int A[10000];
int B[25][2][100],C[25][2];
void print()
{
	int i;
	FOR(i,1,N)
		(A[i]==1)? cout << "true\n" : cout << "false\n";
}
bool kontrol()
{
	int i,j;
	FOR(i,1,N)
		if(A[i]==1)
		{
			FOR(j,0,C[i][0]-1)
				if(A[B[i][0][j]]==2)
					return 0;
			FOR(j,0,C[i][1]-1)
				if(A[B[i][1][j]]==1)
					return 0;
		}
		else if(A[i]==2)
		{
			bool flag=true;
			FOR(j,0,C[i][0]-1)
				if(A[B[i][0][j]]==2)
					flag=false;
			if(flag)
				FOR(j,0,C[i][1]-1)
					if(A[B[i][1][j]]==1)
						flag=false;
			if(flag) return 0;
		}
	return 1;
}
void bul(int x)
{
	if(x==N+1)
	{ 
		if(kontrol()) { print(); system("PAUSE"); exit(0); }
		return;
	}
	A[x]=1; bul(x+1);
	A[x]=2; bul(x+1);
}
void solve()
{
	int i,j,k,x,y;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> x;
		FOR(j,1,x)
		{
			cin >> y;
			B[i][0][C[i][0]++]=y;
		}
		cin >> x;
		FOR(j,1,x)
		{
			cin >> y;
			B[i][1][C[i][1]++]=y;
		}
	}
	bul(1);
}
int main()
{
	solve();
	return 0;
}
