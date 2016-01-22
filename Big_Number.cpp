#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1005
#define all(x) x.begin(),x.end()
using namespace std;
class Big : vector < int > 
{
	public:
		
		Big() { this->clear(); }
		Big(string str) { set2(str); }
		inline int get(int k) { return (k >= size()) ? 0 : (*this)[k]; }
		inline void set(int k,int v) { if(k >= size()) resize(k+1); (*this)[k] = v; }
		void set2(string str)
		{
			int i,size = str.size();
			if(str == "0") return;
			for(i = 0; i < size; i++)
				set(i,str[size - i - 1] - '0');
		}
		bool operator < ( Big B )
		{
			if(size() < B.size()) return 1;
			if(size() > B.size()) return 0;
			for(int i = size() - 1; i >= 0; i--)
				if(get(i) < B.get(i))
					return 1;
				else if(get(i) > B.get(i))
					return 0;
			return 0;
		}
		bool operator <= ( Big B ) { return (*this) < B || (*this == B); }
		bool operator >= ( Big B ) { return !(*this < B); }
		bool operator >  ( Big B ) { return !(*this <= B); }
		bool operator != ( Big B ) { return !( (*this) == B ); }
		bool operator == ( Big B )
		{
			if(size() != B.size()) return 0;
			for(int i = 0; i < size(); i++)
				if(get(i) != B.get(i))
					return 0;
			return 1;
		}
		void read()
		{
			string str;
			cin >> str;
			set2(str);
		}
		void print()
		{
			if(empty()) printf("0");
			vector < int > :: reverse_iterator it;
			for(it = rbegin(); it != rend(); ++it)
				printf("%d",*it);
			printf("\n");
		}
		void hallet()
		{
			while( !empty() && !get(size()-1) ) resize(size()-1);
		}
		Big operator + (int a)
		{
			string str = "";
			while(a)
			{
				str += a + '0';
				a /= 10;
			}
			reverse(all(str));
			Big tmp(str);

			return (*this) + tmp;
		}
		Big operator - (int a)
		{
			string str = "";
			while(a)
			{
				str += a + '0';
				a /= 10;
			}
			reverse(all(str));
			Big tmp(str);
			return (*this) - tmp;
		}
		Big operator + (Big B)
		{
			Big res;
			int i,c(0);
			for(i = 0; i < size() || i < B.size() || c; i++)
			{
				c += get(i) + B.get(i);
				res.set(i,c%10);
				c /= 10;
			}
			return res;
		}
		Big operator - (Big B)
		{
			if(B > (*this)) return B - (*this);
			Big res;
			int c(0),i,t;
			for(i = 0; i < size() || i < B.size(); i++)
			{
				t = get(i) - B.get(i) + c;
				if(t < 0) { t += 10; c = -1; }
				else c = 0;
				res.set(i,t);
			}
			res.hallet();
			return res;
		}
		Big operator * (Big B)
		{
			Big res;
			int c(0),i,j;
			for(i = 0; i < size() || c; i++)
				for(j = 0; j < B.size() || c; j++)
				{
					c += res.get(i+j) + get(i) * B.get(j);
					res.set(i+j,c%10);
					c /= 10;
				}
			return res;
		}
		Big ikiyebol()
		{
			Big res;
			int c(0),i,t;
			for(i = size() - 1; i >= 0; i--)
			{
				t = get(i);
				res.set(i,t/2 + c);
				c = 5 * (t&1);
			}
			res.hallet();
			return res;
		}
		Big BS(Big A,Big B,Big bas,Big son)
		{
			if(bas == son) return bas;
			if(bas + 1 == son) return son;
			Big orta = ( bas + son ).ikiyebol();
			Big tmp = B * orta;
			if(tmp == A) return orta;
			if(tmp > A) return BS( A , B , bas , orta - 1);
			if(tmp < A) return BS( A , B , orta , son );
		}
		Big operator / (Big B)
		{
			Big bir("1");
			Big res = BS( *this , B , bir , *this );
			if(res * B > (*this)) res = res - 1;
			return res;
		}
		Big operator % (Big B)
		{
			if((*this) < B) return *this;
			Big res = (*this) / B;
			return res = (*this) - ( B * res );
		}
		bool empty2() { return empty(); }
		bool clear2() { clear(); }

}A[MAXN];
Big GCD( Big A , Big B )
{
	if(B.empty2()) return A;
	return gcd( B , A%B );
}
Big LCM( Big A , Big B )
{
	return ( A * B ) / GCD(A,B);
}
