#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(str,yol) { qstr.push(str); qyol.push(yol); A[str[0]][str[1]][str[2]][str[3]][str[4]][str[5]][str[6]] = true; }
#define BAK(str,yol) { str = qstr.front(); yol = qyol.front(); qstr.pop(); qyol.pop(); }
#define all(x) x.begin(),x.end()
using namespace std;
queue <string> qstr,qyol;
bool A[9][9][9][9][9][9][9];
void print(string str)
{
	printf("%d\n",str.size());
	for(int i=0; i<str.size(); i++)
		printf("%c",str[i]);
	printf("\n");
	exit(0);
}
void solve()
{
	string hedef,str,temp,yol;
	int i;
	char a,b;
	FOR2(i,8)
	{
		cin >> a;
		a-='1';
		hedef+=a;
		str+=i;
	}
	EKLE(str,"");
	while(!qstr.empty())
	{
		BAK(str,yol);
		if(str == hedef) print(yol);
		temp = str;
		reverse(all(str));
		if(!A[str[0]][str[1]][str[2]][str[3]][str[4]][str[5]][str[6]])
			EKLE(str,(yol+"A"));
		reverse(all(str));
		a = str[3];
		b = str[4];
		for(i=3; i>0; i--)
		{
			str[i] = str[i-1];
			str[7-i] = str[8-i];
		}
		str[0] = a;
		str[7] = b;
		if(!A[str[0]][str[1]][str[2]][str[3]][str[4]][str[5]][str[6]])
			EKLE(str,(yol+"B"));
		
		str = temp;
		
		a = str[1];
		str[1] = str[6]; str[6] = str[5]; str[5] = str[2]; str[2] = a;
		if(!A[str[0]][str[1]][str[2]][str[3]][str[4]][str[5]][str[6]])
			EKLE(str,(yol+"C"));
	}
}
int main()
{
	solve();
	return 0;
}
