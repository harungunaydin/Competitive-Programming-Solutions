#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[100005],son[100005],grup[100005];
bool B[100005],hash[100005];
int M,N,k;
void yerlestir(int x,int y)
{
	if(hash[y]) return;
	while(A[son[x]]) son[x]--;
	A[son[x]]=y;
	hash[y]=true;
}
void solve()
{
	int i,j,maxi=0,x,y;
	cin >> N >> M;
	FOR(i,1,N)
	{
		cin >> B[i];
		if(B[i]) { son[++k]=i; grup[k]=i; } 
	}
	FOR(i,1,M)
	{
		cin >> x >> y;
		A[x]=y;
		hash[y]=true;
	}
	FOR(i,1,k)
		FOR(j,grup[i-1]+1,grup[i])
			yerlestir(i,j);
	FOR(i,1,N)
	{
		maxi=max(maxi,A[i]);
		if((B[i] && maxi!=i) || (!B[i] && maxi==i))
		{
			cout << "not exist" << endl;
			return;
		}
	}
	FOR(i,1,N)
		cout << A[i] << " ";
	cout << endl;
}
int main()
{
	solve();
	return 0;
}
