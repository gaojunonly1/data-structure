#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
inline ll read()
{
    ll s=0; bool f=0; char ch=' ';
    while(!isdigit(ch)) {f|=(ch=='-'); ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
    return (f)?(-s):(s);
}
#define R(x) x=read()
inline void write(ll x)
{
    if(x<0) {putchar('-'); x=-x;}
    if(x<10) {putchar(x+'0'); return;}
    write(x/10); putchar((x%10)+'0');
}
#define W(x) write(x),putchar(' ')
#define Wl(x) write(x),putchar('\n')
int main() {
	int n1,m1,t1,n2,m2,t2;
	int i;
	R(n1);
	R(m1);
	R(t1);
	map<pii,int>A;
	for(i=0;i<t1;i++) {
		int x,y,z;
		R(x);
		R(y);
		R(z);
		A[mp(x,y)]=z;
	}
	R(n2);
	R(m2);
	R(t2);
	if(n1!=n2||m1!=m2) {
		cout<<"Illegal!";
		return 0;
	}
	map<pii,int>B;
	for(i=0;i<t2;i++) {
		int x,y,z;
		R(x);
		R(y);
		R(z);
		B[mp(x,y)]=z;
		if(0==A.count(mp(x,y)))
			A[mp(x,y)]=-z;
		else {
			A[mp(x,y)]-=z;
			if(0==A[mp(x,y)])
				A.erase(mp(x,y));
		}
	}
	W(n1);
	W(m1);
	Wl((size_t)A.size());
	for(auto oo:A) {
		W(oo.fi.fi);
		W(oo.fi.se);
		Wl(oo.se);
	}
    return 0;
}
