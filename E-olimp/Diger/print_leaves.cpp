#include <iostream>
#include <map>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 20000000
using namespace std;
map <int,bool> mp;
vector <int> V;
int s;
int res[MAXN+5];
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
void yardir(Node *temp)
{
	if(!temp->sag && !temp->sol) { res[++s] = temp->x; return; }
	if(temp->sol != NULL) yardir(temp->sol);
	if(temp->sag != NULL) yardir(temp->sag);
}
void solve()
{
	int a,i;
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
	if(!head) return;
	yardir(head);
	if(!s) return;
	FOR(i,1,s-1)
		printf("%d ",res[i]);
	printf("%d",res[s]);
}
int main()
{
	solve();
	printf("\n");
	return 0;
}
