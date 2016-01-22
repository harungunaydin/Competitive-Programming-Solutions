#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 100
using namespace std;
int A[MAXN+5];
void solve()
{
	int N,a,b,i,k,m,maxi(0),res(1),t,z;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	scanf("%d %d",&a,&b);
	sort(A+1,A+N+1);
	FOR(i,2,N)
	{
		t = A[i] - A[i-1];
		k = (A[i] + A[i-1])/2;
		if(!(k&1)) k++;
		if(k > b) break;
		if(k>=a && k<=b)
		{
			m = min(A[i]-k,k-A[i-1]);
			if(m > maxi)
			{
				maxi = m;
				res = k;
			}
		}
	}
	N = i-1;
	if(!(a&1)) a++;
	if(!(b&1)) b--;
	if(a < A[1] && A[1]-a > maxi)
	{
		maxi = A[1]-a;
		res = a;
	}
	if(b > A[N] && b-A[N] > maxi)
	{
		maxi = b-A[N];
		res = b;
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
