#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 100000
using namespace std;
typedef pair <int,int> pii;
vector <int> V;
pii A[MAXN+5];
int B[MAXN+5],C[MAXN+5];
int N,maxi=1;
bool cmp(const pii &a , const pii &b)
{
	if(a.f < b.f) return 1;
	if(a.f > b.f) return 0;
	return a.s > b.s;
}
int BS(int bas,int son,int a)
{
	int orta = (bas + son)/2;
	if(orta == maxi) return orta;
	if(B[orta-1] <= a && B[orta] > a) return orta;
	return (B[orta] > a) ? BS(bas,orta-1,a) : BS(orta+1,son,a);
}
void LIS()
{
	int a,i,k,index;
	reverse(A,A+N);
	FOR2(i,N)
	{
		a = A[i].s;
		index = BS(1,maxi,a);
		if(!B[index]) maxi++;
		C[i] = index;
		B[index] = a;
	}
	k = --maxi;
	TFOR(i,N-1,0)
		if(C[i] == k)
		{
			k--;
			V.push_back(i);
		}
	vector <int> :: iterator it;
	printf("%d\n",maxi);
	for(it = V.begin(); it!=V.end(); ++it)
		printf("%d %d\n",A[*it].f,A[*it].s);
}
int main()
{
	int i;
	scanf("%d",&N);
	FOR2(i,N)
		scanf("%d %d",&A[i].f,&A[i].s);
	sort(A,A+N,cmp);
	LIS();
	return 0;
}
