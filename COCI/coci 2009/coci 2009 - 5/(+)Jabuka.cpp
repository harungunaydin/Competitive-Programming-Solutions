#include <iostream>
#include <set>
#define mp(a,b,c) make_pair(make_pair(a,b),c)
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
set < pair < pii , int > > st;
void solve()
{
	int A,B,i,t;
	bool f;
	scanf("%d %d",&A,&B);
	f = (A < B);
	if(f) swap(A,B);
	for(i=1; i*i<=A; i++)
		if(!(A%i))
		{
			t = A/i;
			if(!(B%i)) st.insert( mp(i,t,B/i) );
			if(!(B%t)) st.insert( mp(t,i,B/t) ); 
		}
	set < pair < pii , int > > :: iterator it;
	for(it = st.begin(); it!=st.end(); ++it)
		if(f)
			printf("%d %d %d\n",it->f.f,it->s,it->f.s);
		else
			printf("%d %d %d\n",it->f.f,it->f.s,it->s);
}
int main()
{
	solve();
	return 0;
}
