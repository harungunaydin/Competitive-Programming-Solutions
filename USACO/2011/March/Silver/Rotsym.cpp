#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <conio.h>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
typedef pair <double,double> dii;
map < dii , int > mp;
map < dii , int > :: iterator it;
vector < dii > V;
int N;
pii p[1005];
void solve()
{
	int i,j,k=1,s=0;
	double orta_x,orta_y;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&p[i].f,&p[i].s);
	FOR(i,1,N)
		FOR(j,i+1,N)
		{
			orta_x=(p[i].f + p[j].f)/2.0;
			orta_y=(p[i].s + p[j].s)/2.0;
			V.push_back(make_pair(orta_x,orta_y));
		}
	sort(V.begin(),V.end());
	for(i=0; i<V.size()-1; i++)
	{
		if(V[i].f == V[i+1].f && V[i].s == V[i+1].s) k++;
		else
		{
			s+=(k*(k-1))/2;
			k=1;
		}
	}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
