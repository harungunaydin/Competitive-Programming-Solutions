#include <iostream>
#include <queue>
#define step(a,b,c,d) step[a][b][c][d]
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); visited[x][y] = vis; }
#define BAK(x,y,s)  { x = qx.front(); y = qy.front(); s = qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define KONTROL(x,y) (x>0 && x<=M && y>0 && y<=N && visited[x][y] < vis)
#define f first
#define s second
#define MAXN 50
using namespace std;
typedef pair <int,int> pii;
pii knight[MAXN*MAXN+5];
FILE *in,*out;
int K,M,N,sx,sy,vis;
int visited[MAXN+5][MAXN+5];
int yon[8][2] = { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };
int step[42][30][42][30];
void read()
{
	int i,j,s,x,y;
	char a;
	cin >> M >> N;
	cin >> a >> sx;
	sy = a - 'A' + 1;
	while(cin >> a >> s)
		knight[++K] = make_pair(s,a-'A'+1);
}
void BFS(int a,int b)
{
	vis++;
	queue <int> qx,qy,qs;
	int i,s,x,y;
	EKLE(a,b,0);
	while(!qx.empty())
	{
		BAK(x,y,s);
		step[x][y][a][b] = s;
		FOR2(i,8)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1],s+1);
	}
}
int Mdistance(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int coz(int a,int b)
{
	int a1,a2,i,j,res,top=0,x,y;
	FOR(i,1,K)
	{
		x = knight[i].f; y = knight[i].s;
		if(step(x,y,a,b) == -1) return 10000000;//ULASAMAMA DURUMU
		top+=step(x,y,a,b);
	}//BUTUN ATLARIN ASIL BULUSMA NOKTALARINA OLAN UZAKLIKLARINI BIR TOPLAMA AT
	res = top+Mdistance(sx,sy,a,b);
	FOR(a1,max(1,sx-1),min(M,sx+1))//TIMEDAN KISMAK ICIN BUTUN MATRISI DENEMIYORSUN..
		FOR(a2,max(1,sy-1),min(N,sy+1))//SADECE KRALIN USTUNDEKI KOORDINATLARI DENIYOSUN
		if(step(a1,a2,a,b)!=-1)
			FOR(j,1,K)//BIR BULUSMA NOKTASI DAHA BELIRLEYIP HERHANGI BIR ATLA SAHIN ORADA BULUSTUGUNU DUSUN...
			{
				x = knight[j].f; y = knight[j].s;//ATIN YERLERI
				if(step(x,y,a1,a2) != -1)//ULASABILIYOSA
					res = min(res,top-step(x,y,a,b)+step(x,y,a1,a2)+step(a1,a2,a,b)+Mdistance(sx,sy,a1,a2));
				/*TOPLAMDAN ATIN ASIL BULUSMA NOKTASINA OLAN UZAKLIGINI CIKAR 
					ATIN ARA BULUSMA NOKTASINA UZAKLIGINI EKLE
					ARA BULUSMADAN SONRA KINGLE ATI ASIL BULUSMA NOKTASINA GONDER VE SAHIN ARA BULUSMA NOKTASINA GIDIS 
					MALIYETINI EKLE
					Mdistance(MANHATTAN DISTANCE) GRIDTEKI UZAKLIK ANLAMINA GELIYOR VE SAH SADECE 4 YONE GIDEBILIYOR GALIBA
				*/
			}
	return res;
}
int solve()
{
	int i,j,k,l,res=1000000;
	FOR(i,1,M)
		FOR(j,1,N)
			FOR(k,1,M)
				FOR(l,1,N)
					step[i][j][k][l] = -1;//-INFLEMEK
	FOR(i,1,M)
		FOR(j,1,N)
			BFS(i,j);//STEP(A,B,C,D) = STEP[A][B][C][D] = A'ya B'den C'ye D'ye olan at uzaklýðý
	FOR(i,1,M)
		FOR(j,1,N)
			res = min(res,coz(i,j));//BUTUN BULUSMA NOKTALARINI DENE 
	return res == 1000000 ? 0 : res;//GAYET BARÝZ
}
int main()
{
	read();
	printf("%d\n",solve());//THE END
	return 0;
}
