#include <iostream>
#include <vector>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int i,M,N,sayi;
int boyandi[20005],renk[20005];
vector <int> V[20005],yol[20005];
void read()
{
		  scanf("%d %d",&N,&M);
		  int i,j,s,x,y;
		  for(i=1; i<=M; i++)
		  {
					scanf("%d",&s);
					y=0;
					FOR(j,1,s)
					{
							  scanf("%d",&x);
							  V[x].push_back(i);
							  if(y) { yol[x].push_back(y); yol[y].push_back(x); }
							  y=x;
					}
		  }
}
void solve(int x)
{
		  bool kontrol[2005]={0};
		  int i;
		  if(boyandi[x]) return;
		  boyandi[x]=true;
		  vector <int> :: iterator it;
		  for(it=V[x].begin(); it!=V[x].end(); ++it)
					 kontrol[renk[*it]]=true;
		  for(it=V[x].begin(); it!=V[x].end(); ++it)
					 if(!renk[*it])
					 {
								i=1;
								while(kontrol[i]) i++;
								sayi=max(sayi,i);
								renk[*it]=i;
								kontrol[i]=true;
					 }
		  for(it=yol[x].begin(); it!=yol[x].end(); ++it)
					 if(!boyandi[*it])
								solve(*it);
}
int main()
{
		  read();
		  int i;
		  FOR(i,1,N)
					 if(!boyandi[i])
								solve(i);
		  cout << sayi << endl;
		  for(i=1; i<=M; i++)
					 printf("%d ",renk[i]);
		printf("\n");
		  return 0;
}
