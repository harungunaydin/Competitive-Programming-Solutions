#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N,M;
int A[100000];
int B[100000];
void ata(int x,int y)
{
	int i;
	FOR(i,1,N)
		if(A[i]==x)
			A[i]=y;
}
bool kontrol()
{
	int i;
	FOR(i,1,N-1)
		if(A[i]!=A[i+1])
			return 0;
	return 1;
}
void solve()
{
	int a,b,j,i,k,mk=0,mb=0,sk,sb;
	cin >> N >> M;
	for(i=1;i<=N;i++) A[i]=i;
	FOR(i,1,M)
	{
		cin >> a >> b;
		ata(A[b],A[a]);
	}
	if(kontrol())
	{
		cout << "2 2" << endl;
		exit(0);
	}
	FOR(i,1,N)
		B[A[i]]++;
	FOR(i,1,N)
	{
		if(B[i]>mk) { mk=B[i]; sk=i; }
		if(mk>mb) { swap(mk,mb); swap(sk,sb); }
	}
	cout << sb << " " << sk << endl;
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
