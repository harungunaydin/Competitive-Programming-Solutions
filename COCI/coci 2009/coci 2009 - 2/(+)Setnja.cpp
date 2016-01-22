#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100000
using namespace std;
class Big
{
	public:
		int size;
		int A[8015];
		Big() { size = 0; A[0] = 0; }
		inline void init(string str)
		{
			register int i;
			size = str.size();
			FOR2(i,size)
				A[i] = str[size-i-1]-'0';
		}
		inline Big operator + (Big B)
		{
			Big res;
			register int c=0,i;
			for(i=0; i<size || i<B.size || c; i++)
			{
				if(i<size && i<B.size) c+=A[i] + B.A[i];
				else if(i<size) c+=A[i];
				else if(i<B.size) c+=B.A[i];
				res.A[i] = c%10;
				c/=10;
			}
			res.size = i;
			return res;
		}
		inline Big operator *(int a)
		{
			Big res;
			register int c=0,i;
			for(i=0; i<size || c; i++)
			{
				if(i<size) c+=A[i]*a;
				res.A[i] = c%10;
				c/=10;
			}
			res.size = i;
			return res;
		}
		void print()
		{
			int i;
			TFOR(i,size-1,0)
				printf("%d",A[i]);
			printf("\n");
		}
};
void solve()
{
	Big bir,R,k;
	register int a,i;
	char A[10005];
	scanf("%s",A);
	a = strlen(A);
	R.init("1");
	k = R;
	bir = R;
	FOR2(i,a)
	{
		if(A[i] == 'R') R = R + R + k;
		else if(A[i] == 'L') R = R + R;
		else if(A[i] == '*') { R = R*5 + k; k = k * 3; }
	}
	R.print();
}
int main()
{
	solve();
	return 0;
}
