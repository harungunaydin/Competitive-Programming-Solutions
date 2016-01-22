#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
//#define cin in
#define pb push_back
using namespace std;
ifstream in("a.in");
vector <int> V[10000];
vector <int> V1,V2;
int N;
int A[1005][1005];
bool hash[10005],visited[10005];
void read()
{
	int i,j,s,x;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> s;
		FOR(j,1,s)
		{
			cin >> x;
			V[i].push_back(x);
			V[x].push_back(i);
			A[x][i]=A[i][x]=true;
		}
	}
}
void team1(int x);
void team2(int x)
{
	vector <int> :: iterator it;
	if(visited[x]) return;
	visited[x]=true;
	V2.push_back(x);
	for(it=V[x].begin(); it!=V[x].end(); ++it)
		team1(*it);
}
void team1(int x)
{
	vector <int> :: iterator it;
	if(visited[x]) return;
	visited[x]=true;
	V1.push_back(x);
	for(it=V[x].begin(); it!=V[x].end(); ++it)
		team2(*it);
}
void print()
{
	vector <int> :: iterator it;
	for(it=V2.begin(); it!=V2.end(); ++it)
		cout << *it << " ";
	cout << endl;
	exit(0);
}
void solve()
{
	int a,i,s=0;
	FOR(i,1,N)
		if(!visited[i])
			team1(i);
	vector <int> :: iterator it,it2;
	if(V1.size()==N/2)
		print();
	for(it=V1.begin(); it!=V1.end(); ++it)
	{
		for(it2=V2.begin(); it2!=V2.end(); it2++)
			if(A[*it][*it2])
				break;
		if(it2==V2.end()) V2.pb((*it));
		if(V2.size()==N/2) print();
	}
}
int main()
{
	read();
	solve();
	return 0;
}
