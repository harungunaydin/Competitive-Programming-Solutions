#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 512
using namespace std;
int N;
int DP[MAXN+5][MAXN+5][11];
short DP2[MAXN+5][MAXN+5][11];
bool A[MAXN+5][MAXN+5],B[MAXN+5][MAXN+5];
void read()
{
	string str;
	int i,j,k;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str;
		FOR2(j,str.size())
			A[i][j+1] = str[j] - '0';
	}
	FOR(i,1,N)
		FOR(j,1,N)
			FOR(k,0,10)
				DP[i][j][k] = -1;
}
int log2(int a)
{
	int s(0);
	while(a)
	{
		s++;
		a>>=1;
	}
	return s-1;
}
int control(int x1,int y1,int x2,int y2,bool color)
{
	int i,j,s(0);
	FOR(i,x1,x2)
		FOR(j,y1,y2)
			s+=(A[i][j] != color);
	return s;
}
int solve(int x,int y,int t)
{
	if(DP[x][y][t] != -1) return DP[x][y][t];
	if(!t) return 0;
	int i,j,k,n,m,mini(1000000),s;
	m = 1 << t;
	n = m >> 1;
	bool K[5];
	FOR(i,1,4)
		FOR(j,1,4)
			if(i != j)
			{
				s = 0;
				K[1] = K[2] = K[3] = K[4] = false;
				if(i == 1 || j == 1) s+=control(x,y,x+n-1,y+n-1,(i==1));
				if(i == 2 || j == 2) s+=control(x,y+n,x+n-1,y+m-1,(i==2));
				if(i == 3 || j == 3) s+=control(x+n,y+n,x+m-1,y+m-1,(i==3));
				if(i == 4 || j == 4) s+=control(x+n,y,x+m-1,y+n-1,(i==4));
				K[i] = K[j] = true;
				if(!K[1]) s+=solve(x,y,t-1);
				if(!K[2]) s+=solve(x,y+n,t-1);
				if(!K[3]) s+=solve(x+n,y+n,t-1);
				if(!K[4]) s+=solve(x+n,y,t-1);
				if(s < mini)
				{
					mini = s;
					DP2[x][y][t] = 10*i + j;
				}
			}
	return DP[x][y][t] = mini;
}
void boya(int x1,int y1,int x2,int y2,bool color)
{
	int i,j;
	FOR(i,x1,x2)
		FOR(j,y1,y2)
			B[i][j] = color;
}
void print(int x,int y,int t)
{
	if(!t) { B[x][y] = A[x][y]; return; }
	int a,b,i,m,n;
	bool K[5];
	m = 1 << t;
	n = m >> 1;
	a = DP2[x][y][t];
	b = a%10;
	a = a/10;
	K[1] = K[2] = K[3] = K[4] = false;
	K[a] = K[b] = true;
	if(a == 1 || b == 1) boya(x,y,x+n-1,y+n-1,(a==1));
	if(a == 2 || b == 2) boya(x,y+n,x+n-1,y+m-1,(a==2));
	if(a == 3 || b == 3) boya(x+n,y+n,x+m-1,y+m-1,(a==3));
	if(a == 4 || b == 4) boya(x+n,y,x+m-1,y+n-1,(a==4));
	if(!K[1]) print(x,y,t-1);
	if(!K[2]) print(x,y+n,t-1);
	if(!K[3]) print(x+n,y+n,t-1);
	if(!K[4]) print(x+n,y,t-1);
}
void print2()
{
	int i,j,k(0);
	for(i=1; i<=N; i++,printf("\n"))
		FOR(j,1,N)
			cout << B[i][j];
}
int main()
{
	read();
	int t = log2(N);
	printf("%d\n",solve(1,1,t));
	print(1,1,t);
	print2();
	return 0;
}
