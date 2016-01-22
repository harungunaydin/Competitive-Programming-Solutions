#include <iostream>
#define to_minute_from_hour(str) ( ((str[0]-'0')*10+str[1]-'0')*60+(str[3]-'0')*10+str[4]-'0')
using namespace std;
int a,b,c,d,s1,s2;
bool hash[2005][2005],hash2[2005][2005],hash3[2005][2005],hash4[2005][2005];
void print(int x)
{
	x%=7;
	switch(x)
	{
		case 1 : printf("Sunday");    break;
		case 2 : printf("Monday");    break;
		case 3 : printf("Tuesday");   break;
		case 4 : printf("Wednesday"); break;
		case 5 : printf("Thursday");  break;
		case 6 : printf("Friday");    break;
		case 0 : printf("Saturday");  break;
	}
	printf("\n");
}
void print2(int f)
{
	if(f/60<10) printf("0");
	printf("%d:",f/60);
	if(!((f%60)/10)) printf("0");
	printf("%d\n",f%60);
}
int solve()
{
	int d=0;	
	string str;
	cin >> str;
	a=to_minute_from_hour(str);
	cin >> str;
	b=to_minute_from_hour(str);
	cin >> str;
	c=to_minute_from_hour(str);
	cin >> str;
	d=to_minute_from_hour(str);
	while(1)
	{
		if(a+c>=1440)
		{
			s1++;
			a+=c-1440;
		}
		else
			a+=c;
		if(b+d>=1440)
		{
			s2++;
			b+=d-1440;
		}
		else
			b+=d;
		if(hash3[a][s1%7] && hash4[b][s2%7]) { printf("Never\n"); exit(0); }
		hash3[a][s1%7]=hash4[b][s2%7]=true;
		hash[a][s1]=hash2[b][s2]=true;
		if(hash[b][s2]) return 2;
		if(hash2[a][s1]) return 1;
	}
}
int main()
{
	int k=solve();
	if(k==1)
	{
		print(s1);
		print2(a);
	}
	else
	{
		print(s2);
		print2(b);
	}
	return 0;
}
