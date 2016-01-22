#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int maxi,N;
int A[10000],hedef[10000],otur[10000];
bool kontrol()
{
	int i;
	FOR(i,1,maxi)
		if(A[i])
			return 0;
	return 1;
}
int solve()
{
	int i,s=2,t=0;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&hedef[i]);
		if(maxi<hedef[i]) maxi=hedef[i];
	}
	A[1]=1;
	while(1)
	{
		for(i=maxi; i; i--)
		{
			if(kontrol()) return t+1;
			if(A[i])
			{
				if(i==hedef[A[i]])
				{
					if(otur[A[i]]<5)
						otur[A[i]]++;
					if(otur[A[i]]==5)
						A[i]=0;
				}
				else if(i<maxi && !A[i+1])
						A[i+1]=A[i],A[i]=0;
			}
		}
		t++;
		if(!A[1] && s<=N) A[1]=s++;
	}
	return t;
}
int main()
{
	cout << solve() << endl;
	return 0;
}
