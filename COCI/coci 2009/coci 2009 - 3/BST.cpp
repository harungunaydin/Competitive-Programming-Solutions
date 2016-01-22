#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 300000
using namespace std;
class Node
{
	public:
		int x;
		Node *left,*right;
};
long long res;
int mostright_level,mostleft_level,maxi,mini(MAXN+5);
class BST
{
	public :
		Node *mostright,*mostleft,*root;
		BST() { root = mostright = mostleft = NULL; }
		inline void add(int data)
		{
			register Node *temp = new Node,*temp2,*t3;
			temp -> right = temp -> left = NULL;
			temp->x = data;
			if(!root) { mostright = mostleft = root = temp; return; }
			temp2 = root;
			if(data == maxi)
			{
				mostright_level++;
				res+=mostright_level;
				mostright -> right = temp;
				mostright = mostright -> right;
				return;
			}
			if(data == mini)
			{
				mostleft_level++;
				res+=mostleft_level;
				mostleft -> left = temp;
				mostleft = mostleft -> left;
				return;
			}
			while(1)
			{
				res++;
				if(data > temp2->x)
				{
					t3 = temp2 -> right;
					if(!t3) { temp2 -> right = temp; return; }
					temp2 = t3;
				}
				else
				{
					t3 = temp2 -> left;
					if(!t3) { temp2 -> left = temp; return; }
					temp2 = t3;
				}
			}
		}
};
void solve()
{
	BST sogut;
	register int N,i,x;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&x);
		maxi = max(maxi,x);
		mini = min(mini,x);
		sogut.add(x);
		printf("%lld\n",res);
	}
}
int main()
{
	solve();
	return 0;
}
