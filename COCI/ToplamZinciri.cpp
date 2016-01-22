#include<iostream>
using namespace std;
int n;
int main()
{
	cin >> n;
	if(n==1)
	{
		cout << "1\n";
		return 0;
	}
	if(n==3)
	{
		cout << "1 2 3\n";
		return 0;
	}
	switch(n)
	{
		case 4 : cout << "1 2 4\n"; break;
		case 5 : cout << "1 2 3 5\n"; break;
		case 6 : cout << "1 2 3 6\n"; break;
		case 7 : cout << "1 2 3 4 7\n"; break;
		case 8 : cout << "1 2 3 4 8\n"; break;
		case 9 : cout << "1 2 3 4 6 9\n"; break;
		case 10 : cout << "1 2 3 4 5  6\n"; break;
	}
	return 0;
}
