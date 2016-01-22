//SORU 1050
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "coldwat.in"
#define OUTPUT "coldwat.out"
#define all(x) x.begin(),x.end()
#define EKLE(x,s) { qx.push(x); qs.push(s); }
#define BAK(x,s) { x = qx.front(); s = qs.front(); qx.pop(); qs.pop(); }
#define f first
#define s second
#define MAXN 8000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
typedef pair <int,int> pii;
queue <int> Q;
pii p[MAXN+5];
int A[MAXN+5],BT[2*MAXN+5],result[MAXN+5];
void solve()
{
	int M,N,a,b,c,i,x,s,syc=1,yer;
	cin >> N >> M;
	FOR(i,1,M)
	{
		cin >> a >> b >> c;
		p[a] = make_pair(b,c);
	}
	BT[1] = A[1] = 1;
	while(syc<=M)
	{
		FOR(i,1,N)
			if(A[i] && p[i].f)
			{
				syc++;
				yer = A[i];
				yer<<=1;
				BT[yer] = p[i].f;
				BT[yer+1] = p[i].s;
				A[p[i].f] = yer;
				A[p[i].s] = yer + 1;
				p[i].f = 0;
			}
	}
	queue <int> qx,qs;
	EKLE(1,1);
	while(!qx.empty())
	{
		BAK(x,s);
		if(!BT[x]) continue;
		EKLE(2*x,s+1);
		EKLE(2*x+1,s+1);
		result[BT[x]] = s;
	}
	FOR(i,1,N)
		cout << result[i] << endl;
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
