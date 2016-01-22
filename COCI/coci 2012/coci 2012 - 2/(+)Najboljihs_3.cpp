#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[15],B[15];
void solve()
{
	int a,b,c,d,e,maxi=0,t;
	FOR(a,1,8) scanf("%d",&A[a]);
	FOR(a,1,8)
		FOR(b,a+1,8)
			FOR(c,b+1,8)
				FOR(d,c+1,8)
					FOR(e,d+1,8)
					{
						t=A[a] + A[b] + A[c] + A[d] + A[e];
						if(t > maxi)
						{
							maxi = t;
							B[1]=a;
							B[2]=b;
							B[3]=c;
							B[4]=d;
							B[5]=e;
						}
					}
	printf("%d\n%d %d %d %d %d\n",maxi,B[1],B[2],B[3],B[4],B[5]);
}
int main()
{
	solve();
	return 0;
}
