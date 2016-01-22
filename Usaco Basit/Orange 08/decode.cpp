//SORU 379
//PROGRAM C++
#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "decode.in"
#define OUTPUT "decode.out"
using namespace std;
FILE *in,*out;
char A[100005];
void solve()
{
	string str,temp;
	char temp2[100000];
	int i;
	char c='a';
	in = fopen(INPUT,"r");
	out = fopen(OUTPUT,"w");
	FOR(i,'a','z')
	{
		fscanf(in,"%c",&c);
		A[i] = c;
		A[i-32] = c-32;
	}
	if(c == 'a') return;
	A[' '] = ' ';
	str.clear(); temp.clear();
	while(fscanf(in,"%s",temp2) != -1)
	{
		temp = temp2;
		str = str + " " + temp;
	}
	FOR(i,1,str.size()-1)
		fprintf(out,"%c",A[str[i]]);
}
int main()
{
	solve();
	return 0;
}
