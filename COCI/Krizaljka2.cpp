#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
string Str="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",Temp="";
char S[6][5],Mat[10][10];
int y[6]={0,1,2,3,4,5};
bool yerlestir(int yer,int str)
{
	register int i,j,k=0;
	switch(yer)
	{
		case 0: for(i=1;i<=3;i++) if(Mat[1][i]==S[str][k] || Mat[1][i]=='@') Mat[1][i]=S[str][k++]; else return 0; break;
		case 1: for(i=1;i<=3;i++) if(Mat[2][i]==S[str][k] || Mat[2][i]=='@') Mat[2][i]=S[str][k++]; else return 0; break;
		case 2: for(i=1;i<=3;i++) if(Mat[3][i]==S[str][k] || Mat[3][i]=='@') Mat[3][i]=S[str][k++]; else return 0; break;
		case 3: for(i=1;i<=3;i++) if(Mat[i][1]==S[str][k] || Mat[i][1]=='@') Mat[i][1]=S[str][k++]; else return 0; break;
		case 4: for(i=1;i<=3;i++) if(Mat[i][2]==S[str][k] || Mat[i][2]=='@') Mat[i][2]=S[str][k++]; else return 0; break;
		case 5: for(i=1;i<=3;i++) if(Mat[i][3]==S[str][k] || Mat[i][3]=='@') Mat[i][3]=S[str][k++]; else return 0; break;
	}
	return 1;
}
void yazdir()
{
	register int i,j;
	Temp="";
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			Temp+=Mat[i][j];
}
bool solve(int a,int b,int c,int d,int e,int f)
{
	if(!yerlestir(a,0)) return 0;
	if(!yerlestir(b,1)) return 0;
	if(!yerlestir(c,2)) return 0;
	if(!yerlestir(d,3)) return 0;
	if(!yerlestir(e,4)) return 0;
	if(!yerlestir(f,5)) return 0;
	return 1;
}
int main()
{
	register int i,w=0;
	for(i=0;i<6;i++)
	scanf("%s",S[i]);
	do
	{
		if(solve(y[0],y[1],y[2],y[3],y[4],y[5]))
		{
			yazdir();
			if(Temp<Str)
				Str=Temp;
			w=1;
		}
		memset(Mat,'@',sizeof(Mat));
	}while(next_permutation(y,y+6));
	if(w) { for(i=0;i<=8;i++) { cout << Str[i]; if(i%3==2) printf("\n"); } }
	else
	printf("0\n");
	return 0;
}
