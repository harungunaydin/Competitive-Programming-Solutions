#include <iostream>
#include <cmath>
#include <set>
#define sqr(a) ((a)*(a))
#define f first
#define s second
#define EPS 0.000000001
#define is_equal(a,b) (abs(a-b) < EPS)
using namespace std;
typedef pair <double,double> pdd;
set <pdd> st;
void solve()
{
	double a,a2,b,b2,c,d,d2,r1,r2,sd,x,x1,x2,y,y1,y2;
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
	if(is_equal(x1,x2) && is_equal(y1,y2) && is_equal(r1,r2)) { cout << 3 << endl; return; }
	d = sqr((x2-x1))+sqr(y2-y1);
	sd = sqrt(d);
	if(is_equal(sd+min(r1,r2),max(r1,r2))) { cout << 0 << endl; return; }
	if(is_equal(d,0) || sqr(r1+r2) < d) { cout << 0 << endl; return; }
	d2 = 2*d;
	cout << d2 << endl;
	a = (x1+x2)/2 + ((x2-x1)*(r1*r1-r2*r2))/d2;
	b = (y2-y1)/d2;
	cout << "b = " << b << endl;
	b*= sqrt(  (sqr(r1+r2)-d) * (d - sqr(r2-r1)) );
	cout << a << " " << b << endl;
	a2 = (y1+y2)/2 + ((y2-y1)*(r1*r1-r2*r2))/d2;
	b2 = (x2-x1)/d2;
	b2*= sqrt( (sqr(r1+r2) - d)*(d - sqr(r2-r1)) );
	st.insert(make_pair(a+b,a2+b2));
	st.insert(make_pair(a+b,a2-b2));
	st.insert(make_pair(a-b,a2+b2));
	st.insert(make_pair(a-b,a2-b2));
	set <pdd> :: iterator it;
	cout << st.size() << endl;
	if(st.size())
		for(it = st.begin(); it!=st.end(); ++it)
			printf("%.6lf %.6lf\n",it->f,it->s);
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
/*
0 0 100
2 2 5
*/
