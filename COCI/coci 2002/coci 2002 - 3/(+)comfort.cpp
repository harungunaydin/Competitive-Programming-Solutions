#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
bool hash[100000],visited[100000];
int H,i,j,M,N,x;
int comfort(int x)
{
	if(visited[x] || hash[x]) return 0;
	if(x==H) return 1;
	visited[x]=true;
	return (x+i==N)? comfort(N) : comfort((x+i)%N);
}
int solve()
{
	cin >> N >> H >> M;
	FOR(i,1,M)
	{
		cin >> x;
		hash[x]=true;
	}
	FOR(i,1,N)
	{
		if(comfort(1))
			return i;
		FOR(j,1,N)
			visited[j]=false;
	}
}
int main()
{
	cout << solve() << endl;
	return 0;
}
