#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
#define INPUT "picture.in"
#define OUTPUT "picture.out"
#define MAXN 100000
#define MAXL 10005
using namespace std;
FILE *in,*out;
class line
{
	public:
		int bas,x,son;
		bool is_first;
}A[MAXN+5],B[MAXN+5];
int C[MAXN+5];
bool operator < (line a,line b)
{
	if(a.x != b.x) return a.x <= b.x;
	return a.is_first > b.is_first;
}
int N,res;
void hesapla(line L[])
{
	int i,j,k;
	FOR2(i,2*N)
		FOR(j,L[i].bas,L[i].son-1)
		{
			k = j + MAXL;
			res+=(L[i].is_first && ++C[k] == 1);
			res+=(!L[i].is_first && !(--C[k]));
		}
		
}
void addline(line L[],int i,int x,int b,int s,bool c)
{
	L[i].bas = b;
	L[i].son = s;
	L[i].x = x;
	L[i].is_first = c;
}
void solve()
{
	int a,b,c,d,i;
	in = fopen(INPUT,"r");
	fscanf(in,"%d",&N);
	FOR2(i,N)
	{
		fscanf(in,"%d %d %d %d",&a,&b,&c,&d);
		addline(A,i,a,b,d,1);
		addline(A,i+N,c,b,d,0);
		addline(B,i,b,a,c,1);
		addline(B,i+N,d,a,c,0);
	}
	sort(A,A+2*N);
	sort(B,B+2*N);
	hesapla(A);
	hesapla(B);
	out = fopen(OUTPUT,"w");
	fprintf(out,"%d\n",res);
}
int main()
{
	solve();
	return 0;
}
