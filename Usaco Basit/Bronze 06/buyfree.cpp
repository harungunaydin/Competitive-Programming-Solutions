//SORU 530
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "buyfree.in"
#define OUTPUT "buyfree.out"
#define all(x) x.begin(),x.end()
#define MAXN 10000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N;
int A[MAXN+5],B[MAXN+5];
void solve()
{
	int i,j=1,s=0;
	in >> M >> N;
	FOR(i,1,M)
		in >> A[i];
	FOR(i,1,N)
		in >> B[i];
	s = M;
	sort(A+1,A+M+1,greater<int>());
	sort(B+1,B+N+1,greater<int>());
	for(i=1; i<=M && j<=N; i++,j++)
	{
		while(A[i] <= B[j] && j<=N) j++;
		s+=(j<=N);
	}
	out << s << endl;
}
int main()
{
	solve();
	return 0;
}
