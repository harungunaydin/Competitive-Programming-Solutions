#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 50002
using namespace std;
map < int , int > mp;
typedef pair < int , int > pii;
typedef pair < pii , int > pii3;
pii3 A[MAXN];
int C,K,N;
void print(map < int , int > mp)
{
	map < int , int > :: iterator it;
	for(it = mp.begin(); it != mp.end(); ++it)
		cout << "    " << it->f << " " << it->s << endl;
	cout << endl;
}
void solve()
{
	map < int , int > :: iterator it;
	int i,res(0),s(0);
	scanf("%d %d %d",&K,&N,&C);
	FOR(i,1,K)
		scanf("%d %d %d",&A[i].f.f,&A[i].f.s,&A[i].s);
	sort(A+1,A+K+1);
	FOR(i,1,K)
	{
		for(it = mp.begin(); it != mp.end(); )
			if(it->f <= A[i].f.f)
			{
				res += it->s;
				s -= it->s;
				mp.erase(it++);
			}
			else break;
		mp[A[i].f.s] += A[i].s;
		s += A[i].s;
		it = mp.end(); it--;
		while(s > C)
		{
			if(s - it->s < C)
			{
				it->s -= s - C;
				s = C;
			}
			else
			{
				s -= it->s;
				mp.erase(it--);
			}
		}
	}
	printf("%d\n" , res + s);
}
int main()
{
	solve();
	return 0;
}
