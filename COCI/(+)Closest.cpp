#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1000
using namespace std;
vector < char > V;
int sizeB;
int K[MAXN+5];
char A[MAXN+5],B[MAXN+5];
bool flag;
void rec(int x)
{
	char a = A[x],i,j,k;
	if(flag) return;
	if(x == sizeB)
	{
		for(vector < char > :: iterator it = V.begin(); it != V.end(); ++it)
			printf("%c",*it);
		printf("\n");
		flag = true;
		return;
	}
	if(flag) return;
	if(K[a])
	{
		K[a]--;
		V.push_back(a);
		rec(x+1);
		K[a]++;
		V.pop_back();
	}
	if(flag) return;
	FOR(i,a+1,'9')
		if(K[i])
		{
			K[i]--;
			V.push_back(i);
			FOR(j,'0','9')
				FOR2(k,K[j])
					V.push_back(j);
			for(vector < char > :: iterator it = V.begin(); it != V.end(); ++it)
				printf("%c",*it);
			printf("\n");
			K[i]++;
			V.clear();
			fill(K,K+300,0);
			FOR2(i,sizeB)
				K[B[i]]++;
			flag = true;
			return;
		}
}
void rec2(int x)
{
	char a = A[x],i,j,k;
	if(K[a])
	{
		K[a]--;
		V.push_back(a);
		rec2(x+1);
		K[a]++;
		V.pop_back();
	}
	TFOR(i,a-1,'0')
		if(K[i])
		{
			K[i]--;
			V.push_back(i);
			TFOR(j,'9','0')
				FOR2(k,K[j])
					V.push_back(j);
			for(vector < char > :: iterator it = V.begin(); it != V.end(); ++it)
				printf("%c",*it);
			printf("\n");
			exit(0);
		}
}
void solve()
{
	scanf("%s",A);
	scanf("%s",B);
	int i;
	sizeB = strlen(B);
	FOR2(i,sizeB)
		K[B[i]]++;
	rec(0);
	if(!flag) printf("0\n");
	V.clear();
	fill(K,K+300,0);
	FOR2(i,sizeB)
		K[B[i]]++;
	flag = false;
	rec2(0);
	printf("0\n");
}
int main()
{
	solve();
	return 0;
}
