#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
typedef pair < pii , pii > pii4;
int read()
{
	int res(0),sign(1);
	char c;
	while(1){
		c = getchar();
		if('0' <= c && c <= '9') { res = c - '0'; break; }
		else if(c == '-') { sign = -1; break; }
	}
	while(1){
		c = getchar();
		if('0' <= c && c <= '9') res = res*10 + c - '0';
		else break;
	}
	return res * sign;
}
set < pii > st1,st2;
pii4 P[MAXN*MAXN];
int K,M,N;
char A[MAXN][MAXN];
int Distance( pii a , pii b )
{
	return (a.f - b.f) * (a.f- b.f) + (a.s - b.s) * (a.s - b.s);
}
int solve()
{
	int i,j;
	M = read(); N = read();
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c" , A[i] + j );
			if(A[i][j] == 'X') st1.insert( make_pair(i,j) );
			else if(A[i][j] == 'L') st2.insert( make_pair(i,j) );
		}

	set < pii > :: iterator it1,it2;
	pii p;
	int mini,res(0);

	vector < pii > V;
	vector < pii > :: iterator it3;

	while(1)
	{
		K = 0;

		for(it1 = st1.begin(); it1 != st1.end(); ++it1)
		{
			mini = 123123123;
			for(it2 = st2.begin(); it2 != st2.end(); ++it2)
				if(Distance(*it1,*it2) < mini)
				{
					mini = Distance( *it1 , *it2 );
					p = *it2;
				}
			P[++K] = make_pair( p , *it1 );
		}

		sort( P+1 , P+K+1 );

		FOR(i,1,K)
		{
			j = i;
			mini = 123123123;
			V.clear();
			while(i <= K && P[i].f.f == P[j].f.f && P[i].f.s == P[j].f.s)
			{
				if( Distance(P[i].f,P[i].s) < mini )
				{
					mini = Distance(P[i].f,P[i].s);
					V.clear();
				}
				if( Distance(P[i].f,P[i].s) == mini )
					V.push_back(P[i].s);
				i++;
			}

			for(it3 = V.begin(); it3 != V.end(); ++it3)
				st1.erase( st1.find(*it3) );

			st2.erase( st2.find(P[j].f) );

			res += ( (int) V.size() > 1 );


			i--;
		}

		if(st1.empty() || st2.empty()) return res;

	}	

	printf("%d\n" , res );

}
int main()
{
	printf("%d\n" , solve() );
	return 0;
}
