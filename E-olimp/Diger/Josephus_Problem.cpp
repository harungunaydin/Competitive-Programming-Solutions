#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1500
using namespace std;
bool A[MAXN+5];
void solve()
{
  int M,N,i,s=0,k=0;
  scanf("%d %d",&N,&M);
  for(i=1; i<=N; i++)
  {
      if(!A[i] && ++k == M)
      {
          k = 0;
          A[i] = true;
          if(++s == N) break;
      }
      if(i == N) i = 0;
  }
  printf("%d\n",i);
}
int main()
{
  solve();
  return 0;
}
