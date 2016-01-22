#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int main()
{
	int i,j,res(0);
	char c;
	FOR2(i,4)
		FOR2(j,4)
		{
			scanf(" %c" , &c );
			if(c == '.') continue;
			c -= 'A';
			res += abs( c/4 - i ) + abs( c%4 - j );
		}

	printf("%d\n" , res );
	return 0;
}
