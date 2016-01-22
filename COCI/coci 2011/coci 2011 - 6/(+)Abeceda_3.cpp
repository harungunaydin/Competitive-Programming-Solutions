#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
queue <char> Q;
int B[125];
bool A[125][125];
bool hash[125];
string str[105];
void solve()
{
	int N,i,j,s=0;
	string result="";
	scanf("%d",&N);
	char a,b,cc[10];
	FOR(i,1,N)
	{
		scanf("%s",cc);
		str[i]=cc;
	}
	FOR(i,1,N)
		FOR2(j,str[i].size())
			hash[str[i][j]]=true;
	FOR(i,1,N-1)
		FOR2(j,str[i].size())
		{
			a=str[i][j];
			b=str[i+1][j];
			if(a!=b)
			{
				if(A[b][a]) { printf("!\n"); return; }
				if(!A[a][b])
					B[b]++;
				A[a][b]=true;
				break;
			}
		}
	FOR(b,'a','z')
		if(hash[b] && !B[b] && ++s)
			Q.push(b);
	if(!s) { printf("!\n"); return; }
	if(s>1) { printf("?\n"); return; }
	while(!Q.empty())
	{
		a=Q.front(); Q.pop();
		result+=a;
		s=0;
		FOR(b,'a','z')
			if(hash[b] && A[a][b] && !(--B[b]) && ++s)
				Q.push(b);
		if(s>1) { printf("?\n"); return; }
	}
	cout << result << endl;
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
