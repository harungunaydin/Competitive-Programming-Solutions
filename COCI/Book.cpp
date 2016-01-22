#include<iostream>
#include<cstdio>
using namespace std;
int A[55][55],n,a,cnt,w;
int main()
{
	int i,j,k,ii,jj,a;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin >> A[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(!A[i][j]) continue;
			if(i==1 || i==n || j==1 || j==n)
			{
				cnt++;
				continue;
			}
			a=A[i][j];
			w=0;
			k=i;
			while(k<=n) { k++; if(A[k][j]>=a) { w++; break; } }
			k=i;
			while(k>=1) { k--; if(A[k][j]>=a) { w++; break; } }
			k=j;
			while(k<=n) { k++; if(A[i][k]>=a) { w++; break; } }
			k=j;
			while(k>=1) { k--; if(A[i][k]>=a) { w++; break; } }
			if(w!=4)
				cnt++;
		}
	printf("%d\n",cnt);
	return 0;
}
