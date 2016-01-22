#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int F[105][105][105];
int x1,x2,y1,y2,z1,z2;
void update_z(int x,int y,int k)
{
	register int z;
	for(z = z1; z <= 100; z += z&-z)
		F[x][y][z] += k;
	for(z = z2 + 1; z <= 100; z += z&-z)
		F[x][y][z] -= k;
}
void update_y(int x,int k)
{
	register int y;
	for(y = y1; y <= 100; y += y&-y)
		update_z(x,y,k);
	for(y = y2 + 1; y <= 100; y += y&-y)
		update_z(x,y,-k);
}
void update()
{
	register int x;
	for(x = x1; x <= 100; x += x&-x)
		update_y(x,1);
	for(x = x2 + 1; x <= 100; x += x&-x)
		update_y(x,-1);
}
bool find()
{
	register int s(0),x,y,z;
	for(x = x1; x; x -= x&-x)
		for(y = y1; y; y -= y&-y)
			for(z = z1; z; z -= z&-z)
				s += F[x][y][z];
	return !s;
}
void solve()
{
	register int M,N,i,res(0),t;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
	{
		scanf("%d %d %d %d %d %d",&x1,&x2,&y1,&y2,&z1,&z2);
		x1++; y1++; z1++; x2++; y2++; z2++;
		update();
	}
	FOR(i,1,N)
	{
		scanf("%d %d %d %d",&x1,&y1,&z1,&t);
		x1++; y1++; z1++;
		if(find()) res += t;
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
