#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 300000
using namespace std;
int M,N;
char str[MAXN+5],text[MAXN+5];
class stack
{
	public:
		int bas;
		char A[MAXN+5];
		stack() { bas = 0; for(int i = 0; i < MAXN+2 ; i++) A[i] = 0; }
		inline void ekle(char c) { A[++bas] = c; }
		inline char top()  { return A[bas]; }
		bool control(bool k)
		{
			int i,j;
			i = bas;
			if(k)
			{
				j = 0;
				while(i>=0 && j<M && A[i] == str[j]) { i--; j++; }
				return j == M;
			}
			else
			{
				j = M-1;
				while(i>=0 && j>=0 && A[i] == str[j]) { i--; j--; }
				return j == -1;
			}
		}
};
stack sag,sol;
void solve()
{
	int i(0),j(N-1);
	sag.bas = sol.bas = 0;
	while(i < j)
	{
		while(i < j && !sol.control(0)) { sol.ekle(text[i]); i++; }
		if(i < j) sol.bas-=M;
		while(i <= j && !sag.control(1)) { sag.ekle(text[j]); j--; }
		if(i < j) sag.bas-=M;
	}
	while(sag.bas)
	{
		sol.ekle(sag.top());
		while(sol.control(0)) sol.bas-=M;
		sag.bas--;
	}
	string str = "";
	FOR(i,1,sol.bas)
		printf("%c",sol.A[i]);
	printf("\n");
}
int main()
{
	scanf("%s",str);
	scanf("%s",text);
	M = strlen(str);
	N = strlen(text);
	solve();
	return 0;
}
