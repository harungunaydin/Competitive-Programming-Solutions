//SORU 511
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "scrbl.in"
#define INPUT2 "scrbl.scrbl.txt"
#define OUTPUT "scrbl.out"
#define MAXN 10
using namespace std;
ifstream in(INPUT);
ifstream in2(INPUT2);
ofstream out(OUTPUT);
set <string> res;
string str;
int M,N,l,s;
char A[MAXN+5],B[50000][200];
string S[50000];
bool calc_and_check(int x)
{
	int i,s=0;
	FOR(i,'A','Z')
	{
		if(B[0][i] > B[x][i])
			return 0;
		else if(B[0][i] < B[x][i])
		{
			s+=B[x][i] - B[0][i];
			if(s > B[0]['#'])
				return 0;
		}
	}
	return 1;
}
int Try()
{
	int i;
	FOR(i,1,s)
		if(calc_and_check(i))
			res.insert(S[i]);
}
void rec(int x,int k)
{
	if(k == l) { Try(); return; }
	int i;
	FOR(i,x+1,N)
	{
		B[0][A[i]]++;
		rec(i,k+1);
		B[0][A[i]]--;
	}
}
void solve()
{
	int i,j;
	string temp;
	in >> N >> M;
	FOR(i,1,N)
		in >> A[i];
	FOR(i,1,M)
	{
		in2 >> temp;
		if(temp.size() <= N)
		{
			for(j = 0,s++; j<temp.size(); j++)
				B[s][temp[j]]++;
			S[s] = temp;
		}
	}
	FOR(l,1,N)
		rec(0,0);
	set <string> :: iterator it;
	for(it = res.begin(); it!=res.end(); ++it)
		out << *it << endl;
}
int main()
{
	solve();
	return 0;
}
