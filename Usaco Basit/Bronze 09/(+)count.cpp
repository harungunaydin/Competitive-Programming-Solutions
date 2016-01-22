//SORU 503
//PROGRAM C
#include <stdio.h>
FILE *in,*out;
int N,K;
void read()
{
     in=fopen("count.in","r");
     out=fopen("count.out","w");
     fscanf(in,"%d %d",&N,&K);
}
int control(int n)
{
    while(n)
    {
            if(n%10==K)
            return 0;
            n/=10;
    }
    return 1;
}
void solve()
{
     int i=1,s=0;
     for(; s<N; i++)
           if(control(i))
                         s++;
     fprintf(out,"%d",i-1);
}
int main()
{
    read();
    solve();
    return 0;
}
