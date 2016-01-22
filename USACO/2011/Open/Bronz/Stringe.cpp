#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int main()
{
	int N,T,Z,i,j;
	string str;
	scanf("%d",&Z);
	FOR(i,1,Z)
	{
		scanf("%d %d",&N,&T);
		cin >> str;
		FOR(j,1,T)
			str=str.substr(N) + str;
		cout << str << endl;
	}
	return 0;
}
