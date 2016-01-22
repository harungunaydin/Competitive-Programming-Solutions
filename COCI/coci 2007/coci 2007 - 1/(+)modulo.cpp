#include <cstdio>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
set < int > st;
void solve()
{
	int a,i;
	FOR(i,1,10)
	{
		scanf("%d",&a);
		st.insert(a%42);
	}
	printf("%d\n" , (int) st.size() );
}
int main()
{
	solve();
	return 0;
}
