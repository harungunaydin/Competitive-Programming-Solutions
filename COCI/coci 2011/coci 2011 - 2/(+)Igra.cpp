#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define EKLE(c,x) pq.push(make_pair(c,x))
#define BAK(c,x)  { c = pq.top().first; x = pq.top().second; pq.pop(); }
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
typedef pair < char , int > pci;
set < pci > st;
int N;
char A[MAXN];
void solve()
{
	int i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf(" %c" , A+i);
		st.insert( make_pair(A[i],N-i) );
	}

	string mirko = "" , slavko = "";
	int k(N);
	FOR(i,1,N/2)
	{
		while( st.find( make_pair(A[k],N-k) ) == st.end() ) k--;
		mirko += A[k];
		st.erase( st.find( make_pair(A[k],N-k) ) );
		k--;
		//BURAYA KADAR MIRKONUN HAMLESI

		slavko += st.begin()->first;

		st.erase( st.begin() );

	}

	(slavko < mirko) ? printf("DA\n") : printf("NE\n");

	cout << slavko << endl;
}
int main()
{
	solve();
	return 0;
}
