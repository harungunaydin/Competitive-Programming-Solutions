#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 30000
using namespace std;
char A[35];
char str[MAXN+5][35];
int M,N,a;
int B[MAXN+5],K[MAXN+5];
FILE *in = fopen("a.txt","r"),*out = fopen("a2.txt","w");
inline void hesapla()
{
	register int a,b,i,j,pre(0),s(0);
	fscanf(in,"%s",A);
	a = strlen(A);
	FOR(i,1,N)
	{
		b = B[i];
		j = min(K[i],pre);
		while(j<a && j<b && str[i][j] == A[j]) j++;
		s+=j+1;
		if(j == a && j == b) break;
		pre = j;
	}
	fprintf(out,"%d\n",s);
}
void solve()
{
	fscanf(in,"%d",&N);
	register int a,b,i,j;
	fscanf(in,"%s",str[1]);
	B[1] = strlen(str[1]);
	FOR(i,2,N)
	{
		fscanf(in,"%s",str[i]);
		B[i] = strlen(str[i]);
		j = 0;
		while(j<B[i] && j<B[i-1] && str[i][j] == str[i-1][j]) j++;
		K[i] = j;
	}
	fscanf(in,"%d",&M);
	FOR(i,1,M)
		hesapla();
}
int main()
{
	solve();
	return 0;
}
