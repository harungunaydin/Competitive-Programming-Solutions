#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V,V2;
int K,M,N;
int A[10005],C[10005],D[10005];
char B[10005];
void read()
{
	int i;
	cin >> N >> M >> K;
	FOR(i,1,N)
		cin >> B[i];
	FOR(i,1,M)
		cin >> C[i];
	FOR(i,1,M)
		A[i]=K;
}
int bul(int x)
{
	int i;
	FOR(i,1,M)
		if(C[i]==x)
			return i;
	return -1;
}
void solve()
{
	int a,i,j,k,maxi,mini;
	FOR(i,1,N)
	{
		if(B[i]=='E')
		{
			mini=100000;
			FOR(j,1,M)
				if(A[j] && A[j]<mini)
				{
					mini=A[j];
					k=j;
				}
			V.push_back(k);
			A[k]--;
			continue;
		}
		maxi=0;
		FOR(j,1,M)
			if(A[j] && A[j]>maxi)
			{
				maxi=A[j];
				k=j;
			}
		V.push_back(k);
		A[k]--;
	}
	FOR(i,1,M)
	{
		D[i]=bul(A[i]);
		C[D[i]]=-1;
	}
	FOR(i,0,V.size()-1)
		cout << D[V[i]] << " ";
}
int main()
{
	read();
	solve();
	//system("PAUSE");
	return 0;
}
