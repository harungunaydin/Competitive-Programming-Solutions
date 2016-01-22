//28.10.11 21:41
#include <iostream>
using namespace std;
int N,s;
int A[10005][3];
bool visited[100005];
void solve(int x)
{
	if(!x || x==N || visited[x]) return;
	visited[x]=++s;
	(A[x][1])? (solve(A[x][1]),solve(A[x][2])) : solve(x+1);
}
main(void)
{
	string temp="";
	while(temp!=".")
	{
		cin >> temp;
		N++;
		if(temp=="ILI") cin >> A[--N][2];
		else if(temp=="IDI") cin >> A[N][1];
	}
	solve(1);
	cout << N-s-1 << endl;
}


