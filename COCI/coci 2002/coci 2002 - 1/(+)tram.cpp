#include <iostream>
#include <climits>
using namespace std;
int a,b,N,mini=INT_MAX;
int A[1005][1005];
int B[1005];
bool visited[1005];
void read()
{
	int i=1,j,x,y;
	string str;
	cin >> N >> a >> b;
	for(; i<=N; i++)
	{
		cin >> x;
		B[i]=x;
		for(j=1; j<=x; j++)
		{
			cin >> y;
			A[i][j]=y;
		}
	}
}
void solve(int x,int s)
{
	if(s>=mini) return;
	if(x==b) { mini=min(mini,s); return; }
	for(int i=1; i<=B[x]; i++)
		if(!visited[A[x][i]])
		{
			visited[A[x][i]]=true;
			solve(A[x][i],s+(i>1));
			visited[A[x][i]]=false;
		}
}
int main()
{
	read();
	solve(a,0);
	if(mini==INT_MAX) mini=-1;
	cout << mini << endl;
	return 0;
}
