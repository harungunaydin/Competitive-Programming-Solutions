//SORU 325
//PROGRAM C
#include <stdio.h>
FILE *in,*out;
int main()
{
	int N;
    in=fopen("power.in","r");
    out=fopen("power.out","w");
    fscanf(in,"%d",&N);
    fprintf(out,"%d",1<<N);
    return 0;
}
