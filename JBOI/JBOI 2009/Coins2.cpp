#include <iostream>
#include <fstream>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
set < pair < int , char > > st4;
set < int > st,st2,st3;
int A[10][10];
char C[5];
char find(int i,int x)
{
	int j;
	if(C[i] == '<')
	{
		FOR(j,1,4)
			if(A[i*2-1][j] == x)
				break;
		return j == 5 ? '+' : '-';
	}
	else if(C[i] == '>')
	{
		FOR(j,1,4)
			if(A[i*2-1][j] == x)
				break;
		return j == 5 ? '-' : '+';
	}
	return '#';
}
void solve()
{
	int i,j,k;
	FOR(i,1,12)
		st.insert(i);
	cin >> A[1][1] >> A[1][2] >> A[1][3] >> A[1][4] >> C[1] >> A[2][1] >> A[2][2] >> A[2][3] >> A[2][4];
	cin >> A[3][1] >> A[3][2] >> A[3][3] >> A[3][4] >> C[2] >> A[4][1] >> A[4][2] >> A[4][3] >> A[4][4];
	cin >> A[5][1] >> A[5][2] >> A[5][3] >> A[5][4] >> C[3] >> A[6][1] >> A[6][2] >> A[6][3] >> A[6][4];
	FOR(i,1,3)
		if(C[i] == '=')
			FOR(j,i*2-1,i*2)
				FOR(k,1,4)
					st.erase(A[j][k]);
	set < int > :: iterator it;
	FOR(i,1,3)
		if(C[i] != '=')
		{
			FOR(j,i*2-1,i*2)
				FOR(k,1,4)
					st2.insert(A[j][k]);
			for(it = st.begin(); it != st.end(); ++it)
				if(st2.find(*it) != st2.end())
					st3.insert(*it);
			st2.clear();
			st = st3;
			st3.clear();
		}
	if(st.empty()) { printf("impossible\n"); return; }
	char c,t1,t2,t3;
	c = t1 = t2 = t3 = ' ';
	for(it = st.begin(); it != st.end(); ++it)
	{
		if(C[1] != '=') t1 = find(1,*it);
		if(C[2] != '=') t2 = find(2,*it);
		if(C[3] != '=') t3 = find(3,*it);
		if((t1 == t2 || t1 == ' ' || t2 == ' ') && (t2 == t3 || t2 == ' ' || t3 == ' '))
			st4.insert( make_pair( *it , (t1 != ' ') ? t1 : (t2 != ' ') ? t2 : t3) );
	}
	set < pair < int , char > > :: iterator it2;
	if(st4.empty()) printf("indefinite\n");
	for(it2 = st4.begin(); it2 != st4.end(); ++it2)
		cout << it2->first << it2->second << endl;
}
int main()
{
	solve();
	return 0;
}
