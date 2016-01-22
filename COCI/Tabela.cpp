#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
int A[10][10],n,temp[10][10],k,cnt;
string str,sayi[10000000];
map < string , bool > mep;
bool w;
int yap(int x,int y)
{
	int xx=x,yy=y,a=A[x][y];
	x--;
	if(x<1)
	{
		x=n;
		y++;
	}
	if(y>n)
		y=1;
	yy++;
	if(yy>n)
	{
		yy=1;
		xx++;
	}
	if(xx>n)
		xx=1;
	if(A[xx][yy]+A[x][y]==1)
		return a;
	return !a;
}
int main()
{
	int i,j;
	cin >> n >> k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin >> A[i][j];
			str+=A[i][j]+'0';
		}
	while(cnt!=k)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				temp[i][j]=yap(i,j);
		cnt++;
		str="";
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				A[i][j]=temp[i][j];
				str+='0'+A[i][j];
			}
		sayi[cnt]=str;
		if(mep[str])
		{
			w=1;
			break;
		}
		mep[str]=1;
	}
	if(!w)
	{
		int t=0;
		for(i=0;i<n;i++,cout << endl)
			for(j=0;j<n;j++)
				cout << str[t++] << " ";
	}
	else
	{
		int t=0;
		for(i=0;i<n;i++,cout << endl)
			for(j=0;j<n;j++)
				cout << sayi[k%(cnt-1)][t++] << " ";
	}
	return 0;
}
