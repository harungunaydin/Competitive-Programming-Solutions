#include <iostream>
using namespace std;
int N;
int A[1000];
int bul()
{
	for(int i=1; i<=N; i++)
		if(A[i]==1)
			return i;
}
void solve()
{
	int a,i,G,k=1,x;
	bool d=true;
	cin >> N >> G;
	for(i=0; i<G; i++)
	{
		cin >> x;
		if(d)
			while(x)
			{
				if(x==1) { A[k++]=1; break; }
				A[k++]=2;
				x-=2;
				if(k==N+1)
				while(x)
				{
					A[bul()]=2;
					x--;
				}
			}
		else
			while(x)
			{
				A[bul()]=2;
				x--;
			}
		if(k==N+1) d=false;
	}
	for(i=1; i<=N; i++)
		cout << A[i] << endl;
}
int main()
{
	solve();
	return 0;
}
