#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define BASE 1009
#define all(x) x.begin(),x.end()
#define MAXN 1005
using namespace std;
string str[MAXN];
int H[MAXN];
int L,M,N;
int hash(string str)
{
	int t(0);
	for(int i = 0; i < (int) str.size(); i++)
		t = t * BASE + str[i];
	return t;
}
int B[MAXN] , RES[MAXN];
void solve()
{
	int a1,a2,b1,b2,i,j;
	scanf("%d %d %d",&N,&L,&M);
	FOR(i,1,N)
	{
		cin >> str[i];
		H[i] = hash( str[i] );
	}
	FOR(i,1,N)
	{
		FOR(j,1,N)
			if(H[i] == H[j])
				B[i]++;
		RES[i] = B[i];
	}

	while(M--)
	{
		scanf("%d %d %d %d",&a1,&b1,&a2,&b2);

		swap( str[a1][b1-1] , str[a2][b2-1] );

		if(a1 == a2)
		{
			FOR(i,1,N)
				if(H[i] == H[a1])
					B[i]--;

			
			H[a1] = hash(str[a1]);

			B[a1] = 1;

			FOR(i,1,N)
				if(i != a1 && H[i] == H[a1])
				{
					B[i]++;
					B[a1]++;
				}

		}
		else
		{
			if(H[a1] != H[a2])
				FOR(i,1,N)
				{
					if(H[i] == H[a1])
						B[i]--;
					if(H[i] == H[a2])
						B[i]--;
				}
			else
				FOR(i,1,N)
					if(H[i] == H[a1])
						B[i] -= 2;

			H[a1] = hash(str[a1]);
			H[a2] = hash(str[a2]);
			
			B[a1] = B[a2] = 1;
			
			if(H[a1] != H[a2])
				FOR(i,1,N)
				{
					if(i != a1 && H[i] == H[a1])
					{
						B[i]++;
						B[a1]++;
					}
					if(i != a2 && H[i] == H[a2])
					{
						B[i]++;
						B[a2]++;
					}
				}
			else
			{
				FOR(i,1,N)
					if(i != a1 && i != a2 && H[i] == H[a1])
					{
						B[i] += 2;
						B[a1]++;
					}
				B[a2] = ++B[a1];
			}
		}

		FOR(i,1,N)
			if(B[i] > RES[i])
				RES[i] = B[i];

	}

	FOR(i,1,N)
		printf("%d\n" , RES[i] );

}
int main()
{
	solve();
	return 0;
}
