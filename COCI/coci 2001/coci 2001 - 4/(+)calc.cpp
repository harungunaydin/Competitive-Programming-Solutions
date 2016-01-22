#include <iostream>
#include <fstream>
#define yaz printf
//#define cin in
using namespace std;
ifstream in("calc.in");
int s;
char abc;
string str;
void generate(char c)
{
	if(c=='A')
	{
		yaz("SWAP\n");
		yaz("DUP\nDUP\n");
		yaz("ROT\nROT\nROT\n");
		yaz("DROP\nSWAP\n");
	}
	if(c=='B')
	{
		yaz("DUP\nDUP\n");
		yaz("ROT\nROT\nROT\n");
		yaz("DROP\n");
	}
}
void OS(char c)
{
	yaz("ROT\nROT\n");
	(c=='#')? cout << "HASH": cout << "DOLLAR";
	yaz("\nDUP\n");
	yaz("ROT\nROT\nROT\n");
	yaz("DROP\n");
}
/*int yerbul(int x)
{
	int i,s1=0,s2=0;
	for(i=x; ; i++)
	{
		if(str[i]=='(') s1++;
		else if(str[i]==')') s2++;
		if(s1==s2) { abc=str[i+1]; return i+1; }
	}
}*/
void solve()
{
		if(str[s]==')') { s++; return; }
		if(str[s]=='(')
		{
			s++;
			solve();
			int op=s;
			s++;
			solve();
			OS(str[op]);
			s++;
		}
		if(str[s]=='A') { s++; generate('A'); }
		else if(str[s]=='B') { s++; generate('B'); }
}
int main()
{
	cin >> str;
	solve();
	yaz("DROP\nDROP\n");
	//system("PAUSE");
	return 0;
}

