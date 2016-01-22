#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
string str,temp;
string B[15] = {"0134","012","1245","036","13457","258","3467","678","4578"};
int K[] = {1,2,3,0};
int comb[100];
void print2(string str)
{
	int i;
	FOR2(i,str.size())
		printf("%c ",str[i]+'0');
	cout << endl;
}
void print()
{
	int i,j;
	string str;
	str.clear();
	FOR2(i,9)
		FOR2(j,comb[i])
			str+=char(i+1)+'0';
	FOR2(i,str.size())
	{
		printf("%c",str[i]);
		if(i!=str.size()-1)
			printf(" ");
	}
	printf("\n");
	exit(0);
}
bool control()
{
	int i,j,k;
	FOR2(i,10)
		FOR2(j,comb[i])
			FOR2(k,B[i].size())
				str[B[i][k]-'0'] = K[str[B[i][k]-'0']];
	FOR2(i,str.size())
		if(str[i])
			return 0;
	return 1;
}
void solve(int x)
{
	int i;
	if(x == 9)
	{ 
			temp = str;
			if(control())
				print();
			str = temp;
			return;
	}
	FOR2(i,4)
	{
		comb[x] = i;
		solve(x+1);
	}
}
int main()
{
	int a,i;
	FOR2(i,9)
	{
		cin >> a;
		str+=(a == 12) ? '0' : (a == 3) ? '1' : (a == 6) ? '2' : '3';
		str[i]-='0';
	}
	solve(0);
	return 0;
}

