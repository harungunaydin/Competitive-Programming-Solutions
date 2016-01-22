#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
using namespace std;
int K,M,N;
double A[105];
bool cmp(const double &a,const double &b)
{
	return a>b;
}
void solve()
{
	int i,j,x;
	double s;
	scanf("%d %d %d",&N,&M,&K);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf("%d %lf",&x,&s);
			if(s>A[x]) A[x]=s;
		}
	sort(A+1,A+N+1,cmp);
	s=0;
	FOR(i,1,K)
		s+=A[i];
	printf("%.1lf\n",s);
}
int main()
{
	solve();
	return 0;
}
