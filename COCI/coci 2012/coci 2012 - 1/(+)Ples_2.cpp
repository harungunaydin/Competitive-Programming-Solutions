#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 200000
using namespace std;
typedef pair <int,int> pii;
bool cmp(const pii &a,const pii &b)
{
	return abs(a.f) < abs(b.f);
}
pii A[MAXN+5];
int solve()
{
	int N,a,b,i,j,res(0),tue(0),tuk(0),ue(0),uk(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&A[i].f);
		A[i].s = 1;
	}
	N<<=1;
	for(; i<=N; i++)
	{
		scanf("%d",&A[i].f);
		A[i].s = 2;
	}
	sort(A+1,A+N+1,cmp);
	FOR(i,1,N)
	{
		a = b = i;
		while(abs(A[b].f) == abs(A[b+1].f)) b++;
		i = b;
		if(a == b)
		{
			if(A[i].f > 0)
				(A[i].s == 1) ? ue++ : uk++;
			if(A[i].f < 0)
			{
				if(A[i].s == 1 && uk) { res++; uk--; }
				else if(A[i].s == 2 && ue){ res++; ue--; }
			}
		}
		else
		{
			tue = tuk = 0;
			FOR(j,a,b)
			{
				if(A[j].f > 0)
					(A[j].s == 1) ? tue++ : tuk++;
				if(A[j].f < 0)
				{
					if(A[j].s == 1 && uk) { res++; uk--; }
					else if(A[j].s == 2 && ue) { res++; ue--; }
				}
			}
			ue+=tue;
			uk+=tuk;
		}
	}
	return res;
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
