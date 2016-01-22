#include<iostream>
#include<cstdio>
#define f first
#define s second
using namespace std;
int A[25][25],n,i,j,a,b,sayac,k;
bool H[25][25];
pair < int , int > Y[100];
void yazdir()
{
	int i,j;
	for(i=20;i>=1;i--,cout << endl)
		for(j=1;j<=20;j++)
		{
			if(A[i][j])
			cout << A[i][j] << " ";
			else cout << "  ";
		}
}
int main()
{
	cin >> n;
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		A[a][b]=1;
	}
	yazdir(); cout << endl << endl;
	while(n)
	{
		bool w=0;
		for(i=21;i>=1;i--)
			for(j=0;j<=21;j++)
			{
				int cnt=0;
				cnt+=A[i][j]+A[i][j+1];
				cnt+=A[i-1][j]+A[i-1][j+1];
				if(!H[i][j] && (A[i][j]+A[i-1][j+1]==2 || A[i-1][j]+A[i][j+1]==2))
				{
					n-=cnt;
					H[i][j]=H[i][j+1]=H[i-1][j]=H[i-1][j+1]=1;
					A[i][j]=A[i][j+1]=A[i-1][j]=A[i-1][j+1]=0;
					w=1;
					sayac++;
					Y[++k].f=i-1;
					Y[k].s=j;
					yazdir();
					cout << endl << endl;
					cin.get();
				}
			}
		if(!w && n)
		{
			for(i=21;i>=1;i--)
				for(j=0;j<=21;j++)
				{
					int cnt=0;
					cnt+=A[i][j]+A[i][j+1];
					cnt+=A[i-1][j]+A[i-1][j+1];
					if(!H[i][j] && cnt==2)
					{
						n-=cnt;
						H[i][j]=H[i][j+1]=H[i-1][j]=H[i-1][j+1]=1;
						A[i][j]=A[i][j+1]=A[i-1][j]=A[i-1][j+1]=0;
						w=1;
						sayac++;
						Y[++k].f=i-1;
						Y[k].s=j;
						yazdir();
						cout << endl << endl;
						cin.get();
					}
				}
		}
		if(!w && n)
		{
			for(i=21;i>=1;i--)
				for(j=0;j<=21;j++)
				{
					int cnt=0;
					cnt+=A[i][j]+A[i][j+1];
					cnt+=A[i-1][j]+A[i-1][j+1];
					if(!H[i][j] && cnt)
					{
						n-=cnt;
						H[i][j]=H[i][j+1]=H[i-1][j]=H[i-1][j+1]=1;
						A[i][j]=A[i][j+1]=A[i-1][j]=A[i-1][j+1]=0;
						w=1;
						sayac++;
						Y[++k].f=i-1;
						Y[k].s=j;
						yazdir();
						cout << endl << endl;
						cin.get();
					}
				}
		}
	}
	cout << sayac << endl;
	for(i=1;i<=k;i++)
	{
		cout << Y[i].f << " " << Y[i].s << endl;
	}
	return 0;
}
