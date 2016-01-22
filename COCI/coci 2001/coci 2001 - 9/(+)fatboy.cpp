#include <iostream>
using namespace std;
string str,str2,str3,s;
int A[100][105][105],DP[105][105][105];
void izracunaj(int x,int y,int z)
{
	if(A[x][y][z]==4)
	{
		izracunaj(x-1,y-1,z-1);
		cout << str[x-1];
	}
	else if(A[x][y][z]==3) izracunaj(x-1,y,z);
	else if(A[x][y][z]==2) izracunaj(x,y-1,z);
	else if(A[x][y][z]==1) izracunaj(x,y,z-1);
	else if(!A[x][y][z]) return;
	
}
void solve()
{
	int a,b,c,i,j,k,mx=0;
	cin >> str >> str2 >> str3;
	for(i=1; i<=str.size(); i++)
		for(j=1; j<=str2.size(); j++)
			for(k=1; k<=str3.size(); k++)
			{
				if(str[i-1]==str2[j-1] && str2[j-1]==str3[k-1])
				{
					A[i][j][k]=4;
					DP[i][j][k]=DP[i-1][j-1][k-1]+1;
				}
				else
				{
					DP[i][j][k]=max(DP[i-1][j][k],max(DP[i][j-1][k],DP[i][j][k-1]));
					if(DP[i][j][k-1]==DP[i][j][k])
						A[i][j][k]=1;
					else if(DP[i][j-1][k]==DP[i][j][k])
						A[i][j][k]=2;
					else if(DP[i-1][j][k]==DP[i][j][k])
						A[i][j][k]=3;
				}
					if(mx < DP[i][j][k])
					{
						a=i;
						b=j;
						c=k;
						mx=DP[i][j][k];
					}
			}
	izracunaj(a,b,c);
	cout << endl;
}
int main()
{
	solve();
	return 0;
}
