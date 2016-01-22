#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define hash(x) { H[x+32] = H[x] = H[x-32] = true; }
using namespace std;
char H[3000];
int kontrol(string str)
{
	int a,i,t = -1;
	a = str.size();
	while(t < a)
	{
		if(t && !H[str[t+1]]) return t+1;
		FOR(i,t+1,str.size()-1)
			if(str[i] == ' ')
				break;
		t = i;
	}
	FOR2(i,str.size())
		if(!H[str[i]] && str[i] != ' ')
			return i;
	return -1;
}
void solve()
{
	string str;
	int N,i,j,index,t;
	char c;
	bool flag;
	cin >> N;
	getline(cin,str);
	FOR(i,1,N)
	{
		flag = true;
		getline(cin,str);
		index = kontrol(str);
		if(index != -1)
		{
			hash(str[index]);
			for(j = 0; j < str.size() ; j++)
				if(j == index)
					printf("[%c]",str[j]);
				else
					printf("%c",str[j]);
			printf("\n");
		}
		else
			cout << str << endl;
	}
}
int main()
{
	solve();
	return 0;
}
