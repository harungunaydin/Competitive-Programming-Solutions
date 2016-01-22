#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<map>
#define mbp make_pair
#define add(a,s) q.push(mbp(-(a),s));
using namespace std;
priority_queue< pair < int  , string > > q;
map < string , int > mep,mp;
inline int solve()
{
	string s;
	register int a,i;
	while(q.empty()==0)
	{
		a=-q.top().first;
		s=q.top().second;
		q.pop();
		if(mp[s])
		{
			return a;
		}
		for(i=0;i<11;i++)
		if(s[i]=='X')
		break;
		if(i)
		{
			string temp=s;
			swap(temp[i],temp[i-1]);
			if(mep[temp]>a+1 or !mep[temp])
			{
				add(a+1,temp);
				mep[temp]=a+1;
			}
		}
		if(i>1)
		{
			string temp=s;
			swap(temp[i],temp[i-2]);
			if(mep[temp]>a+1 or !mep[temp])
			{	
				add(a+1,temp);
				mep[temp]=a+1;
			}
		}
		if(i>2)
		{
			string temp=s;
			swap(temp[i],temp[i-3]);
			if(mep[temp]>a+2 or !mep[temp])
			{	
				add(a+2,temp);
				mep[temp]=a+2;
			}
		}
		if(i<10)
		{
			string temp=s;
			swap(temp[i],temp[i+1]);
			if(mep[temp]>a+1 or !mep[temp])
			{
				add(a+1,temp);
				mep[temp]=a+1;
			}
		}
		if(i<9)
		{
			string temp=s;
			swap(temp[i],temp[i+2]);
			if(mep[temp]>a+1 or !mep[temp])
			{
				add(a+1,temp);
				mep[temp]=a+1;
			}
		}
		if(i<8)
		{
			string temp=s;
			swap(temp[i],temp[i+3]);
			if(mep[temp]>a+2 or !mep[temp])
			{
				add(a+2,temp);
				mep[temp]=a+2;
			}
		}
	}
}
int main()
{
	mp["BBBXBBSSSSS"]=mp["BBXBBBSSSSS"]=mp["BXBBBBSSSSS"]=mp["XBBBBBSSSSS"]=mp["BBBBXBSSSSS"]=mp["BBBBBXSSSSS"]=mp["BBBBBSXSSSS"]=mp["BBBBBSSXSSS"]=mp["BBBBBSSSXSS"]=mp["BBBBBSSSSXS"]=mp["BBBBBSSSSSX"]=1;
	string str;
	cin >> str;
	add(0,str);
	cout << solve() << endl;
	return 0;
}
