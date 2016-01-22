#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int a[10],x[10];
void solve()
{
	int i,j;
	string str = "";
	FOR(i,1,9)
	{
		scanf("%d",a+i);
		a[i] = (a[i] == 12) ? 0 : (a[i] == 3) ? 3 : (a[i] == 6) ? 2 : 1;
	}
	FOR2(x[1],4)
		FOR2(x[2],4)
			FOR2(x[5],4)
			{
				x[4] = (a[1]-x[1]-x[2]+20)%4;
				x[3] = (a[2]-x[1]-x[2]-x[5]+20)%4;
				x[6] = (a[3]-x[2]-x[3]+20)%4;
				x[7] = (a[4]-x[1]-x[4]-x[5]+20)%4;
				x[9] = (a[5]-x[1]-x[3]-x[5]-x[7]+20)%4;
				x[8] = (a[7]-x[4]-x[7]+20)%4;
				if((x[3]+x[5]+x[6]+x[9])%4 == a[6] && (x[5]+x[7]+x[8]+x[9])%4 == a[8] && (x[6]+x[8]+x[9])%4 == a[9])
				{	
					FOR(i,1,9)
						FOR2(j,x[i])
						{
							str+=i+'0';
							str+=" ";
						}
					str.resize(str.size()-1);
					cout << str << endl;
					return;	
				}
			}
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
