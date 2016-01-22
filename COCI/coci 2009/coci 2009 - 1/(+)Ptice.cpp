#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
string str;
string A[3] = { "ABC","BABC","CCAABB" };
void solve()
{
	int N,i,s1(0),s2(0),s3(0);
	scanf("%d",&N);
	cin >> str;
	FOR2(i,str.size())
	{
		s1+=(str[i] == A[0][i%3]);
		s2+=(str[i] == A[1][i%4]);
		s3+=(str[i] == A[2][i%6]);
	}
	int maxi = max(s1,max(s2,s3));
	printf("%d\n",maxi);
	if(s1 == maxi) printf("Adrian\n");
	if(s2 == maxi) printf("Bruno\n");
	if(s3 == maxi) printf("Goran\n");
}
int main()
{
	solve();
	return 0;
}
