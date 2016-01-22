#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 20
using namespace std;
pair < int , int > hash[1<<(MAXN+2)];
bool A[MAXN+5][MAXN+5];
string print(int a)
{
	string str = "";
	if(!a) return "0";
	while(a)
	{
		str+=char(a&1) +'0';
		a>>=1;
	}
	reverse(all(str));
	return str;
}
void solve()
{
	long long H,N,i,j,k,l,cur,pre,s(0);
	char c;
	bool flag = true;
	scanf("%lld %lld",&N,&H);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf(" %c",&c);
			A[i][j] = c - '0';
		}
	cur = 0;
	FOR(i,1,N)
		if(A[1][i])
		{
			cur^=(1<<i);
			s++;
		}
	pre = cur;
	FOR(l,2,H)
	{
		cur = 0;
		FOR(i,1,N)
		{
			bool k = (pre & (1 << i));
			FOR(j,1,N)
				if(A[i][j])
				{
					if(k)
						cur^=(1 << j);
					s+=!k + 1;
				}
		}
		if(hash[cur].f && flag)
		{
			flag = false;
			long long fark = (l - hash[cur].f);
			long long t = (H - l) / fark;
			s+=(s - hash[cur].s)*t;
			l+=fark * t;
			pre = cur;
			continue;
		}
		hash[cur] = make_pair(l,s);
		pre = cur;
	}
	printf("%lld\n",s);
}
int main()
{
	solve();
	return 0;
}
