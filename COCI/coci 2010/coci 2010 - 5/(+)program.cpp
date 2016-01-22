#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 1000010
using namespace std;
long long B[MAXN];
int K,N;
class klas
{
	public:
		vector < int > V;
		klas() { }
		void bitir(int k)
		{
			int a(0),i , s = V.size() , t = N/k + 1 , tmp;

			tmp = s;

			sort( all(V) );

			for(i = 0; i < t; i++)
			{
				while(a < tmp && V[a] == i)
				{
					a++;
					s--;
				}
				B[i*k] += (long long) s;
				if(a == tmp) return;
			}

		}

}A[MAXN];
void solve()
{
	int a,b,i;
	scanf("%d %d",&N,&K);
	FOR(i,1,K)
	{
		scanf("%d",&a);
		A[a].V.push_back(N/a+1);
	}

	FOR(i,1,N)
		if(!A[i].V.empty())
			A[i].bitir(i);

	FOR(i,1,N-1) B[i] += B[i-1];

	scanf("%d",&K);

	while(K--)
	{
		scanf("%d %d",&a,&b);

		if(a) printf("%lld\n" , B[b] - B[a-1] );
		else  printf("%lld\n" , B[b]);
	}

}
int main()
{
	solve();
	return 0;
}
