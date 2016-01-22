#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cctype>
using namespace std;
int main()
{
	srand(time(NULL));
	if(rand()%2)
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
