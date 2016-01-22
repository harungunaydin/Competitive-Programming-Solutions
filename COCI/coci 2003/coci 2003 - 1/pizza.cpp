#include <iostream>
#include <fstream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
//#define cin in
using namespace std;
ifstream in("pizza.in");
int M,N,K,R,maxi;
bool hash[10005];
class bisi
{
	public:
		int x,y,s,no;
		int C[100];
		bisi() { x=y=s=no=0; for(int i=0; i<10; C[i++]=0);}
		void add(int x) { C[++no]=x; }
}A[10005],p[10005];
int B[100005],comb[100005];
int mini=10000000;
double uzaklik(int x1,int y1,int x2,int y2)
{
	/*int a=abs(x2-x1),b=abs(y2-y1);
	a*=a;
	b*=b;*/
	return sqrt(abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1));
}
void read()
{
	int i;
	cin >> K >> R;
	cin >> M;
	FOR(i,1,M)
	{
		cin >> p[i].x >> p[i].y;
		p[i].x+=1000;
		p[i].y+=1000;
	}
	cin >> N;
	FOR(i,1,N)
	{
		cin >> A[i].x >> A[i].y >> A[i].s;
		A[i].x+=1000;
		A[i].y+=1000;
	}
}
void yazdir();
void dene()
{
	int i,j,s=0;
	int hash2[100005];
	FOR(i,1,N) hash2[i]=0;
	for(i=1; i<=K; i++)
		FOR(j,1,p[comb[i]].no)
		{
		//	cout << p[comb[i]].C[j] << " ";
			if(!hash2[p[comb[i]].C[j]])
				s+=A[p[comb[i]].C[j]].s;
			hash2[p[comb[i]].C[j]]=true;
			//cout << "s=" << s << endl;
		}
/*	cout << s << endl;
	yazdir();
	cout << "\n\n";*/
	maxi=max(maxi,s);
}
void yazdir()
{
	int i;
	FOR(i,1,K)
		cout << comb[i] << " ";
	getchar(); cout << endl;
}
void izracunaj(int x)
{
	if(x==K+1)
	{
		dene();
		return;
	}
	int i;
	FOR(i,comb[x-1]+1,M)
		if(!hash[i])
		{
			comb[x]=i;
			hash[i]=true;
			izracunaj(x+1);
			hash[i]=false;
		}
}
void solve()
{
	int i,j,top;
	double a;
	FOR(i,1,M)
	{
		top=0;
		FOR(j,1,N)
			if(uzaklik(p[i].x,p[i].y,A[j].x,A[j].y)<=R)
				p[i].add(j);
		B[i]=top;
	}
	izracunaj(1);
	cout << maxi << endl;
}
int main()
{
	read();
	solve();
	//system("PAUSE");
	return 0;
}
