#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 2000
using namespace std;
string mini;
string S[10];
int N,X;
int F[MAXN+5];
void pre_KMP(string str)
{
	int i(0),j(-1);
	F[i] = j;
	while(i < str.size())
	{
		while(j >= 0 && str[i] != str[j]) j = F[j];
		i++; j++;
		F[i] = j;
	}
}
bool KMP(string text,string str)
{
	pre_KMP(str);
	int i(0),j(0);
	while(i < text.size())
	{
		while(j >= 0 && text[i] != str[j]) j = F[j];
		i++; j++;
		if(j == str.size()) return 1;
	}
	return 0;
}
bool kontrol(string str)
{
	int i;
	FOR(i,1,N)
		if(i != X && !KMP(S[i],str))
			return 0;
	return 1;
}
bool control(int x)
{
	string str = mini.substr(0,x);
	for(int i = x; i < mini.size(); i++)
	{
		if(kontrol(str))
			return 1;
		str+=mini[i];
		str.erase(str.begin());
	}
	return kontrol(str);
}
int BS(int bas,int son)
{
	int orta = (bas + son)/2;
	if(bas == son) return control(bas) ? bas : 0;
	if(bas + 1 == son) return control(son) ? son : control(bas) ? bas : 0;
	return control(orta) ? BS(orta,son) : BS(bas,orta-1);
}
void solve()
{
	int i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> S[i];
		if(S[i].size() < mini.size() || mini.empty())
		{ mini = S[i]; X = i; }
	}
	printf("%d\n" , BS(0,mini.size()) );
}
int main()
{
	solve();
	return 0;
}
