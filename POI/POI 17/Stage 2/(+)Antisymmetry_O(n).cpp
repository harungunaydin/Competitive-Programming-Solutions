#include <cstdio>
#include <vector>
#define MAXN 500005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
char A[MAXN];
void solve()
{
	vector < int > V;
	long long res(0);
	int N , i,j,k;

	N = read();
	scanf("%s" , A );

	i = j = 0;
	while(i < N)
	{
		while( j <= i && i+j+1 < N && A[i-j] != A[i+j+1]) j++;
		V.push_back(j); res += j;

		k = 1;
		while( k <= i && k <= j && V[i-k] != V[i] - k)
		{
			V.push_back( min(V[i-k],V[i]-k) );
			res += V.back();
			k++;
		}
		j = max(0,j-k);
		i += k;
	}

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
