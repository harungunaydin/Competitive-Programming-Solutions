#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 
using namespace std;
typedef pair <int,int> pii;
vector <pii> pro[105];
int prfiyat[105];
int N,S;
int DP[6][6][6][6][6];
int C[1000],D[1000],P[15],K[1000],V[1000];
void read()
{
	int a,b,c,i,j;
	scanf("%d",&S);
	FOR(i,1,S)
	{
		scanf("%d",&c);
		FOR2(j,c)
		{
			scanf("%d %d",&a,&b);
			pro[i].push_back(make_pair(a,b));
		}
		scanf("%d",prfiyat+i);
	}
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d %d",&a,K+i,V+i);
		C[i] = a;
		D[a] = i;
	}
}
void solve()
{
	vector <pii> :: iterator it;
	int a,b,c,d,e,i,j,mini,v=0;
	FOR(a,0,K[1])
		FOR(b,0,K[2])
			FOR(c,0,K[3])
				FOR(d,0,K[4])
					FOR(e,0,K[5])
					if(a || b || c || d || e)
					{
						mini = a*V[1]+b*V[2]+c*V[3]+d*V[4]+e*V[5];
						FOR(i,1,S)
						{
							fill(P+1,P+10,0);
							for(it = pro[i].begin(); it!=pro[i].end(); ++it)
								P[D[it->f]] = it->s;
							if(a >= P[1] && b >= P[2] && c >= P[3] && d >= P[4] && e >= P[5])
								mini = min(mini,DP[a-P[1]][b-P[2]][c-P[3]][d-P[4]][e-P[5]]+prfiyat[i]);
						}
						DP[a][b][c][d][e] = mini;
					}	
	printf("%d\n",DP[K[1]][K[2]][K[3]][K[4]][K[5]]);
}
int main()
{
	read();
	solve();
	return 0;
}
