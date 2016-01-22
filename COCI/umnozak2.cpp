#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define cont(t) { if(t > B) break; if(t >= A) res++; }
using namespace std;
long long unsigned A,B,res(0);
inline void solve()
{
	register long long unsigned a,b,c,d,e,f,g,h,i,j,t;
	register long long unsigned a1,b1,c1,d1,e1,f1,g1,h1,i1,j1;
	scanf("%lld %lld",&A,&B);
	FOR(a,1,9)
	{
		t = a*a;
		cont(t)
		FOR(b,1,9)
		{
			t = (a*10+b)*a*b;
			cont(t)
			FOR(c,1,9)
			{
				t = (a*100+b*10+c)*a*b*c;
				cont(t)
				FOR(d,1,9)
				{
					t = (a*1000+b*100+c*10+d)*a*b*c*d;
					cont(t)
					FOR(e,1,9)
					{
						t = (a*10000+b*1000+c*100+d*10+e)*a*b*c*d*e;
						cont(t)
						FOR(f,1,9)
						{
							t = (a*100000+b*10000+c*1000+d*100+e*10+f)*a*b*c*d*e*f;
							cont(t)
							FOR(g,1,9)
							{
								t = (a*1000000+b*100000+c*10000+d*1000+e*100+f*10+g)*a*b*c*d*e*f*g;
								cont(t)
								FOR(h,1,9)
								{
									t = (a*10000000+b*1000000+c*100000+d*10000+e*1000+f*100+g*10+h)*a*b*c*d*e*f*g*h;
									cont(t);
									FOR(i,1,9)
									{
										t = (a*100000000+b*10000000+c*1000000+d*100000+e*10000+f*1000+g*100+h*10+i)*a*b*c*d*e*f*g*h*i;
										cont(t);
										FOR(j,1,9)
										{
											t = (a*1000000000+b*100000000+c*10000000+d*1000000+e*100000+f*10000+g*1000+h*100+i*10+j)*a*b*c*d*e*f*g*h*i*j;
											cont(t)
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
