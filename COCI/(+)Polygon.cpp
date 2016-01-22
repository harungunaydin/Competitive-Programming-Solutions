#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool solve()
{
	int N,a,b,c;
	int A[5];
	scanf("%d",&N);
	scanf("%d %d %d",A+1,A+2,A+3);
	sort(A+1,A+4); a = A[1]; b = A[2]; c = A[3];
	if(( !a && b == 1 && c == N - 1 ) || ( !a && b == N - 2 && c == N - 1 ) || (a == b - 1 && b == c - 1 )) return 1;
	return !(N&1);
}
int main()
{
	cout << (solve() ? "TAK" : "NIE");
	return 0;
}
