#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
int bas;
char sta[MAXN];
char A['z'+5]['z'+5];
bool B['z'+5]['z'+5];
bool control(char c)
{
	int i;
	FOR2(i,bas)
		if(B[sta[i]][c])
			return true;
	return false;
}
void solve()
{
	memset( A , 0 , sizeof A );
	memset( B,  0 , sizeof B );
	bas = 0;
	string str;
	int M,i;
	char c;
	scanf("%d",&M);
	FOR(i,1,M)
	{
		cin >> str;
		A[str[0]][str[1]] = str[2];
		A[str[1]][str[0]] = str[2];
	}
	scanf("%d",&M);
	FOR(i,1,M)
	{
		cin >> str;
		B[str[0]][str[1]] = true;
		B[str[1]][str[0]] = true;
	}
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf(" %c",&c);
		if(!bas) sta[bas++] = c;
		else
		{
			if(A[sta[bas-1]][c])
				sta[bas-1] = A[sta[bas-1]][c];
			else if(control(c))
				bas = 0;
			else
				sta[bas++] = c;
		}
	}
	printf("[");
	FOR2(i,bas)
	{
		printf("%c",sta[i]);
		if(i != bas - 1)
			printf(", ");
	}
	printf("]\n");
}
int main()
{
	freopen("inp","r",stdin);
	freopen("out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
