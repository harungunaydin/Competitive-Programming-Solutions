#include <iostream>
#include <map>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
vector <int> V;
map <int,bool> mp;
int res;
class Node
{
	public:
		int x;
		Node *sag,*sol;
};
Node *head;
void add(int x)
{
	Node *temp= new Node,*temp2 = new Node;
	temp2->x = x; temp2->sag = temp2->sol = NULL;
	if(!head) { head = temp2; return; }
	temp = head;
	Node *ata = NULL;
	while(temp)
	{
		ata = temp;
		temp = (temp->x < x) ? temp->sag : temp->sol;
	}
	if(ata->x < x) ata->sag = temp2;
	else ata->sol = temp2;
}
void yardir(Node *temp,int d)
{
	res = max(res,d);
	if(!temp) return;
	yardir(temp->sol,d+1);
	yardir(temp->sag,d+1);
}
void solve()
{
	int a;
	while(1)
	{
		scanf("%d",&a);
		if(!a) break;
		if(!mp[a])
		{
			V.push_back(a);
			mp[a] = true;
		}
	}
	vector <int> :: iterator it;
	for(it = V.begin(); it!=V.end(); ++it)
		add(*it);
	yardir(head,0);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
