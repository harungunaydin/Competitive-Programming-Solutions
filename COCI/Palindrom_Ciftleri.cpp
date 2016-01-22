#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char A[1055][1055];
int n,m,ans=-99999,H[260];
int main()
{
	register int i,j,l,r,u,d,vis,t,x,y,xu,yu;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",A[i]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(min(n-i,i)*2 + min(m-j,j)*2 -1 < ans) continue;
			vis++;
			l = r = j;
			u = d = i;
			
			while(l>=0 and r<m and A[i][l]==A[i][r])
			H[A[i][l]]=vis,r++,l--;
			
			while(u>=0 and d<n and A[u][j]==A[d][j] and abs(H[A[u][j]])==vis)
			H[A[u][j]]=-vis,u--,d++;
			
			l = r = j;
			while(l>=0 and r<m and A[i][l]==A[i][r] and H[A[i][l]]==-vis)
			l--,r++;
			l++,r--,u++,d--;
			t = r-l+1+d-u+1 - 1;
			
			if( t > ans )
			{
				ans = t;
				x = i + 1;
				y = j + 1;
				xu = r - l + 1;
				yu = d - u + 1;
			}
		}
	printf("%d %d %d %d\n",x,y,xu,yu);
	return 0;
}
