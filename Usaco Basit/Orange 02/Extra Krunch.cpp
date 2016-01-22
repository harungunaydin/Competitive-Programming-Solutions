//SORU 336
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INPUT "krunch.in"
#define OUTPUT "krunch.out"
#define IS_VOWEL(x) (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[100000];
bool hash[300],hash2[300];
void solve()
{
	int i;
	string str,temp="";
	getline(in,str);
	FOR2(i,str.size())
	{
		if(hash[str[i]] || IS_VOWEL(str[i])) continue;
		temp+=str[i];
		A[i] = str[i];
		if(str[i] != ' ' && str[i] != ',' && str[i] != '.')
			hash[str[i]] = true;
	}
	while(temp[temp.size()-1] == ' ') temp.resize(temp.size()-1);
	i = temp.find('.')-1;
	if(i != -2)
		while(temp[i] == ' ') { hash2[i] = true; i--; }
	FOR2(i,temp.size())
	{
		if(temp[i] == ' ')
			while(temp[i+1] == ' ') i++;
			if(!hash2[i])
		out << temp[i];
	}
}
int main()
{
	solve();
	return 0;
}
