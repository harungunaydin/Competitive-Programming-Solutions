#include <iostream>
#include <cmath>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
vector <pii> V;
const double PI = 2*acos(-1);
bool cmp(const pii &a,const pii &b)
{
	double c=atan2(a.s,a.f),d=atan2(b.s,b.f);
	if(c < 0) c+=PI;
	if(d < 0) d+=PI;
	return atan2(a.s,a.f) < atan2(b.s,b.f);
}
void solve()
{
	int N,a,b,i;
	char c;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> a >> b >> c;
		if(c == 'Y')
			V.push_back(make_pair(a,b));
	}
	sort(all(V),cmp);
	printf("%d\n",V.size());
	vector <pii> :: iterator it;
	for(it = V.begin(); it!=V.end(); ++it)
		printf("%d %d\n",it->f,it->s);
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
