#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define pb push_back
using namespace std;
int small[150],big[150],sml,bg,S[150],B[150],i,j,a,b,c,d,e,f,g,h,uc=3;
char ch;
int main()
{
	for(i=1;i<=12;i++) small[i]=big[i]=1;
	while(uc--)
	{
		scanf("%d %d %d %d %c %d %d %d %d",&a,&b,&c,&d,&ch,&e,&f,&g,&h);
		if(ch=='=')
		{
			small[a]=small[b]=small[c]=small[d]=small[e]=small[f]=small[g]=small[h]=0;
			big[a]=big[b]=big[c]=big[d]=big[e]=big[f]=big[g]=big[h]=0;
		}
		else if(ch=='<')
		{
			vector < int > v;
			if(small[a]) v.pb(a);
			if(small[b]) v.pb(b);
			if(small[c]) v.pb(c);
			if(small[d]) v.pb(d);

			memset(small , 0 , sizeof(small));
	
			for(i=0;i<v.size();i++)
				small[v[i]]=1;
	
			v.resize(0);
	
			if(big[e]) v.pb(e);
			if(big[f]) v.pb(f);
			if(big[g]) v.pb(g);
			if(big[h]) v.pb(h);

			memset(big, 0 , sizeof(big));
	
			for(i=0;i<v.size();i++)
				big[v[i]]=1;
	
			v.resize(0);
	
		}
		else
		{
			vector < int > v;
			if(big[a]) v.pb(a);
			if(big[b]) v.pb(b);
			if(big[c]) v.pb(c);
			if(big[d]) v.pb(d);
	
			memset(big , 0 , sizeof(big));
	
			for(i=0;i<v.size();i++)
				big[v[i]]=1;
	
			v.resize(0);
	
			if(small[e]) v.pb(e);
			if(small[f]) v.pb(f);
			if(small[g]) v.pb(g);
			if(small[h]) v.pb(h);

			memset(small , 0 , sizeof(small));

			for(i=0;i<v.size();i++)
				small[v[i]]=1;
		}
	}
	int w=0;
	for(i=1;i<=12;i++)
		w+=small[i]+big[i];
	if(!w) cout << "impossible\n";
	else if(w>1) cout << "indefinite\n";
	else
	{
		for(i=1;i<=12;i++)
		{
			if(small[i])
			{
				cout << i << "-\n";
				return 0;
			}
			if(big[i])
			{
				cout << i << "+\n";
				return 0;
			}
		}

	}
	return 0;
}
