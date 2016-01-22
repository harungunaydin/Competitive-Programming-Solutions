//SORU 324
//PROGRAM C++
#include<stdio.h>
#include<string.h>
FILE *in,*out;
int main()
{
	int N,i;
	in =  fopen("neg.in","r");
	out = fopen("neg.out","w");
	fscanf(in,"%d",&N);
	double res = 1;
	for(i=1; i<=N; i++,res/=2);
	char A[1005];
	sprintf(A,"%.999lf",res);
	for(i = strlen(A) - 1; i ; i--)
		if(A[i] != '0')
			break;
	A[i+1] = '\0';
	if(A[i] == '.') A[i] = '\0';
	fprintf(out,"%s",A);
	return 0;
}
