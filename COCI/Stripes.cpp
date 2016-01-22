#include <cstdio>
#include <iostream>

using namespace std;

int A,B,C,K;
int asd;

int dn[1111];

int won(int k){
		
		if(k==A || k==B || k==C) return 1;

			if(dn[k]) return dn[k];
				
				if((k>=A && won(k-A)==2) || (k>=B && won(k-B)==2) || (k>=C && won(k-C)==2))
							return dn[k]=1;
						
					return dn[k]=2;
}
int main()
{
		cin >> A >> B >> C >> K ;
			while(K--){
						
						scanf(" %d",&asd);
								
								printf("%d\n",won(asd));
									}				
	return 0;
}
