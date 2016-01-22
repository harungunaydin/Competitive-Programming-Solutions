#include <iostream>
#include <set>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
using namespace std;
set < long long > st;
vector < long long > V;
bool ASAL[MAXN+5];
long long A,B,L;
void asal()
{
	int i,j;
	ASAL[1] = true;
	FOR(i,2,MAXN)
		if(!ASAL[i])
			for(j=i+i; j<=MAXN; j+=i)
				ASAL[j] = true;
}
void update(int x)
{
	V.clear();
	int i;
	FOR(i,2,x)
		if(!ASAL[i] && !(x%i))
			V.push_back(i);
}
long long us(long long a , long long b)
{
	return !b ? 1 : a*us(a,b-1);
}
long long hesapla()
{
	long long a,i,k,res(0),s,s2,t;
	a = us(2,V.size());
	vector < long long > :: iterator it;
	for(i=1; i<a; i++)
	{
		k = i;
		s = s2 = 0;
		t = 1;
		while(k)
		{
			if(k&1) { t*=V[s]; s2++; }
			k>>=1;
			s++;
		}
		res+=(s2&1) ? L/t : -L/t;
	}
	return L - res;
}
void solve()
{
	set < long long > :: iterator sit;
	vector < long long > :: iterator it;
	long long a,b,c,i,res0(0),res1(0),res2(0),t;
	scanf("%lld %lld %lld",&A,&B,&L);
	A+=B+1;
	V.clear();
	FOR(i,1,A-2)
	{
		update(i);
		st.clear();
		for(it = V.begin(); it!=V.end(); ++it)
			st.insert(*it);
		a = hesapla();
		update(A-i-1);
		b = hesapla();
		for(it = V.begin(); it!=V.end(); ++it)
			st.insert(*it);
		V.clear();
		t = 1;
		for(sit = st.begin(); sit!=st.end(); ++sit)
			V.push_back(*sit);
		c = hesapla();
		res2+=c;
		res1+=a+b-2*c;
	}
	update(A-1);
	a = 2*(hesapla()-1);
	res1+=a;
	res2+=2;
	printf("%lld\n%lld\n%lld\n",L*A-res1-res2,res1,res2);
}
int main()
{
	asal();
	solve();
	return 0;
}
