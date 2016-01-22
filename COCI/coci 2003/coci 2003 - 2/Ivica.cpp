#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
ifstream in("ivica.in");
int M,N;
int A[100005],B[100005],C[100005];
void solve()
{
	int i,j,s,x;
	cin >> N >> M;
	FOR(i,1,N)
		cin >> A[i];
	TFOR(i,N,1)
	{
		s=0;
		FOR(j,1,N)
		{
			if(!B[j] && ++s==A[i])
			{
				B[j]=i;
				break;
			}
		}
	}
	TFOR(i,M,1)
		cin >> A[i];
	FOR(i,1,M)
	{
		s=0;
		FOR(j,1,M)
			if(!C[j] && ++s==A[i])
			{
				C[j]=B[i];
				break;
			}
		}
	}
	FOR(i,1,3)
		cout << C[i] << endl;
}
int main()
{
	solve();
	return 0;
}
