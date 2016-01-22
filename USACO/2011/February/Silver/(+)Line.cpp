#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V;
vector <int> :: iterator it;
int K,N;
long long fakt[105];
long long A[105];
long long bul()
{
	long long i,j,s=0,k;
	for(i=1; i<=N; i++)
	{
		k=0;
		for(j=1; j<i; j++)
			if(A[j] < A[i])
				k++;
		s+=(A[i]-k-1)*fakt[N-i];
	}
	return s+1;
}
void solve()
{
	long long a,i,j,k,x,s;
	char c;
	fakt[0]=1;
	FOR(i,1,21) fakt[i]=fakt[i-1]*i;
	scanf("%d %d",&N,&K);
	FOR(i,1,K)
	{
		scanf(" %c",&c);
		if(c=='P')
		{
			scanf("%lld",&x);
			k=N-1;
			x--;
			FOR(j,1,N) V.push_back(j);
				FOR(j,1,N)
				{
					a=x/fakt[k] + 1;
					x%=fakt[k];
					k--;
					for(it=V.begin(),s=1; it!=V.end(); ++it,s++)
						if(s==a)
						{
							printf("%d",*it);
							if(V.size() > 1) printf(" ");
							V.erase(it);
							break;
						}
				}
			V.clear();
			cout << endl;
		}
		else if(c=='Q')
		{
			FOR(j,1,N)
				scanf("%d",&A[j]);
			cout << bul() << endl;
		}
	}
}
int main()
{
	solve();
	return 0;
}
/*
5 1
Q
1 2 5 3 4
*/
