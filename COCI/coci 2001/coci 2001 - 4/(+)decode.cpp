#include <iostream>
#define HARF(x) (char)(x+'A'-1)
using namespace std;
char A[1000];
bool hash[1000];
int bul(char c)
{
	for(int i=1; i<27; i++)
		if(A[i]==c)
			return i;
}
void solve()
{
	int i,k=0,K,s=0;
	char c='A';
	string str,str2;
	cin >> str;
	cin >> K;
	cin >> str2;
	for(i=K; s<str.size(); i++,s++)
	{
		A[i]=str[k++];
		hash[A[i]]=1;
		if(i==26) i=0;
	}
	for(k=0; k<26-str.size(); k++,i++)
	{
		if(!hash[c])
			A[i]=c;
		else { i--; k--; }
		c++;
		if(i==26) i=0;
	}
	for(i=0; i<str2.size(); i++)
		cout << HARF(bul(str2[i]));
	cout << endl;
}
int main()
{
	solve();
	return 0;
}
