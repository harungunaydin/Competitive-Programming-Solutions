#include <iostream>
#include <list>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define mp(a,b,c) make_pair(make_pair(a,b),c)
#define f first
#define s second
using namespace std;
typedef pair <int,int> ii;
list < pair < ii,string > > liste;
list < pair < ii,string > > :: iterator it,it2;
map <string,int> mp;
int hesapla(string str)
{
	int i,k=1,s=0;
	for(i=str.size()-3; i>=0; i--,k*=10)
		s+=(str[i]-'0')*k;
	return s;
}
void solve()
{
	
	liste.insert(liste.begin(),mp(0,0,""));
	liste.insert(liste.end(),mp(100001,100001,""));
	int N,a,i,k;
	char ccc[50];
	string str;
	scanf("%d",&N);
	pair < ii,string > temp;
	FOR(i,1,N)
	{
		scanf("%s",&ccc);
		str=ccc;
		if(str[4]=='=') // --- >>> EKLEME
		{
			temp.s=str.substr(0,4);
			if(mp[temp.s])
				for(it=liste.begin(); it!=liste.end(); ++it)
					if(it->s==temp.s)
					{
						it->s="";
						break;
					}
			it2=liste.begin();
			it2++;
			a=hesapla(str.substr(12));
			for(it=liste.begin(); it2!=liste.end(); ++it,++it2)
				if(it2->f.f-it->f.s>a)
				{
					liste.insert(it2,mp(it->f.s+1,it->f.s+a,temp.s));
					break;
				}
			mp[temp.s]=true;
		}
		else if(str[0]=='p')// --- >>> YAZDIRMA
		{
			bool flg=1;
			str=str.substr(6,4);
			if(mp[str])
				for(it=liste.begin(); it!=liste.end(); ++it)
					if(it->s==str)
					{
						printf("%d\n",it->f.f);
						flg=0;
						break;
					}
			if(flg)	printf("0\n");
		}
		else// --- >>> SILME
		{
			str=str.substr(5,4);
			if(mp[str])
				for(it=liste.begin(); it!=liste.end(); ++it)
						if(it->s==str)
						{
							liste.erase(it);
							break;
						}
			mp[str]=0;
		}
	}
}
int main()
{
	solve();
	return 0;
}
