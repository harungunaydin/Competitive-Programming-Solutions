#include <iostream>
#include <set>
#define FOR(_i,__a,___b) for(_i=__a; _i<=___b; _i++)
#define FOR2(_i,__n)  FOR(_i,0,__n-1)
#define alan(a) (a.f*a.s)
#define MAX(a,b) ((a > b) ? a : b)
#define Max(a,b,c,d) MAX(MAX(a,b),MAX(c,d))
#define max(a,b,c) MAX(a,MAX(b,c))
#define f first
#define s second
using namespace std;
typedef pair <int,int> rect;
set <int> st;
rect d[5],t[5];
int i,j,res=214231231;
string perm[25] = { "1234","1243","1324","1342","1423","1432",
										"2134","2143","2314","2341","2413","2431",
										"3124","3142","3214","3241","3412","3421",
										"4123","4132","4213","4231","4312","4321"
									};
void swap(rect *a)
{
	swap(a->f,a->s);
}
void hallet(rect a)
{
	if(a.f > a.s) swap(&a);
	int tmp = alan(a);
	if(tmp < res)
	{
		res = tmp;
		st.clear();
	}
	if(tmp == res && st.find(a.s) == st.end())
		st.insert(a.f);
}
void _1()
{
	rect a;
	a.f = Max(t[1].f,t[2].f,t[3].f,t[4].f);
	a.s = t[1].s + t[2].s + t[3].s + t[4].s;
	hallet(a);
	if(alan(a) == 308) cout << "1\n";
}
void _2()
{
	rect a;
	a.f = max(t[1].f,t[2].f,t[3].f) + t[4].f;
	a.s = MAX(t[4].s,t[1].s+t[2].s+t[3].s);
	hallet(a);
	if(alan(a) == 308) cout << "2\n";
}
void _3()
{
	rect a;
	a.f = max(t[1].f,t[2].f+t[4].f,t[3].f+t[4].f);
	a.s = MAX(t[1].s+t[2].s+t[3].s,t[1].s+t[4].s);
	hallet(a);
	if(alan(a) == 308) cout << "3\n";
}
void _4()
{
	rect a;
	a.f = max(t[1].f,t[2].f+t[3].f,t[4].f);
	a.s = t[1].s + MAX(t[2].s,t[3].s) + t[4].s;
	if(alan(a) == 308) cout << "4\n";
	hallet(a);
}
void _5()
{
	rect a,b,c,d,cvp;
	a = t[1]; b = t[2]; c = t[3]; d = t[4];
	if(c.f < b.f) return;
	if(b.f + a.f <= c.f)
	{
		cvp.f = c.f+d.f;
		cvp.s = max(d.s,a.s+c.s,b.s+c.s);
	}
	else if(d.s <= c.s)
	{
		cvp.f = MAX(c.f+d.f,a.f+b.f);
		cvp.s = MAX(a.s,b.s)+c.s;
	}
	else
	{
		cvp.f = MAX(a.f+b.f,c.f+d.f);
		cvp.s = MAX(a.s+d.s,b.s+c.s);
	}
	if(alan(cvp) == 308) cout << "5\n";
	hallet(cvp);
}
void solve()
{
	int k;
	FOR(i,1,4)
		scanf("%d %d",&d[i].f,&d[i].s);
	FOR2(i,16)
		FOR2(j,24)
		{
			FOR(k,1,4) t[k] = d[perm[j][k-1]-'0'];
			FOR2(k,4)
				if(i&(1<<k))
					swap(t+k+1);
			_1(); _2(); _3(); _4(); _5();
		}
		set <int> :: iterator it;
		printf("%d\n",res);
		for(it = st.begin(); it!=st.end(); ++it)
			printf("%d %d\n",*it,res/(*it));
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
