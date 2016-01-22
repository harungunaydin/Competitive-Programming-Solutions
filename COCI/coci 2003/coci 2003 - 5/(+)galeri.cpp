#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N;
char A[1005][1005];
void read()
{
	int i,j;
	cin >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			cin >> A[i][j];
}
void solve()
{
	int i,j,k,s=0;
	FOR(i,1,M)
		FOR(j,1,N)
		{
			if(A[i+1][j]=='.' || A[i][j]=='X') k=0;
			if(A[i][j]=='.' && A[i+1][j]=='X') k++;
			if(k==2) { k=0,s++; }
		}
	k=0;
	FOR(i,1,M)
		FOR(j,1,N)
		{
			if(A[i-1][j]=='.' || A[i][j]=='X') k=0;
			if(A[i][j]=='.' && A[i-1][j]=='X') k++;
			if(k==2) { k=0,s++; }
		}
	k=0;
	FOR(j,1,N)
		FOR(i,1,M)
		{
			if(A[i][j-1]=='.' || A[i][j]=='X') k=0;
			if(A[i][j]=='.' && A[i][j-1]=='X') k++;
			if(k==2) { k=0,s++; }
		}
	k=0;
	FOR(j,1,N)
		FOR(i,1,M)
		{
			if(A[i][j+1]=='.' || A[i][j]=='X') k=0;
			if(A[i][j]=='.' && A[i][j+1]=='X') k++;
			if(k==2) { k=0,s++; }
		}
	cout << s << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
