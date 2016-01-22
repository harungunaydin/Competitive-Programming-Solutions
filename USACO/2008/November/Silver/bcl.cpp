//SORU 930
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "bcl.in"
#define OUTPUT "bcl.out"
#define MAXN 5000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int line;
char A[MAXN+5];
void yazdir(char a)
{
	if(line == 80) { out << endl; line = 0; }
	out << a;
	line++;
}
void solve()
{
	int N,bas,i,j,son;
	in >> N;
	FOR(i,1,N)
		in >> A[i];
	bas = 1;
	son = N;
	while(bas<=son)
	{
		if(A[bas] < A[son]) yazdir(A[bas]),bas++;
		else if(A[bas] > A[son]) yazdir(A[son]),son--;
		else
		{
			i = bas+1; j = son-1;
			while(j-i > 1 && A[i] == A[j]) i++,j--;
			if(A[i] > A[j]) yazdir(A[bas]),son--;
			else yazdir(A[bas]),bas++;
		}
	}
}
int main()
{
	solve();
	return 0;
}
