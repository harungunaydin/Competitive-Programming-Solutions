#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
char harf[10]={'A','E','I','O','U','a','e','i','o','u'};
string str[10000];
bool kontrol(string str,string str2)
{
	if(str.size()!=str2.size()) return 0;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]>'Z')
			str[i]-=32;
		if(str2[i]>'Z')
			str2[i]-=32;
		if(str[i]!=str2[i])
			return 0;
	}
	return 1;
}
int find2(string str)
{
	for(int i=str.size()-1; i+1; i--)
		for(int j=0; j<10; j++)
			if(str[i]==harf[j] || str[i-1]==' ' || !i)
				return i;
	return 0;
}
string bul(string str,string str2,string str3,string str4)
{
	string a,b,c,d;
	a=str.substr(find2(str));
	b=str2.substr(find2(str2));
	c=str3.substr(find2(str3));
	d=str4.substr(find2(str4));
	if(kontrol(a,b)) return (kontrol(b,c))? "perfect" : "even";
	if(kontrol(a,c)) return "cross";
	return (kontrol(a,d) && kontrol(b,c))? "shell" : "free";
}
void solve()
{
	int i,N,k;
	char c;
	string temp;
	cin >> N;
	N*=4;
	getline(cin,temp);
	for(i=1; i<=N; i++)
		getline(cin,str[i]);
	for(i=1; i<=N; i+=4)
	cout << bul(str[i],str[i+1],str[i+2],str[i+3]) << endl;
}
int main()
{
	solve();
	return 0;
}
