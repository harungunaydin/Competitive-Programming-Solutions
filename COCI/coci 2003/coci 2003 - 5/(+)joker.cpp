#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
using namespace std;
pair <int,int> p[5000005];
bool cmp(const pair <int,int> &a,const pair< int,int > &b)
{
	return a.f>=b.f;
}
void solve()
{
	int K,N,i,j,k=0;
	cin >> N >> K;
	FOR(i,1,K)
	{
		scanf("%d %d",&p[i].f,&p[i].s);
		k+=p[i].s-p[i].f+1;
	}
	sort(p+1,p+K+1,cmp);
	if(k==N-1)
		FOR(i,1,K)
			printf("%d %d\n",p[i].f,p[i].s);
	else
		cout << -1 << endl;
}
int main()
{
	solve();
	return 0;
}
