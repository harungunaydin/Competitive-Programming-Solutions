#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(x,s) { qx.push(x); qs.push(s); }
#define BAK(x,s) { x=qx.front(); s=qs.front(); qx.pop(); qs.pop(); }
using namespace std;
queue <int> qx,qs;
vector <int> V[1005];
int N,sayi;
int iki[]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
bool hash[3000000];
void read()
{
	int a=0,i,j,s,x;
	bool b;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> b;
		if(b) a|=iki[i];
	}
	EKLE(a,0);
	FOR(i,1,N)
	{
		cin >> s;
		FOR(j,1,s)
		{
			cin >> x;
			V[i].push_back(x);
		}
	}
}
void degistir(int x)
{
	vector <int> :: iterator it;
	for(it=V[x].begin(); it!=V[x].end(); ++it)
		sayi&=(~(iki[*it]));
	sayi|=iki[x];
}
int solve()
{
	int a,i,s,temp;
	while(!qs.empty())
	{
		BAK(sayi,s);
		if(sayi==4) return s;
		if(hash[sayi]) continue;
		hash[sayi]=true;
		int k=1;
		for(i=1; i<=N; i++)
			if(!(sayi&iki[i]))
			{
				temp=sayi;
				degistir(i);
				if(!hash[sayi]) EKLE(sayi,s+1);
				sayi=temp;
			}
	}
}
int main()
{
	read();
	cout << solve() << endl;
	return 0;
}
