#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define cont(t) { if(t > B) break; if(t >= A) res++; }
using namespace std;
long long unsigned A,B,res(0);
long long unsigned us10[15];
inline void solve()
{
	register long long unsigned a,b,c,d,e,f,g,h,i,j,t;
	register long long unsigned b1,b2,b3,b4,b5,b6,b7,b8;
	register long long unsigned c1,c2,c3,c4,c5,c6,c7,c8;
	scanf("%lld %lld",&A,&B);
	us10[0] = 1;
	FOR(a,1,12) us10[a] = us10[a-1]*10;
	FOR(a,1,9)
	{
		t = a*a;
		cont(t)
		FOR(b,1,9)
		{
			b1 = a*b;
			t = (a*10+b)*b1;
			cont(t)
			if(t + us10[8] <= A) break;
			c1 = a*100+b*10;
			FOR(c,1,9)
			{
				b2 = b1*c;
				t = (c1+c)*b2;
				cont(t)
				if(t + us10[7] <= A) break;
				c2 = (c1+c)*10;
				FOR(d,1,9)
				{
					b3 = b2*d;
					t = (c2+d)*b3;
					cont(t)
					if(t + us10[6] <= A) break;
					c3 = (c2+d)*10;
					FOR(e,1,9)
					{
						b4 = b3*e;
						t = (c3+e)*b4;
						cont(t)
						if(t + us10[5] <= A) break;
						c4 = (c3+e)*10;
						FOR(f,1,9)
						{
							b5 = b4*f;
							t = (c4+f)*b5;
							cont(t)
							if(t + us10[4] <= A) break;
							c5 = (c4+f)*10;
							FOR(g,1,9)
							{
								b6 = b5*g;
								t = (c5+g)*b6;
								cont(t)
								if(t + us10[3] <= A) break;
								c6 = (c5+g)*10;
								FOR(h,1,9)
								{
									b7 = b6*h;
									t = (c6+h)*b7;
									cont(t)
									if(t + us10[2]  <= A) break;
									c7 = (c6+h)*10;
									FOR(i,1,9)
									{
										b8 = b7*i;
										t = (c7+i)*b8;
										cont(t)
										c8 = (c7+i)*10;
										FOR(j,1,9)
										{
											t = (c8+j)*b8*j;
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
