//SORU 232
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "friday.in"
#define OUTPUT "friday.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
int A[10],ay[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_leap(int x)
{
	if(x%4) return 0;
	if(!(x%100) && x%400) return 0;
	return 1;
}
void solve()
{
	int a,b=0,c,i,j,k;
	in >> N;
	FOR(i,1900,1900+N-1)
	{
		c = is_leap(i);
		FOR(j,1,12)
		{
			a = ay[j];
			if(j == 2 && c) a++;
			FOR(k,1,a)
			{
				b++;
				if(k == 13)
					A[b]++;
				if(b == 7) b=0;
			}
		}
	}
	out << A[6] << " " << A[7] << " " << A[1] << " " << A[2] << " " << A[3] << " " << A[4] << " " << A[5] << endl;
}
int main()
{
	solve();
	return 0;
}
