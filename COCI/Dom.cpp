#include<cstdio>
#include<cstring>
char S[150];
int n;
bool H[150];
int main()
{
	H['C']=H['A']=H['M']=H['B']=H['R']=H['I']=H['D']=H['G']=H['E']=1;
	scanf("%s",S);
	register int i,j;
	n=strlen(S);
	for(i=0;i<n;i++)
	{
		if(!H[S[i]])
		printf("%c",S[i]);
	}
	return 0;
}
