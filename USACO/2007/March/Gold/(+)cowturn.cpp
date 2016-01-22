#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 5005
using namespace std;
typedef pair < int , int > pii;
int N;
int H[MAXN];
bool A[MAXN];
int hesapla(int K)
{
	int i,k,s(0),t(0);
	FOR(i,1,N-K+1)
	{
		if(H[i] == K) s--;
		k = (s&1) ? !A[i] : A[i];
		if(!k)
		{
			s++;
			H[i + K] = K;
			t++;
		}
	}
	FOR(i,N-K+2,N)
	{
		if(H[i] == K) s--;
		k = (s&1) ? !A[i] : A[i];
		if(!k) return MAXN*MAXN;
	}
	return t;
}
void solve()
{
	int i,k,res(MAXN*MAXN),t;
	char c;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf(" %c",&c);
		A[i] = (c == 'F');
	}
	FOR(i,1,N)
	{
		t = hesapla(i);
		if(t < res)
		{
			res = t;
			k = i;
		}
	}
	printf("%d %d\n" , k , res );
}
int main()
{
	solve();
	return 0;
}
