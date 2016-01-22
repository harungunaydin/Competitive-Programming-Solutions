#include <iostream>
using namespace std;
int solve(int N)
{
	int i,j;
	for(i=0; i<=2000; i++)
		for(j=0; j<=2000; j++)
			if(i*3 + j*5 == N)
				return i + j;
	return -1;
}
int main()
{
	int N;
	scanf("%d",&N);
	cout << solve(N) << endl;
	return 0;
}
