#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1300
int A[MAXN+5];
int main()
{
	int a(0),b,i,j,res(0);
	FOR(i,1,50)//INIT
		FOR(j,1,i)
			A[++a] = i;
	scanf("%d %d",&a,&b);
	FOR(i,a,b)//SOLVE
		res+=A[i];
	printf("%d\n",res);
	return 0;
}
