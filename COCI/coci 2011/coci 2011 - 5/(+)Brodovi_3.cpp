#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V;
int N,s;
int A[5005];
bool kontrol(int x)
{
	for(vector <int> :: iterator it=V.begin(); it!=V.end(); ++it)
		if(!(x%(*it)))
			return 0;
	return 1;
}
void solve()
{
	int N,i;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",&A[i]);
	FOR(i,2,N)
		if(kontrol(A[i]-1))
			V.push_back(A[i]-1);
	printf("%d\n",V.size());
}
int main()
{
	solve();
	return 0;
}
