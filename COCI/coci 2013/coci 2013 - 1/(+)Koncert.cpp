#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int M,M2,N,N2;
int A[MAXN] , B[MAXN];
bool H[MAXN];
void solve()
{
	int i;
	M = read(); M2 = read();
	FOR(i,1,M2)
		A[read()]++;
	N = read(); N2 = read();
	FOR(i,1,N2)
		B[read()]++;

	FOR(i,1,N)
		while(B[i])
		{
			printf("GIVE GIRL %d GUY 1\n", i );
			A[1]++;
			B[i]--;
		}

	FOR(i,2,M)
		while(A[i])
		{
			printf("GIVE GUY %d GUY 1\n" , i );
			A[1]++;
			A[i]--;
		}

	bool flag;

	while(1)
	{
		flag = true;
		for(i = 2; A[1] > 1 && i <= M; i++) // BILETLERI MILLETE DAGIT
			if(!H[i])
			{
				printf("GIVE GUY 1 GUY %d\n" , i );
				A[1]--;
				A[i]++;
				flag = false;
			}
		if(flag) { printf("ENTER GUY 1\n"); return; }
		FOR(i,1,M) // MILLETI ICERI SOK
			if(!H[i] && A[i])
			{
				H[i] = true;
				printf("ENTER GUY %d\n" , i );
			}

		FOR(i,2,M) // BILETLERI GERI TOPLA
			if(H[i] && A[i])
			{
				A[1]++;
				A[i]--;
				printf("GIVE GUY %d GUY 1\n" , i );
			}

		printf("EXIT GUY 1\n"); // DISARI CIK

		H[1] = false;

	}


}
int main()
{
	solve();
	return 0;
}
