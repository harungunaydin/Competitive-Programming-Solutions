#include<iostream>
#include<cstdio>
using namespace std;
int n,T;
bool isPrime(int x)
{
	if(x==2 || x==3) return 1;
	if(x%2==0 || x==1) return 0;
	for(int i=3;i*i<=x;i+=2)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	register int i,j,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			printf("2\n");
	
			for(i=3;;i+=2)
			{
				if(isPrime(i) && isPrime(n-i))
				{
					printf("%d %d\n",i,n-i);
					break;
				}
			}
		}
		else
		{
			printf("3\n");
			for(i=3;;i=2)
			{
				if(isPrime(i))
					for(j=i+2;;j+=2)
					{
						if(isPrime(j) && isPrime(n-i-j))
						{
							printf("%d %d %d\n",i,j,n-i-j);
							goto somewhere;
						}
					}
			}
		somewhere:;
		}
	}
	return 0;
}
