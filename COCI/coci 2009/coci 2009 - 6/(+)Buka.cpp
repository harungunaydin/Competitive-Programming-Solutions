#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
class Big
{
	public:
		int size;
		int A[MAXN+5];
		Big() { size = 0; for(int i=0; i<1000; i++) A[i] = 0; }
		void read(string str)
		{
			size = str.size();
			for(int i=0; i<size; i++)
				A[i] = str[size-i-1]-'0';
		}
		Big operator +(Big B)
		{
			Big res;
			int c(0),i;
			for(i=0; i < size || i < B.size || c; i++)
			{
				c+=A[i] + B.A[i];
				res.A[i] = c%10;
				c/=10;
			}
			res.size = i;
			return res;
		}
		void print()
		{
			for(int i=size-1; i>=0; i--)
				printf("%d",A[i]);
			printf("\n");
		}
};
void solve()
{
	string res,str,str2;
	int c(0),i;
	char a;
	cin >> str;
	cin >> a;
	cin >> str2;
	if(a == '*')
		cout << str + str2.substr(1) << endl;
	else
	{
		Big A,B;
		A.read(str); B.read(str2);
		(A+B).print();
	}
}
int main()
{
	solve();
	return 0;
}
