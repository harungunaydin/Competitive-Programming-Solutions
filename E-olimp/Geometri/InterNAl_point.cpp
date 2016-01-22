#include <iostream>
#include <cmath>
#include <set>
#include <climits>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
#define f first
#define s second
using namespace std;
typedef pair <double,double> pdd;
set <pdd> st;
pdd p[MAXN+5];
int A[5];
double ccw(pdd a,pdd b,pdd c)
{
  return (b.f-a.f)*(c.s-a.s) - (b.s-a.s)*(c.f-a.f);
}
void solve()
{
  int K,N,i,j;
  double a,x,y;
  pdd p2;
  scanf("%d",&N);
  FOR(i,1,N)
  {
      scanf("%lf %lf",&x,&y);
      p[i] = make_pair(x,y);
      st.insert(p[i]);
  }
  p[N+1] = p[1];
  scanf("%d",&K);
  FOR(i,1,K)
  {
      scanf("%lf %lf",&x,&y);
      p2 = make_pair(x,y);
      if(st.find(p2) != st.end()) printf("BORDER\n");
      else
      {
          A[0] = A[1] = A[2] = 0;
          FOR(j,1,N)
          {
              a = ccw(p[j],p[j+1],p2);
              if(a < 0) A[2]++;
              else if(a > 0) A[1]++;
              else A[0]++;
              if(A[1] && A[2]) { printf("OUTSIDE\n"); A[1] = A[2] = 0; break;}
          }
          if(A[1] && (!A[0] && !A[2])) printf("INSIDE\n");
          else if(A[2] && (!A[0] && !A[1])) printf("INSIDE\n");
          else if(A[0]==1 && ( (A[1] && !A[2]) || (!A[1] && A[2]) )) printf("BORDER\n");
          if(A[1] && A[2]) printf("OUTSIDE\n");
      }
  }
}
int main()
{
  solve();
  system("PAUSE");
  return 0;
}
