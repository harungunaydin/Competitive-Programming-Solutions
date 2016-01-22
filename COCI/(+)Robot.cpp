#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
#define MAXL 1000000
using namespace std;
typedef long long lli;
int M,N,X,Y,alt,sag,sol,ust;
long long sum;
int satir[2*MAXL+5],sutun[2*MAXL+5];
long long hesapla(char c)
{
	if(c == 'S')
	{
		sum+=(lli)alt - (lli)ust + (lli)satir[Y];
		alt+=satir[Y];
		ust-=satir[++Y];
	}
	else if(c == 'J')
	{
		sum+=(lli)ust - (lli)alt + (lli)satir[Y];
		ust+=satir[Y];
		alt-=satir[--Y];
	}
	else if(c == 'I')
	{
		sum+=(lli)sol - (lli)sag + (lli)sutun[X];
		sol+=sutun[X];
		sag-=sutun[++X];
	}
	else
	{
		sum+=(lli)sag - (lli)sol + (lli)sutun[X];
		sag+=sutun[X];
		sol-=sutun[--X];
	}
	return sum;
}
void solve()
{
	int a,b,i;
	char c;
	scanf("%d %d",&N,&M);
	sol = 0;
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		a+=MAXL;
		b+=MAXL;
		sutun[a]++;
		satir[b]++;
		if(a < MAXL) sol++;
		if(a > MAXL) sag++;
		if(b < MAXL) alt++;
		if(b > MAXL) ust++;
		sum+=abs(MAXL-a) + abs(MAXL-b);
	}
	X = Y = MAXL;
	FOR(i,1,M)
	{
		scanf(" %c",&c);
		printf("%lld\n",hesapla(c));
	}
}
int main()
{
	solve();
	return 0;
}
