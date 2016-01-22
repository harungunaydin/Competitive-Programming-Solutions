//SORU 457
//PROGRAM C++
#include<stdio.h>
#include<string.h>
FILE *in,*out;
int main()
{
	int N,i;
	in =  fopen("nptwo.in","r");
	out = fopen("nptwo.out","w");
	fscanf(in,"%d",&N);
	double res = 1;
	for(i=1; i<=N; i++,res/=2);
	char A[505];
	sprintf(A,"%.300lf",res);
	for(i = strlen(A) - 1; i ; i--)
		if(A[i] != '0')
			break;
	A[i+1] = '\0';
	if(A[i] == '.') A[i] = '\0';
	fprintf(out,"%s",A);
	return 0;
}
