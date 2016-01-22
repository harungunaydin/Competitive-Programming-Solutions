#include<iostream>
#include<cstdio>
#include<cstring>
#define f first
#define s second
using namespace std;
char A[105][105],temp[105];
int n,tn;
pair < pair < int , int > , char > ans;
pair < pair < int , int > , char > solve()
{
	register int i,j,sag,alt,uz;
	uz=strlen(temp);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			alt = i;
			sag = j;
			while(alt < n && temp[alt-i]==A[alt][j])
				alt++;
			while(sag < n && temp[sag-j]==A[i][sag])
				sag++;
			if(alt-i==uz)
				return make_pair(make_pair(i+1,j+1),'D');
			if(sag-j==uz)
				return make_pair(make_pair(i+1,j+1),'Y');
		}
}
int main()
{
	register int h,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%s",A[i]);
	scanf("%d",&h);
	for(i=0;i<h;i++)
	{
		scanf("%s",temp);
		ans = solve();
		printf("%d %d %c\n",ans.f.f,ans.f.s,ans.s);
	}
	return 0;
}
