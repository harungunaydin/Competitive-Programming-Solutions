#include<iostream>
#include<cstdio>
#include<string>
#define kare(a) ((a)*(a))
using namespace std;
string s,temp;
int sa=3;
bool tarih,yazar,kontrol;
int main()
{
	while(sa--)
	{
		yazar=tarih=kontrol=0;
		temp=s="";
		cin >> s;
		temp+=s[2];
		temp+=s[3];
		if(temp=="01" || temp== "03" || temp== "05" || temp== "07" || temp== "08" || temp== "10" || temp=="12")
		{
			int b=(s[1]-'0')+(s[0]-'0')*10;
			if(b>=1 && b<=31)
				tarih=true;
		}
		else if(temp=="02")
		{
			int a=(s[4]-'0')*100+(s[5]-'0')*10+(s[6]-'0'),b=(s[1]-'0')+(s[0]-'0')*10;
			if(b>=1 && b<=28+( (a%4==0 && a%100) || (a%400==0)))
				tarih=true;
			}
		else if(temp=="04" || temp=="06" || temp=="09" || temp=="11")
		{
			int b=(s[1]-'0')+(s[0]-'0')*10;
			if(b>=1 && b<=30)
				tarih=true;
		}
		if(s[7]=='1' || s[7]=='6' || s[7]=='9')
			yazar=true;
		if( (kare(s[0]-'0')+kare(s[1]-'0')+kare(s[2]-'0')+kare(s[3]-'0')+kare(s[4]-'0')+kare(s[5]-'0')+kare(s[6]-'0')+kare(s[7]-'0') )% 7 == (s[8]-'0'))
			kontrol=true;
		cout << (yazar+tarih+kontrol==3) << endl;
	}
	return 0;
}
