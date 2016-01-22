#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
long long gcd( long long a , long long b )
{
	return !b ? a : gcd(b,a%b);
}
long long lcm( long long a , long long b )
{
	return a * b / gcd(a,b);
}
void solve()
{
	string str;
	int i,j;
	cin >> str;
	if(str[0] == '5')
	{
		printf("0 0 0 0 1\n");
		return;
	}
	FOR(i,1,5)
		if(i == str[0] - '0')
		{
			long long on(1),t(0);
			
			for(j = 2; j < (int) str.size(); j++,on*=10)
				t = t * 10ll + str[j] - '0';

			if(!t)
			{
				printf("1 ");
				continue;
			}

			long long l = lcm( t , on - t );
			printf("%lld %lld " , l / t , l / (on - t) );

			i++;
		}
		else
			printf("0 ");
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
