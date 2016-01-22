#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N,s;
int A[100005];
int us(int x,int y)
{
	return (!y)? 1 : x*us(x,y-1);
}
void rec(int x,int y)
{
	int orta=(x+y)/2;
	if(x+1 == y)
	{
		if(A[x] > A[y])
		{
			s+=2;
			swap(A[x],A[y]);
		}
		return;
	}
	rec(x,orta);
	rec(orta+1,y);
	int i,j;
	if(A[x] > A[orta+1])
		for(i=x,j=orta+1; i<=orta; i++,j++)
		{
			swap(A[i],A[j]);
			s+=(j-i)*2;
		}
}
void solve()
{
	int a,i;
	char c;
	scanf("%d",&N);
	a=us(2,N);
	FOR(i,1,a)
		scanf("%d",&A[i]);
	rec(1,a);
	cout << s << endl;
	FOR(i,1,a)
		printf("%d\n",A[i]);
}
int main()
{
	solve();
	return 0;
}
