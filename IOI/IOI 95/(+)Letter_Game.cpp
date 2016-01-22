#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 40000
using namespace std;
ifstream in("words.txt");
string cozum[MAXN+5],words[MAXN+5];
int N,cozum_sayisi,maxi;
int V[35] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
short B[130],C[130];
bool cmp(string a,string b)
{
	return a.size() < b.size();
}
void read()
{
	int i,j,k,res=0,s;
	string str,temp;
	cin >> str;
	FOR2(i,str.size())
		C[str[i]]++;
	while(1)
	{
		in >> temp;
		if(temp == ".") break;
		fill(B,B+130,0);
		FOR2(i,temp.size())
			if(++B[temp[i]] > C[temp[i]])
				break;
		if(i == temp.size())
			words[++N]  = temp;
	}
	words[++N] = "";
}
void solve()
{
	int i,j,k,s;
	string str;
	FOR(i,1,N)
		FOR(j,i+1,N)
		{
			fill(B,B+130,0);
			str = words[i] + " " + words[j];
			FOR2(k,str.size())	B[str[k]]++;
			FOR(k,'a','z') if(B[k] > C[k]) break;
			if(k != 'z'+1) continue;
			s = 0;
			FOR2(k,str.size()) s+=V[str[k]-'a'];
			if(s > maxi)
			{
				cozum_sayisi = 0;
				maxi = s;
			}
			if(s == maxi)
				cozum[cozum_sayisi++] = str; 
		}
	printf("%d\n",maxi);
	FOR2(i,cozum_sayisi)
	{
		while(cozum[i][cozum[i].size()-1] == ' ' && i>=0) cozum[i].resize(cozum[i].size()-1);
		cout << cozum[i] << endl;
	}
}
int main()
{
	read();
	solve();
	return 0;
}
