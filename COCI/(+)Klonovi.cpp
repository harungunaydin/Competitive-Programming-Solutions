#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 50
using namespace std;
typedef pair < int , int > pii;
map < int , short > mp;
set < int > st;
pii K[MAXN+5];
int M,N,p;
int A[MAXN+5],B[MAXN+5],P[36000];
int T[36000][MAXN+5];
bool asal(int a)
{
	int i,t = mp[a];
	if(t) return t == 2;
	if(!(a&1)) return 0;
	for(i=3; i*i<=a; i+=2)
		if(!(a%i))
		{
			mp[a] = 1;
			return 0;
		}
	mp[a] = 2;
	return 1;
}
bool control(int x)
{
	int i;
	FOR(i,1,N)
		if(T[x][i])
			return 1;
	return 0;
}
inline bool cmp( const pii &a , const pii &b ) { return a.f > b.f; }
void solve()
{
	int i,j,k,s(0),t;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	scanf("%d",&M);
	FOR(i,1,N)
		for(j=1; j*j <= A[i]; j++)
			if(!(A[i]%j))
			{
				if(asal(j)) st.insert(j);
				k = A[i]/j;
				if(asal(k)) st.insert(k);
			}
	set < int > :: iterator it;
	for(it = st.begin(); it!=st.end(); ++it)
		P[++p] = *it;
	FOR(i,1,N)
	{
		k = A[i];
		FOR(j,1,p)
		{
			while(!(k%P[j]))
			{
				T[j][i]++;
				k/=P[j];
			}
		}
	}
	FOR(i,1,p)
	{
		printf("ENTER %d\n",P[i]);
		t = 0;
		FOR(j,1,N)
			if(T[i][j])
			{
				K[j].f+=T[i][j];
				K[j].s = j;
				t+=T[i][j];
			}
		while(t)
		{
			s = 0;
			printf("CLONE");
			sort(K+1,K+N+1,cmp);
			FOR(j,1,N)
				if(K[j].f)
				{
					K[j].f--;
					t--;
					printf(" %d",K[j].s);
					if(++s == M) break;
				}
			printf("\n");
		}
	}
}
int main()
{
	mp[1] = 1;
	mp[2] = 2;
	solve();
	return 0;
}
