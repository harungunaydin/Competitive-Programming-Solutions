/*
ID : harung91
PROG: prime3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,n) for(i=a; i>=b; i--)
#define FORN(i,a,b,c) for(i=a; i<=b; i+=c)
#define MAXN 100000
#define control(a,b,c,d,e,f) (f<0 || f>9 || prime[a*10000+b*1000+c*100+d*10+e])
using namespace std;
FILE *in,*out;
set <string> st;
int top;
int A[15];
int M[15][15];
bool prime[MAXN+5];
void asallar()
{
	int i,j;
	prime[1] = true;
	for(i=2; i<MAXN; i++)
		if(!prime[i])
			for(j=i+i; j<MAXN; j+=i)
				prime[j] = true;
}
int a1,a2,a3,a4,a5,a6,a7,a8,a9,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,c1,c2,c3,c4,i,s=0;
void ekle()
{
	string str;
	int i,j;
	str.clear();
	str+=a1+'0'; str+=b1+'0'; str+=b2+'0'; str+=b3+'0'; str+=a6+'0';
	str+=b7+'0'; str+=a2+'0'; str+=c3+'0'; str+=a7+'0'; str+=b10+'0';
	str+=b9+'0'; str+=c1+'0'; str+=a3+'0'; str+=c2+'0'; str+=b12+'0';
	str+=b8+'0'; str+=a9+'0'; str+=c4+'0'; str+=a4+'0'; str+=b11+'0';
	str+=a8+'0'; str+=b4+'0'; str+=b5+'0'; str+=b6+'0'; str+=a5+'0';
	st.insert(str);
}
void solve()
{
	asallar();
	in = fopen("prime3.in","r");
	fscanf(in,"%d %d",&top,&a1);
	FOR2(a2,10)FOR2(a4,10)FORN(a5,1,9,2)
	{
		a3 = top-a1-a2-a4-a5;
		if(control(a1,a2,a3,a4,a5,a3)) continue;
		
		FORN(a6,1,9,2)FOR2(a7,10)FORN(a8,1,9,2)
		{
			a9 = top-a8-a3-a7-a6;
			if(control(a8,a9,a3,a7,a6,a9)) continue;
			
			FOR(b1,1,9)FOR(b3,1,9)
			{
				b2 = top-a1-b1-b3-a6;
				if(!b2 || control(a1,b1,b2,b3,a6,b2)) continue;
				FORN(b4,1,9,2)FORN(b6,1,9,2)
				{
					b5 = top-a8-b4-b6-a5;
					if(!(b5&1) || control(a8,b4,b5,b6,a5,b5)) continue;
					c1 = top-b1-a2-a9-b4;
					if(control(b1,a2,c1,a9,b4,c1)) continue;
					
					c2 = top-b3-a7-a4-b6;
					if(control(b3,a7,c2,a4,b6,c2)) continue;
					
					FOR(b7,1,9)FOR(b8,1,9)
					{
						b9 = top-a1-b7-b8-a8;
						if(!b9 || control(a1,b7,b9,b8,a8,b9)) continue;
						b12 = top-b9-c1-a3-c2;
						if(!(b12&1) || control(b9,c1,a3,c2,b12,b12)) continue;
						FORN(b10,1,9,2)
						{
							b11 = top-a6-b10-b12-a5;
							if(control(a6,b10,b12,b11,a5,b11)) continue;
							c3 = top-b7-a2-a7-b10;
							if(control(b7,a2,c3,a7,b10,c3)) continue;
							c4 = top-b8-a9-a4-b11;
							if(control(b8,a9,c4,a4,b11,c4)) continue;
							if(b2+c3+a3+c4+b5!=top ||  control(b2,c3,a3,c4,b5,1)) continue;
							if(b9+c1+a3+c2+b12!=top || control(b9,c1,a3,c2,b12,1)) continue;
							ekle();
						}
					}
				}
			}
		}
	}
	out = fopen("prime3.out","w");
	set <string> :: iterator it;
	for(it = st.begin(); it!=st.end(); ++it,s=0)
	{
		if(it!=st.begin()) fprintf(out,"\n");
		FOR2(i,it->size())
		{
			fprintf(out,"%c",(*it)[i]);
			if(++s == 5) { s = 0; fprintf(out,"\n"); }
		}
	}
}
int main()
{
	solve();
	return 0;
}
