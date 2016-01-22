#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 500000
using namespace std;
vector <int> V[10];
int K,N;
void solve()
{
	string str;
	int i,j,pre,s(0);
	char A[MAXN+5];
	bool flag;
	scanf("%d %d",&N,&K);
	scanf("%s",A);
	TFOR(i,N-1,0)
		V[A[i]-'0'].push_back(i);
	pre = -1;
	TFOR(i,N-K,1)
		TFOR(j,9,0)
		{
			while(!V[j].empty() && V[j].back() < pre) V[j].pop_back();
			if(!V[j].empty() && V[j].back()+i-1 < N)
			{
				A[s++] = j+'0';
				pre = V[j].back();
				V[j].pop_back();
				break;
			}
		}
	A[s] = '\0';
	printf("%s\n",A);
}
int main()
{
	solve();
	return 0;
}
