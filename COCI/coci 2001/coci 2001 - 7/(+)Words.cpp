#include <iostream>
#include <climits>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define harf(x) (x=='A')? 0 : (x=='E')? 1 : (x=='I')? 2 : (x=='O')? 3 : 4;
using namespace std;
int N;
int A[50][50][50],B[100][100];
int izracunaj(int bas)
{
	int son,maxi=0;
	FOR(son,0,4)
	{
		if(!B[bas][son]) continue;
		B[bas][son]--;
		maxi=max(maxi,A[bas][son][B[bas][son]]+izracunaj(son));
		B[bas][son]++;
	}
	return maxi;
}
void solve()
{
	int bas,i,j,maxi=0,son;
	string str;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> str;
		j=str.size();
		bas=harf(str[0]);
		son=harf(str[j-1]);
		A[bas][son][B[bas][son]]=j;
		B[bas][son]++;
	}
	FOR(i,0,4)
		FOR(j,0,4)
			sort(A[i][j],A[i][j]+B[i][j]);
	FOR(i,0,4)
		maxi=max(maxi,izracunaj(i));
	cout << maxi << endl;
}
int main()
{
	solve();
	return 0;
}
