#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N,soru;
string str;
string new_world_order[1005];
void rec()
{
	cout << str << endl; getchar();
	if(!soru) { cout << str << endl; getchar(); getchar(); exit(0); }
	int a,i,j,k=0,temp2;
	string temp;
	for(j=0; j < N; j++)
	{
		for(i=0; i < str.size(); i++)
		{
			if(str[i] == new_world_order[j][k] || str[i] == '?') k++;
			else k=0;
			if(k == new_world_order[i].size())
			{
				cout << i << endl; getchar();
				temp=str;
				temp2=soru;
				a=0;
				for(j=i-k; j<=i; j++)
					{
					if(str[j] == '?') soru--;
					str[j] = new_world_order[i][a++];
				}
				rec();
				soru=temp2;
				str=temp;
				k=0;
			}
	}
}
void solve()
{
	int i;
	scanf("%d %d",&M,&N);
	char c[123];
	scanf("%s",c);
	str=c;
	for(i=0; i < str.size(); i++)
		if(str[i] == '?')
			soru++;
	FOR(i,1,N)
	{
		scanf("%s",c);
		new_world_order[i]=c;
	}
	rec();
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
