#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
string str,str2;
int a,b;
void find()
{
	cin >> str >> str2;
	FOR2(a,str.size())	
		FOR2(b,str2.size())
			if(str[a] == str2[b])
				return;
}
int main()
{
	find();
	int i,j;
	for(i=0; i<str2.size(); i++,printf("\n"))
		FOR2(j,str.size())
			if(i == b) 
				printf("%c",str[j]);
			else if(j == a)
				printf("%c",str2[i]);
			else
				printf(".");
	return 0;
}
