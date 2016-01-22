#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 200000
using namespace std;
string B[205];
int M,N;
bool DP[200005];
char A[200005];
void read()
{
	int i;
	string str,temp;
	while(1)
	{
		cin >> B[++N];
		if(B[N] == ".") break;
	}
	N--;
	while(cin >> temp) str+=temp;
	M = str.size();
	FOR2(i,M)
		A[i+1] = str[i];
}
void solve()
{
	int i,j,k;
	DP[0] = true;
	FOR(i,0,M)
		if(DP[i])
			FOR(j,1,N)
				if(i + B[j].size() <= M)
				{
					FOR2(k,B[j].size())
						if(A[i+k+1] != B[j][k])
							break;
					if(k == B[j].size()) DP[i+k] = true;
				}
	i = M;
	while(!DP[i]) i--;
	printf("%d\n",i);
}
int main()
{
	read();
	solve();
	return 0;
}
