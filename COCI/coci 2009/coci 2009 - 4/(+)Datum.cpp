#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
string days[10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" , "Sunday" };
int MONTH[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
string solve()
{
	int a,b,i,j,s(3);
	scanf("%d %d",&a,&b);
	FOR(i,1,12)
		FOR(j,1,MONTH[i])
		{
			if(i == b && j == a) return days[s];
			s = (s+1)%7;
		}
}
int main()
{
	cout << solve() << endl;
	return 0;
}
