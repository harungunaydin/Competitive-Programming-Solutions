#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 25
using namespace std;
int sat[6] , satir[6] , sut[6];
int DP[600][6][6][6][6][6];
char A[MAXN];
bool used[MAXN];
int dp(int k,int a,int b,int c,int d,int e,int t)
{
	int &ret = DP[k][a][b][c][d][e];
	if(ret) return ret;
	if(used[t]) return ret = dp(k,a,b,c,d,e,t+1);
	ret = 0;
	if(a < 5 && t > sat[0] && t > sut[a]) ret += dp(k,a+1,b,c,d,e,t+1);
	if(b < a && t > sat[1] && t > sut[b]) ret += dp(k,a,b+1,c,d,e,t+1);
	if(c < b && t > sat[2] && t > sut[c]) ret += dp(k,a,b,c+1,d,e,t+1);
	if(d < c && t > sat[3] && t > sut[d]) ret += dp(k,a,b,c,d+1,e,t+1);
	if(e < d && t > sat[4] && t > sut[e]) ret += dp(k,a,b,c,d,e+1,t+1);

	return ret;

}
void solve1()
{
	int i,j,res(0),s(0),t,x,y;
	scanf("%s",A);
	FOR2(i,25)
	{
		x = i/5; y = i%5;
		satir[x]++;
		t = A[i] - 'A';
		FOR2(j,t)
			if(!used[j] && j > sat[x] && j > sut[y])
			{
				sat[x] = sut[y] = j;
				used[j] = true;
				DP[++s][5][5][5][5][5] = 1;
				res += dp(s,satir[0],satir[1],satir[2],satir[3],satir[4],0);
				used[j] = false;
			}
		used[ t ] = true;
		sat[x] = sut[y] = t;
	}
	printf("%d\n" , res + 1 );
}
void solve2()
{

	int T,i,j,s(0),t,x,y;
	scanf("%d",&T);
	FOR2(i,25)
	{
		x = i/5; y = i%5;
		satir[x]++;
		FOR2(j,25)
			if(!used[j] && j > sat[x] && j > sut[y])
			{
				used[j] = true;
				sat[x] = sut[y] = j;
				
				DP[++s][5][5][5][5][5] = 1;
				t = dp(s,satir[0],satir[1],satir[2],satir[3],satir[4],0);

				if(T <= t)
				{
					printf("%c",j + 'A');
					break;
				}
				T -= t;

				used[j] = false;
			}
	}
	printf("\n");
}
int main()
{
	memset( sat , -1 , sizeof sat );
	memset( sut , -1 , sizeof sut );
	char c;
	scanf("%c" , &c);
	if(c == 'W') solve1();
	else solve2();
	return 0;
}
