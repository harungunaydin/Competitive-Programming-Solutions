#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 200005
using namespace std;
string str,str2;
int M,N,T,vis;
int A[MAXN] , hash[MAXN];
void solve()
{
	scanf("%d %d",&M,&N);
	cin >> str >> str2;
	reverse( all(str) );
	str += str2;

	int S = M + N , i;

	FOR2(i,M) A[i] = 1;
	FOR(i,M,S-1) A[i] = 2;

	scanf("%d",&T);
	while(T--)
	{
		vis++;
		FOR2(i,S-1)
			if(hash[i] != vis && A[i] == 1 && A[i+1] == 2)
			{
				swap(str[i],str[i+1]);
				swap(A[i],A[i+1]);
				hash[i+1] = vis;
			}
	}

	cout << str << endl;

}
int main()
{
	solve();
	return 0;
}
