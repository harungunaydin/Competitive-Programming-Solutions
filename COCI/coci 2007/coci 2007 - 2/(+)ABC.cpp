#include <cstdio>
#include <iostream>
#define yaz(a,b,c) printf("%d %d %d\n" , a , b , c )
using namespace std;
int A[300];
main()
{
	int a,b,c;
	char a2,b2,c2;
	scanf("%d %d %d",&a,&b,&c);
	if(a > b) swap(a,b);
	if(a > c) swap(a,c);
	if(b > c) swap(b,c);
	A['A'] = a;
	A['B'] = b;
	A['C'] = c;
	scanf(" %c %c %c",&a2,&b2,&c2);
	printf("%d %d %d\n" , A[a2] , A[b2] , A[c2] );
}
