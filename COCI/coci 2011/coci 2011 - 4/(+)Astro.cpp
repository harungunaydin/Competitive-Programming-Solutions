#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1500
using namespace std;
string days[] = { "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };
int a,b,ia,ib;
int day[2];
int A[MAXN+5][MAXN+5],B[MAXN+5][MAXN+5];
bool durum[MAXN+5][MAXN+5];
void read()
{
	int c,d,i,j;
	scanf("%d : %d",&c,&d);
	a =  c*60 + d;
	scanf("%d : %d",&c,&d);
	b =  c*60 + d;
	scanf("%d : %d",&c,&d);
	ia = c*60 + d;
	scanf("%d : %d",&c,&d);
	ib = c*60 + d;
}
int hallet(int x,bool c)
{
	int a = x/60,b = x%60;
	while(a>=24) { a-=24; day[c]++; }
	return a*60 + b;
}
void print(int x)
{
	int a=x/60,b=x%60;
	printf("%d%d:%d%d",a/10,a%10,b/10,b%10);
}
void solve()
{
	A[a][0] = B[b][0] = 0;
	while(1)
	{
		if(durum[a][b]) { printf("Never"); return; }
		durum[a][b] = true;
		a = hallet(a+ia,0);
		b = hallet(b+ib,1);
		if(B[a][day[0]])
		{
			cout << days[day[0]%7] << endl;
			print(a);
			return;
		}
		if(A[b][day[1]])
		{
			cout << days[day[1]%7] << endl;
			print(b);
			return;
		}
		A[a][day[0]] = B[b][day[1]] = true;
	}
}
int main()
{
	read();
	solve();
	printf("\n");
	return 0;
}
