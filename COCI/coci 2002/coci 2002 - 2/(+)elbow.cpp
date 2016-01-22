#include <iostream>
using namespace std;
int result[1005];
bool visited[155][155][305];
string str,str2,str3;
void izracunaj(int x,int y,int z)
{
	if(visited[x][y][z]) return;
	if(z==str3.size())
	{
		for(int i=0; i<z; i++)
			cout << result[i];
		cout << endl;
		exit(0);
	}
	if(str[x]==str3[z])
	{
		result[z]=1;
		izracunaj(x+1,y,z+1);
	}
	if(str2[y]==str3[z])
	{
		result[z]=2;
		izracunaj(x,y+1,z+1);
	}
	visited[x][y][z]=true;
}
int main()
{
	cin >> str >> str2 >> str3;
	izracunaj(0,0,0);
	return 0;
}
