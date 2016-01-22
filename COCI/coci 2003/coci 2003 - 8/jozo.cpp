#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define EKLE(x,y,s) Q.push(make_pair(make_pair(-s,x),y))
#define BAK(x,y,s) { x=Q.top().first.second; y=Q.top().second; s=-Q.top().first.first; Q.pop(); }
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define cin in
using namespace std;
ifstream in("jozo.in");
vector <int> tr[1005],V[1005][1005];
priority_queue < pair < pair<int,int>,int > > Q;
int N,P,T1,T2,TREN;
int A[1005][1005],tme[1005];
bool visited[1005][1005];
void read()
{
	int c,i,j,s,x,y;
	cin >> N >> P >> TREN >> T1 >> T2;
	FOR(i,1,P)
	{
		cin >> x >> y >> c;
		A[x][y]=A[y][x]=c;
	}
	FOR(i,1,TREN)
	{
		cin >> tme[i] >> s;
		FOR(j,1,s)
		{
			cin >> x;
			tr[i].push_back(x);
		}
	}
}
void hesapla()
{
	int a,i,j,s;
	FOR(i,1,TREN)
	{
		s=tme[i];
		a=tr[i].size()-1;
		V[i][tr[i][0]].push_back(tme[i]);
		FOR(j,1,a)
		{
			s+=A[tr[i][j-1]][tr[i][j]];
			V[i][tr[i][j]].push_back(s);
		}
	}
}
int bul(int x,int a)
{
	int b,i;
	b=tr[x].size()-1;
	FOR(i,0,b-1)
		if(tr[x][i]==a)
			return tr[x][i+1];
	return 1000;
}
int solve()
{
	int asdf,i,j,k,s,x,y;
	hesapla();
	vector <int> :: iterator it;
	FOR(i,1,TREN)
		if(V[i][1].size())
			EKLE(1,i,(V[i][1][0]-1));
	while(!Q.empty())
	{
		BAK(x,y,s);
		if(visited[x][y]) continue;
		visited[x][y]=true;
		printf("x=%d y=%d s=%d\n",x,y,s); getchar();
		if(s>=T1 && s<=T2 && x==1) return s;
		asdf=bul(y,x);
		if(asdf!=1000) EKLE(asdf,y,(s));
		FOR(i,1,TREN)
		{
			asdf=V[i][x].size()-1;
			cout << asdf << endl;
			if(!visited[x][i])
			FOR(j,0,asdf)
				if(V[i][x].begin()>=V[y][x].begin())
				{
					printf("%d %d\n",x,i);
					EKLE(x,i,(s+abs(V[i][x].begin()-V[y][x].begin())));
					V[i][x].erase(V[i][x].begin());
				}
		}
	}
	return -1;
}
int main()
{
	read();
	cout << solve() << endl;
	system("PAUSE");
	return 0;
}
