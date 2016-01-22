#include <iostream>
using namespace std;
int M,N;
class contest
{
	public:
		int no;
		double sayi;
};
contest A[1000],B[1000];
bool cmp(const contest &a,const contest &b)
{
	return a.sayi>b.sayi;
}
void solve()
{
	int i,M,N;
	char c;
	double maxi,x;
	cin >> N >> M;
	cin >> A[1].sayi;
	maxi=A[1].sayi;
	A[1].no=1;
	for(i=2; i<=N; i++)
	{
		cin >> c;
		cin >> x;
		if(c=='+')
			A[i].sayi=maxi+x;
		if(c=='-')
		{
			maxi=maxi-x;
			A[i].sayi=maxi;
		}
		A[i].no=i;
	}
	sort(A+1,A+N+1,cmp);
	int k=1;
	for(int i=N-M+1; i<=N; i++)
		B[k++].no=A[i].no;
	cin >> B[1].sayi;
	maxi=B[1].sayi;
	for(i=2; i<=M; i++)
	{
		cin >> c;
		cin >> x;
		if(c=='+')
			B[i].sayi=maxi+x;
		if(c=='-')
		{
			maxi=maxi-x;
			B[i].sayi=maxi;
		}
	}
	sort(B+1,B+M+1,cmp);
	cout << B[M].no << endl << B[M-1].no << endl << B[M-2].no << endl;
}
int main()
{
	solve();
	return 0;
}
