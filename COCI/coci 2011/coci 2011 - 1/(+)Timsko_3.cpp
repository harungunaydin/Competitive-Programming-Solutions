#include <iostream>
using namespace std;
int hallet(int x,int y)
{
	if(x/2>=y) return y;
	return x/2;
}
int solve()
{
	int a,b,K,M,N,maxi=0,x,y;
	scanf("%d %d %d",&M,&N,&K);
	if(!K) return hallet(M,N);
	a=0;
	b=K;
	while(b!=-1)
	{
		x=M-a;
		y=N-b;
		maxi=max(maxi,hallet(x,y));
		a++;
		b--;
	}
	return maxi;
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
