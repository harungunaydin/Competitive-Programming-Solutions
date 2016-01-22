#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#define isNum(a) ((a)>='0' && (a)<='9')
#define kare(a) ((a)*(a))
using namespace std;
string s;
int n,i,j,a,dik,yan;
int main()
{
	getline(cin,s);
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]=='n' || s[i]=='e' || s[i]=='w' || s[i]=='s')
		{
			string temp="";
			j=i+1;
			while(isNum(s[j])) { temp+=s[j++]; }
			if(temp.size()==1)
			{
				a=temp[0]-'0';
			}
			else if(temp.size())
			{
				a=(temp[0]-'0')*10+(temp[1]-'0');
			}
			switch(s[i])
			{
				case 'n' : dik+=a; break;
				case 'e' : yan+=a; break;
				case 's' : dik-=a; break;
				case 'w' : yan-=a; break;
			}
		}
	}
	printf("%.2lf\n",sqrt(kare(dik)+kare(yan)));
	return 0;
}
