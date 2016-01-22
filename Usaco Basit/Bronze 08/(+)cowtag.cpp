//SORU 512
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "cowtag.in"
#define OUTPUT "cowtag.out"
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define MAXN 1000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
typedef pair <int,int> pii;
pii p[MAXN+5];
int N;
double Distance[MAXN+5][MAXN+5];
bool visited[MAXN+5];
int enyakin(int x)
{
	int a,i;
	double mini = (double)INT_MAX;
	FOR(i,1,N)
		if(x!=i && !visited[i] && Distance[x][i] < mini)
		{
			mini = Distance[x][i];
			a = i;
		}
	return a;
}
void solve()
{
	int a,i,j,s=2;
	in >> N;
	FOR(i,1,N)
	{
		in >> p[i].f >> p[i].s;
		FOR(j,1,i-1)
			Distance[i][j]=Distance[j][i]=sqrt((p[i].f-p[j].f)*(p[i].f-p[j].f) + (p[i].s-p[j].s)*(p[i].s-p[j].s));
	}
	while(s<=N)
	{
		for(i=1; i<=N; i++)
			if(!visited[i])
			{
				a = enyakin(i);
				visited[a] = true;
				s++;
			}
	}
	FOR(i,1,N)
		if(!visited[i])
			break;
	out << i << endl;
}
int main()
{
	solve();
	return 0;
}
