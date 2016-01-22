#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define cevir(x) (x-'0')
#define to_minute_from_hour(str) ((cevir(str[0])*10+cevir(str[1]))*60 + cevir(str[3])*10+cevir(str[4]))
using namespace std;
int A[10005];
void print(int a)
{
	if(a/60<10) printf("0");
	printf("%d:",a/60);
	if(a%60<10) printf("0");
	printf("%d\n",a%60);
}
void solve()
{
	int N,i,t1=0,t2=0,s1=0,s2=0,x;
	string str;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&x);
		cin >> str;
		A[to_minute_from_hour(str)]=x;
	}
	FOR(i,0,2880)
	{
		if(s1>s2) t1++;
		else if(s1<s2) t2++;
		if(A[i]==1)
			s1++;
		else if(A[i]==2)
			s2++;
	}
	print(t1);
	print(t2);
}
int main()
{
	solve();
	return 0;
}
