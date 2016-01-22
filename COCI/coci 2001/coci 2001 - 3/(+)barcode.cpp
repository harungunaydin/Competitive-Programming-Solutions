#include <iostream>
using namespace std;
int N,s=0;
char A[105][105];
char kontrol(int k)
{
	for(int i=0; i<5; i++)
		if(A[i][k]=='.')
			return '.';
		else if(A[i][k]=='X')
			return 'X';
	s++;
	return '?';
}
void read()
{
	cin >> N;
	for(int i=0; i<5; i++)
		for(int j=0; j<N; j++)
			cin >> A[i][j];
}
string solve()
{
	if(N==1) return "0";
	int i=0,temporary;
	string str,temp;
	str.clear();
	for(; i<N; i++)
		str+=kontrol(i);
	if(str.find('?')!=-1)
		while(1)
		{
			temporary=s;
			for(i=0; i<N; i++)
				if(str[i]=='?')
						if(i<N-2 && str[i+1]=='.' && str[i+2]=='.')
							str[i]='X',s--;
						else if(i<N-2 && str[i+1]=='X' && str[i+2]=='X')
							str[i]='.',s--;
						else if(i>1 && str[i-1]=='.' && str[i-2]=='.')
							str[i]='X',s--;
						else if(i>1 && str[i-1]=='X' && str[i-2]=='X')
							str[i]='.',s--;
						else if(i && i<N-1 && str[i-1]=='X' && str[i+1]=='X')
							str[i]='.',s--;
						else if(i && i<N-1 && str[i-1]=='.' && str[i+1]=='.')
							str[i]='X',s--;
			if(!s) break;
			if(s==temporary) return "UNDETERMINABLE";
		}
	temp.clear();
	for(i=0; i<N; i++)
		if(i<N-1 && str[i]==str[i+1]) { i++; temp+='1'; }
		else temp+=str[i];
	for(i=0; i<N; i++)
		if(temp[i]=='X' || temp[i]=='.')
			temp[i]='0';
	return temp;
}
int main()
{
	read();
	cout << solve() << endl;
	return 0;
}
