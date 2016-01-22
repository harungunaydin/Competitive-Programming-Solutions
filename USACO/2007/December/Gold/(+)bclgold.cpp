#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 30001
using namespace std;
int s;
char A[MAXN];
void print(char c)
{
	printf("%c",c);
	if(++s == 80)
	{
		printf("\n");
		s = 0;
	}
}
void solve()
{
	int N,a,b,bas,i,son;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf(" %c",A+i);
	bas = 1; son = N;
	while(bas <= son)
	{
		if(A[bas] < A[son]) { print(A[bas]); bas++; }
		else if(A[bas] > A[son]) { print(A[son]); son--; }
		else
		{
			a = bas; b = son;
			while(a < b)
			{
				if(A[a] < A[b]) { print(A[bas]); bas++; break; }
				else if(A[a] > A[b]) { print(A[son]); son--; break; }
				a++; b--;
			}
			if(a >= b) { print(A[bas]); bas++; }
		}
	}
}
int main()
{
	solve();
	return 0;
}
