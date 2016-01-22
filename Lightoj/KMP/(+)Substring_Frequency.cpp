#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1000001
using namespace std;
int M,N;
int F[MAXN];
char text[MAXN],str[MAXN];
void pre_KMP()
{
	int i(0),j(-1);
	F[i] = j;
	while(text[i])
	{
		while(j >= 0 && str[i] != str[j]) j = F[j];
		i++; j++;
		F[i] = j;
	}
}
int KMP()
{
	scanf("%s",text);
	scanf("%s",str);

	pre_KMP();

	int i(0),j(0),res(0);
	
	while(text[i])
	{
		while(j >= 0 && text[i] != str[j]) j = F[j];
		i++; j++;
		if(!str[j]) res++;
	}
	return res;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
		printf("Case %d: %d\n" , i , KMP() );
	return 0;
}
