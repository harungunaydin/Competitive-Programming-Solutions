#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 2000000000
#define MAXN 250
using namespace std;
double S;
double B[MAXN+5];
double A[MAXN+5][20];
int RES[MAXN+5];
void solve()
{
	double a,maxi;
	int N,i,j,k,t,t2;
	char c;
	FOR(i,'A','Z') B[i] = -1;
	cin >> S;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> c >> a;
		B[c] = a;
		FOR(j,1,14)
			A[c][j] = a/j;
	}
	S/=20;
	FOR(i,1,14)
	{
		maxi = t = t2 = -INF;
		FOR(j,'A','Z')
			if(B[j] >= S)
			{
				FOR(k,1,14)
					if(A[j][k] > maxi)
					{
						maxi = A[j][k];
						t = j;
						t2 = k;
					}
			}
		A[t][t2] = -INF;
		RES[t]++;
	}
	FOR(i,'A','Z')
		if(B[i] >= S)
			printf("%c %d\n",i,RES[i]);
}
int main()
{
	solve();
	return 0;
}
