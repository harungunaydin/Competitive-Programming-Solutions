#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define AYRIKMI(A,B) (A.sol >= B.sag || A.sag <= B.sol || A.ust <= B.alt || A.alt >= B.ust)
using namespace std;
class dik
{
	public:
		int alt,ust,sag,sol;
		dik read() { cin >> sol >> alt >> sag >> ust; return (*this); }
		int area() { return (ust-alt)*(sag-sol); }
};
vector <dik> dix;
void add(dik yeni)
{
	dik t,t2;
	vector <dik> temp;
	temp.clear();
	temp.push_back(yeni);
	vector <dik> :: iterator it;
	for(it = dix.begin(); it!=dix.end(); ++it)
		if(!AYRIKMI(yeni,(*it)))
		{
			t = t2 = *it;
			if(t.sol <= yeni.sol && yeni.sol <= t.sag)
			{
				t.sol = yeni.sol;
				t2.sag = yeni.sol;
				temp.push_back(t2);
			}
			t2 = t;
			if(t.sol <= yeni.sag && yeni.sag <= t.sag)
			{
				t.sag = yeni.sag;
				t2.sol = yeni.sag;
				temp.push_back(t2);
			}
			t2 = t;
			if(t.alt <= yeni.ust && yeni.ust <= t.ust)
			{
				t.ust = yeni.ust;
				t2.alt = yeni.ust;
				temp.push_back(t2);
			}
			t2 = t;
			if(t.alt <= yeni.alt && yeni.alt <= t.ust)
			{
				t.alt = yeni.alt;
				t2.ust = yeni.alt;
				temp.push_back(t2);
			}
		}
		else
			temp.push_back(*it);
	dix = temp;
}
void solve()
{
	dik a;
	int i,s=0;
	FOR(i,1,4)
		add(a.read());
	vector <dik> :: iterator it;
	for(it = dix.begin(); it!=dix.end(); ++it)
		s+=it->area();
	cout << s << endl;
}
int main()
{
	solve();
	return 0;
}
